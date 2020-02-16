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
	healthSpriteData = imageToSpriteData(IMAGE_HUD_HEALTH);
	healthOrbSpriteData = imageToSpriteData(IMAGE_HUD_HEALTHORB);
	inventorySpriteData = getInventorySpriteData();
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
	// image.getSpriteData(imageSpriteData, imageCoord);
	image.getSpriteData(imageCoord);

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

void HUD::print()
{
	spriteText.print("HELP ME GPP IS\nSUFFERING", 0, 0);
}

void HUD::drawHUD()
{
	graphics->drawSprite(manaOrbSpriteData, GAME_WIDTH - 230, GAME_HEIGHT - 230, 1);
	graphics->drawSprite(healthOrbSpriteData, 0, GAME_HEIGHT - 230, 1);
	graphics->drawSprite(manaSpriteData, GAME_WIDTH - 530, GAME_HEIGHT - 230, 1);
	graphics->drawSprite(healthSpriteData, 0, GAME_HEIGHT - 230, 1);
	spriteText.print("HP: 100/100", 50, GAME_HEIGHT - 300);
	spriteText.print("MP: 100/100", GAME_WIDTH - 250, GAME_HEIGHT - 300);
}

void HUD::releaseAll()
{}

void HUD::resetAll()
{}

void HUD::update()
{}

void HUD::render()
{
	drawHUD();
	print();
}