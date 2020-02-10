#include "hud.h"

HUD::HUD()
{}

HUD::~HUD()
{}

void HUD::initialize()
{
	HUD::graphics = Window::graphics;
	HUD::input = Window::input;
	spriteText.initialize(graphics, IMAGE_HUD_FONT);
	manaSpriteData = imageToSpriteData(IMAGE_HUD_MANA, 530, 230);
	healthSpriteData = imageToSpriteData(IMAGE_HUD_HEALTH, 530, 230);
	inventorySpriteData = getInventorySpriteData();
}

SpriteData HUD::imageToSpriteData(const char* file, UINT imageWidth, UINT imageHeight)
{
	Texture imageTexture;
	GridMask imageGridMask;
	Image image;
	SpriteData imageSpriteData;
	CoordI imageCoord = { 0,0 };

	imageTexture.initialize(Window::graphics, file);
	imageGridMask.initialize(0, 0, imageWidth, imageHeight, 0, 0, 0, 0);
	image.initialize(&imageTexture, imageGridMask);
	image.getSpriteData(imageSpriteData, imageCoord);

	return imageSpriteData;
}

SpriteData HUD::imageToSpriteData(const char* file, UINT imageWidth, UINT imageHeight, 
								  GridMask imageGridMask, CoordI imageCoord)
{
	Texture imageTexture;
	Image image;
	SpriteData imageSpriteData;

	imageTexture.initialize(Window::graphics, file);
	image.initialize(&imageTexture, imageGridMask);
	image.getSpriteData(imageSpriteData, imageCoord);

	return imageSpriteData;
}

void HUD::drawInventory(UINT x, UINT y)
{
	graphics->drawSprite(inventorySpriteData, x, y, 1);
}

SpriteData HUD::getInventorySpriteData()
{
	GridMask imageGridMask;
	CoordI imageCoord = { 0, 0 };
	imageGridMask.initialize(0, 0, 320, 352, 1, 1, 0, 0);
	inventorySpriteData = imageToSpriteData(IMAGE_HUD_INVENTORY, 320, 352, imageGridMask, imageCoord);

	return inventorySpriteData;
}

void HUD::print()
{
	spriteText.print("HELP ME GPP IS\nSUFFERING", 0, 0);
}

void HUD::releaseAll()
{}

void HUD::resetAll()
{}

void HUD::update()
{}

void HUD::render()
{
	graphics->drawSprite(manaSpriteData, GAME_WIDTH - 530, GAME_HEIGHT - 230, 1);
	graphics->drawSprite(healthSpriteData, 0, GAME_HEIGHT - 230, 1);
	drawInventory(GAME_WIDTH - 320, 0);
	print();
}