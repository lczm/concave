#include "graphics.h"

Graphics::Graphics()
{
    direct3d = NULL;
    device3d = NULL;
    fullscreen = false;
    width = GAME_WIDTH;    // width & height are replaced in initialize()
    height = GAME_HEIGHT;
	backColor = SETCOLOR_ARGB(255, 124, 183, 248);
}

Graphics::~Graphics()
{
    releaseAll();
}

void Graphics::releaseAll()
{
    SAFE_RELEASE(device3d);
    SAFE_RELEASE(direct3d);
}

void Graphics::initialize(HWND hw, int w, int h, bool full)
{
    hwnd = hw;
    width = w;
    height = h;
    fullscreen = full;

    //initialize Direct3D
    direct3d = Direct3DCreate9(D3D_SDK_VERSION);
    if (direct3d == NULL)
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing Direct3D"));

    initD3Dpp();        // init D3D presentation parameters
    if (fullscreen)      // if full-screen mode
    {
        if (isAdapterCompatible())   // is the adapter compatible
            // set the refresh rate with a compatible one
            d3dpp.FullScreen_RefreshRateInHz = pMode.RefreshRate;
        else
            throw(GameError(gameErrorNS::FATAL_ERROR,
                "The graphics device does not support the specified resolution and/or format."));
    }

    // determine if graphics card supports harware texturing and lighting and vertex shaders
    D3DCAPS9 caps;
    DWORD behavior;
    result = direct3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
    // If device doesn't support HW T&L or doesn't support 1.1 vertex 
    // shaders in hardware, then switch to software vertex processing.
    if ((caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == 0 ||
        caps.VertexShaderVersion < D3DVS_VERSION(1, 1))
        behavior = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  // use software only processing
    else
        behavior = D3DCREATE_HARDWARE_VERTEXPROCESSING;  // use hardware only processing

    //create Direct3D device
    result = direct3d->CreateDevice(
        D3DADAPTER_DEFAULT,
        D3DDEVTYPE_HAL,
        hwnd,
        behavior,
        &d3dpp,
        &device3d);

    if (FAILED(result))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error creating Direct3D device"));

    result = D3DXCreateSprite(device3d, &sprite);

    if (FAILED(result))
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error creating Direct3D sprite"));

}

void Graphics::initD3Dpp()
{
    try {
        ZeroMemory(&d3dpp, sizeof(d3dpp));              // fill the structure with 0
        // fill in the parameters we need
        d3dpp.BackBufferWidth = width;
        d3dpp.BackBufferHeight = height;
        if (fullscreen)                                  // if fullscreen
            d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;  // 24 bit color
        else
            d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;   // use desktop setting
        d3dpp.BackBufferCount = 1;
        d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
        d3dpp.hDeviceWindow = hwnd;
        d3dpp.Windowed = (!fullscreen);
        d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
    }
    catch (...)
    {
        throw(GameError(gameErrorNS::FATAL_ERROR,
            "Error initializing D3D presentation parameters"));

    }
}

HRESULT Graphics::showBackbuffer()
{
    result = E_FAIL;    // default to fail, replace on success
    // Display backbuffer to screen
    result = device3d->Present(NULL, NULL, NULL, NULL);
    return result;
}

bool Graphics::isAdapterCompatible()
{
    UINT modes = direct3d->GetAdapterModeCount(D3DADAPTER_DEFAULT,
        d3dpp.BackBufferFormat);
    for (UINT i = 0; i < modes; i++)
    {
        result = direct3d->EnumAdapterModes(D3DADAPTER_DEFAULT,
            d3dpp.BackBufferFormat,
            i, &pMode);
        if (pMode.Height == d3dpp.BackBufferHeight &&
            pMode.Width == d3dpp.BackBufferWidth &&
            pMode.RefreshRate >= d3dpp.FullScreen_RefreshRateInHz)
            return true;
    }
    return false;
}

HRESULT Graphics::getDeviceState()
{
    result = E_FAIL;    // default to fail, replace on success
    if (device3d == NULL)
        return  result;
    result = device3d->TestCooperativeLevel();
    return result;
}

HRESULT Graphics::reset()
{
    result = E_FAIL;    // default to fail, replace on success
    initD3Dpp();                        // init D3D presentation parameters
    result = device3d->Reset(&d3dpp);   // attempt to reset graphics device
    return result;
}

HRESULT Graphics::loadTexture(const char* filename, COLOR_ARGB transcolor,
    UINT& width, UINT& height, LP_TEXTURE& texture)
{
    // The struct for reading file info
    D3DXIMAGE_INFO info;
    result = E_FAIL;

    try {
        if (filename == NULL)
        {
            texture = NULL;
            return D3DERR_INVALIDCALL;
        }

        // Get the width and height from file
        result = D3DXGetImageInfoFromFile(filename, &info);
        if (result != D3D_OK)
            return result;

        width = info.Width;
        height = info.Height;

        // Create the new texture by loading from file
        result = D3DXCreateTextureFromFileEx(
            device3d,                   // 3D device
            filename,                   // image filename
            info.Width,                 // texture width
            info.Height,                // texture heihgt
            1,                          // mip-map levels (1 for no chain)
            0,                          // usage
            D3DFMT_UNKNOWN,             // surface format (default)
            D3DPOOL_DEFAULT,            // memory class for the texture
            D3DX_DEFAULT,               // image filter
            D3DX_DEFAULT,               // mip filter
            transcolor,                 // color key for transparency
            &info,                      // bitmap file info (from loaded file)
            NULL,                       // color palette
            &texture);                  // destination texture

    }
    catch (...)
    {
        throw(GameError(gameErrorNS::FATAL_ERROR, "Error in Graphics::loadTexture"));
    }

    return result;
}

// draw the primitive
bool Graphics::drawQuad(LP_VERTEXBUFFER vertexBuffer)
{
	HRESULT result = E_FAIL;    // standard Windows return value

	if (vertexBuffer == NULL)
		return false;

	device3d->SetStreamSource(0, vertexBuffer, 0, sizeof(VertexC));
	device3d->SetFVF(D3DFVF_VERTEX);
	result = device3d->DrawPrimitive(D3DPT_TRIANGLEFAN, 0, 2);			// draw the primitive as a triangle fan

	if (FAILED(result))
		return false;

	return true;
}

// creating the vertex buffer
HRESULT Graphics::createVertexBuffer(VertexC verts[], UINT size, LP_VERTEXBUFFER& vertexBuffer)
{
	HRESULT result = E_FAIL;

	// Create a vertex buffer
	result = device3d->CreateVertexBuffer(size, D3DUSAGE_WRITEONLY, D3DFVF_VERTEX,
		D3DPOOL_DEFAULT, &vertexBuffer, NULL);
	if (FAILED(result))
		return result;

	void* ptr;
	// must lock buffer before data can be transferred in
	result = vertexBuffer->Lock(0, size, (void**)& ptr, 0);
	if (FAILED(result))
		return result;
	memcpy(ptr, verts, size);   // copy vertex data into buffer
	vertexBuffer->Unlock();     // unlock buffer

	return result;
}

HRESULT Graphics::loadTextureSystemMem(const char* filename, COLOR_ARGB transcolor,
	UINT& width, UINT& height, LP_TEXTURE& texture)
{
	// The struct for reading bitmap file info
	D3DXIMAGE_INFO info;
	result = E_FAIL;        // Standard Windows return value

	try {
		if (filename == NULL)
		{
			texture = NULL;
			return D3DERR_INVALIDCALL;
		}

		// Get width and height from bitmap file
		result = D3DXGetImageInfoFromFile(filename, &info);
		if (result != D3D_OK)
			return result;
		width = info.Width;
		height = info.Height;

		// Create the new texture by loading a bitmap image file
		result = D3DXCreateTextureFromFileEx(
			device3d,           //3D device
			filename,           //bitmap filename
			info.Width,         //bitmap image width
			info.Height,        //bitmap image height
			1,                  //mip-map levels (1 for no chain)
			0,                  //usage
			D3DFMT_UNKNOWN,     //surface format (default)
			D3DPOOL_SYSTEMMEM,  //systemmem is lockable
			D3DX_DEFAULT,       //image filter
			D3DX_DEFAULT,       //mip filter
			transcolor,         //color key for transparency
			&info,              //bitmap file info (from loaded file)
			NULL,               //color palette
			&texture);         //destination texture

	}
	catch (...)
	{
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error in Graphics::loadTexture"));
	}
	return result;
}

//void Graphics::drawSprite(const SpriteData& spriteData, COLOR_ARGB color)
//{
//	if (spriteData.texture == NULL) return;
//
//	D3DXVECTOR2 pivot(spriteData.pivotX, spriteData.pivotY);
//	D3DXVECTOR2 scale(spriteData.scale, spriteData.scale);
//	D3DXVECTOR2 screenPos(
//		spriteData.screenX - spriteData.pivotX, 
//		spriteData.screenY - spriteData.pivotY);
//	
//	D3DXMATRIX matrix;
//	D3DXMatrixTransformation2D(
//		&matrix,                        // The matrix
//		&pivot,							// Scaling center
//		0.0f,                           // No scaling rotation
//		&scale,							// Scaling amount
//		NULL,							// No rotation center
//		0.0f,							// Rotation angle
//		&screenPos);                    // X, Y location
//
//    sprite->SetTransform(&matrix);
//    sprite->Draw(spriteData.texture, &spriteData.rect, NULL, NULL, color);
//}

void Graphics::drawSprite(const SpriteData& spriteData, float screenX, float screenY, float scale, COLOR_ARGB color)
{
	if (spriteData.texture == NULL) return;

	D3DXVECTOR2 pivot(spriteData.pivotX, spriteData.pivotY);
	D3DXVECTOR2 scale2(scale, scale);
	D3DXVECTOR2 screenPos(
		screenX - spriteData.pivotX,
		screenY - spriteData.pivotY);

	D3DXMATRIX matrix;
	D3DXMatrixTransformation2D(
		&matrix,                        // The matrix
		&pivot,							// Scaling center
		0.0f,                           // No scaling rotation
		&scale2,						// Scaling amount
		NULL,							// No rotation center
		0.0f,							// Rotation angle
		&screenPos);                    // X, Y location

	sprite->SetTransform(&matrix);
	sprite->Draw(spriteData.texture, &spriteData.rect, NULL, NULL, color);
}

void Graphics::drawSprite(const SpriteData& spriteData, CoordF screenCoord, float scale, COLOR_ARGB color)
{
	if (spriteData.texture == NULL) return;

	D3DXVECTOR2 pivot(spriteData.pivotX, spriteData.pivotY);
	D3DXVECTOR2 scale2(scale, scale);
	D3DXVECTOR2 screenPos(
		screenCoord.x - spriteData.pivotX,
		screenCoord.y - spriteData.pivotY);

	D3DXMATRIX matrix;
	D3DXMatrixTransformation2D(
		&matrix,                        // The matrix
		&pivot,							// Scaling center
		0.0f,                           // No scaling rotation
		&scale2,						// Scaling amount
		NULL,							// No rotation center
		0.0f,							// Rotation angle
		&screenPos);                    // X, Y location

	sprite->SetTransform(&matrix);
	sprite->Draw(spriteData.texture, &spriteData.rect, NULL, NULL, color);
}