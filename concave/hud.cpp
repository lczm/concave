#include "hud.h"

HUD::HUD()
{
}

HUD::~HUD()
{}

void HUD::initialize()
{
	HUD::graphics = Window::graphics;
	HUD::input = Window::input;
	manaSpriteData = imageToSpriteData(IMAGE_HUD_MANA, 530, 230);
	healthSpriteData = imageToSpriteData(IMAGE_HUD_HEALTH, 530, 230);
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

void HUD::print()
{
	spriteText.print("AB 123\nA", -100, -100);
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
	print();
}