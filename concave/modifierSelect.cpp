#include "modifierSelect.h"

ModifierSelect::ModifierSelect()
{}

ModifierSelect::~ModifierSelect()
{}

void ModifierSelect::initialize()
{
	ModifierSelect::graphics = Window::graphics;
	ModifierSelect::input = Window::input;
	modifierGridMask.initialize(0, 0, 32, 32, 1, 1, 0, 0);
	shieldCoord = { 0, 0 };
	swordCoord = { 1,0 };
	wandCoord = { 7, 0 };
	shieldSpriteData = imageToSpriteData(IMAGE_HUD_MODIFIERS, modifierGridMask, shieldCoord);
	swordSpriteData = imageToSpriteData(IMAGE_HUD_MODIFIERS, modifierGridMask, swordCoord);
	wandSpriteData = imageToSpriteData(IMAGE_HUD_MODIFIERS, modifierGridMask, wandCoord);
}

SpriteData ModifierSelect::imageToSpriteData(const char* file, GridMask imageGridMask, CoordI imageCoord)
{
	Texture imageTexture;
	Image image;
	SpriteData imageSpriteData;

	imageTexture.initialize(Window::graphics, file);
	image.initialize(&imageTexture, imageGridMask);
	imageSpriteData = image.getSpriteData(imageCoord);

	return imageSpriteData;
}

void ModifierSelect::releaseAll()
{}

void ModifierSelect::resetAll()
{}

void ModifierSelect::update()
{}

void ModifierSelect::render()
{}