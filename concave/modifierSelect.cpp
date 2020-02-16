#include "modifierSelect.h"

ModifierSelect::ModifierSelect()
{}

ModifierSelect::~ModifierSelect()
{}

void ModifierSelect::initialize()
{
	ModifierSelect::graphics = Window::graphics;
	ModifierSelect::input = Window::input;
	spriteText.initialize(graphics, IMAGE_HUD_FONT);
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
{
	if (input->getMouseLButton())
	{
		input->setMouseLButton(false);
		int mouseX = input->getMouseX();
		int mouseY = input->getMouseY();
		if (checkWhichButton(mouseX, mouseY) == 1)
		{
			increaseAttackSpeed(0, level.getPlayers(), 0.2);
		}
		else if (checkWhichButton(mouseX, mouseY) == 2)
		{
			increaseMaxHealth(0, level.getPlayers(), 50);
		}
		else if (checkWhichButton(mouseX, mouseY) == 3)
		{
			increaseProjectilesAmount(0, level.getPlayers(), 2);
		}

		input->setMouseLButton(true);
	}
	Window::hud.update();
}

int ModifierSelect::checkWhichButton(int mouseX, int mouseY)
{
	if (mouseX >= GAME_WIDTH / 3 && mouseX <= GAME_WIDTH / 3 + swordSpriteData.width * 5 &&
		mouseY >= GAME_HEIGHT / 2 && mouseY <= GAME_HEIGHT / 2 + swordSpriteData.height * 5)
	{
		return 1;
	}
	else if (mouseX >= GAME_WIDTH / 3 && mouseX <= GAME_WIDTH / 3 + shieldSpriteData.width * 5 &&
		mouseY >= GAME_HEIGHT / 2 && mouseY <= GAME_HEIGHT / 2 + shieldSpriteData.height * 5)
	{
		return 2;
	}
	else if (mouseX >= GAME_WIDTH / 3 && mouseX <= GAME_WIDTH / 3 + wandSpriteData.width * 5 &&
		mouseY >= GAME_HEIGHT / 2 && mouseY <= GAME_HEIGHT / 2 + wandSpriteData.height * 5)
	{
		return 3;
	}
	else
	{
		return NULL;
	}
}

void ModifierSelect::render()
{
	graphics->drawSprite(swordSpriteData, GAME_WIDTH / 4, GAME_HEIGHT / 3, 5);
	graphics->drawSprite(shieldSpriteData, GAME_WIDTH / 2, GAME_HEIGHT / 3, 5);
	graphics->drawSprite(wandSpriteData, GAME_WIDTH / 3 + GAME_WIDTH /3, GAME_HEIGHT / 3, 5);
}