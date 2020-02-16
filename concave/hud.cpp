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
	manaSpriteData = imageToSpriteData(IMAGE_HUD_MANA);
	manaOrbSpriteData = imageToSpriteData(IMAGE_HUD_MANAORB);
	manaOrbRegenSpriteData = imageToSpriteData(IMAGE_HUD_MANAORBREGEN);
	healthSpriteData = imageToSpriteData(IMAGE_HUD_HEALTH);
	healthOrbSpriteData = imageToSpriteData(IMAGE_HUD_HEALTHORB);
	healthOrbRegenSpriteData = imageToSpriteData(IMAGE_HUD_HEALTHORBREGEN);
	inventorySpriteData = getInventorySpriteData();
	inventoryDisplayed = false;
}

SpriteData HUD::imageToSpriteData(const char* file)
{
	Texture imageTexture;
	SpriteData imageSpriteData;

	imageTexture.initialize(Window::graphics, file);
	imageTexture.getSpriteData(imageSpriteData);

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
	imageSpriteData = image.getSpriteData(imageCoord);

	return imageSpriteData;
}


SpriteData HUD::getInventorySpriteData()
{
	GridMask imageGridMask;
	CoordI imageCoord = { 0, 0 };
	imageGridMask.initialize(0, 0, 320, 352, 1, 1, 0, 0);
	inventorySpriteData = imageToSpriteData(IMAGE_HUD_INVENTORY, 320, 352, imageGridMask, imageCoord);

	return inventorySpriteData;
}


void HUD::drawHUD()
{
	int hpHeight = healthOrbSpriteData.height * 10 / 100;
	int mpHeight = manaOrbSpriteData.height * 10 / 100;
	healthOrbSpriteData.rect.top = hpHeight;
	manaOrbSpriteData.rect.top = mpHeight;
	graphics->drawSprite(manaOrbSpriteData, GAME_WIDTH - 230, GAME_HEIGHT - 230 + mpHeight, 1);
	graphics->drawSprite(healthOrbSpriteData, 0, GAME_HEIGHT - 230 + hpHeight, 1);
	graphics->drawSprite(manaSpriteData, GAME_WIDTH - 530, GAME_HEIGHT - 230, 1);
	graphics->drawSprite(healthSpriteData, 0, GAME_HEIGHT - 230, 1);
	spriteText.print("HP: 100/100", 20, GAME_HEIGHT - 280);
	spriteText.print("MP: 100/100", GAME_WIDTH - 220, GAME_HEIGHT - 280);
}

void HUD::releaseAll()
{}

void HUD::resetAll()
{}

void HUD::update()
{
	if (input->anyKeyPressed() && input->isKeyDown(0x49) )
	{
		if (!inventoryDisplayed)
		{
			windows.push_back(&inventory);
			inventoryDisplayed = true;
		}
		else
		{
			windows.pop_back();
			inventoryDisplayed = false;
		}
	}
	Window::level.update();
}

void HUD::render()
{
	drawHUD();
}