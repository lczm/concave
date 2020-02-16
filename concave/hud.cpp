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
	itemGridMask.initialize(5, 348, 28, 28, 1, 0, 0, 0);
	skillsGridMask.initialize(0, 0, 56, 56, 1, 1, 0, 0);
	fireballCoord = { 0,0 };
	teleportCoord = { 1,2 };
	emptyHealthPotCoord = { 0, 0 };
	healthPotCoord = { 1, 0 };
	emptyManaPotCoord = { 2, 0 };
	manaPotCoord = { 3, 0 };
	fireballSpriteData = imageToSpriteData(IMAGE_HUD_SKILLS, skillsGridMask, fireballCoord);
	teleportSpriteData = imageToSpriteData(IMAGE_HUD_SKILLS, skillsGridMask, teleportCoord);
	healthPotSpriteData = imageToSpriteData(IMAGE_HUD_ITEMS, itemTranscolor, itemGridMask, healthPotCoord);
	manaPotSpriteData = imageToSpriteData(IMAGE_HUD_ITEMS, itemTranscolor, itemGridMask, manaPotCoord);
	emptyHealthPotSpriteData = imageToSpriteData(IMAGE_HUD_ITEMS, itemTranscolor, itemGridMask, emptyHealthPotCoord);
	emptyManaPotSpriteData = imageToSpriteData(IMAGE_HUD_ITEMS, itemTranscolor, itemGridMask, emptyManaPotCoord);
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

SpriteData HUD::imageToSpriteData(const char* file, GridMask imageGridMask, CoordI imageCoord)
{
	Texture imageTexture;
	Image image;
	SpriteData imageSpriteData;

	imageTexture.initialize(Window::graphics, file);
	image.initialize(&imageTexture, imageGridMask);
	imageSpriteData = image.getSpriteData(imageCoord);

	return imageSpriteData;
}

SpriteData HUD::imageToSpriteData(const char* file, COLOR_ARGB color, GridMask imageGridMask, CoordI imageCoord)
{
	Texture imageTexture;
	Image image;
	SpriteData imageSpriteData;

	imageTexture.initialize(Window::graphics, file, color);
	image.initialize(&imageTexture, imageGridMask);
	imageSpriteData = image.getSpriteData(imageCoord);

	return imageSpriteData;
}

void HUD::drawHUD()
{
	int& currentHealth = level.getPlayers().getHealthArray()[0];
	int& maxHealth = level.getPlayers().getMaxHealthArray()[0];
	int& currentMana = level.getPlayers().getManaArray()[0];
	int& maxMana = level.getPlayers().getMaxManaArray()[0];

	int hpHeight = healthOrbSpriteData.height * maxHealth - currentHealth / 100;
	int mpHeight = manaOrbSpriteData.height * maxMana - currentMana / 100;
	healthOrbSpriteData.rect.top = hpHeight;
	manaOrbSpriteData.rect.top = mpHeight;
	graphics->drawSprite(manaOrbSpriteData, GAME_WIDTH - 230, GAME_HEIGHT - 230 + mpHeight, 1);
	graphics->drawSprite(healthOrbSpriteData, 0, GAME_HEIGHT - 230 + hpHeight, 1);
	graphics->drawSprite(manaSpriteData, GAME_WIDTH - 530, GAME_HEIGHT - 230, 1);
	graphics->drawSprite(healthSpriteData, 0, GAME_HEIGHT - 230, 1);
	graphics->drawSprite(fireballSpriteData, GAME_WIDTH - 520, GAME_HEIGHT - 62, 1);
	graphics->drawSprite(teleportSpriteData, GAME_WIDTH - 463, GAME_HEIGHT - 62, 1);
	graphics->drawSprite(healthPotSpriteData, 469, GAME_HEIGHT - 62, 1.9);
	graphics->drawSprite(healthPotSpriteData, 412, GAME_HEIGHT - 62, 1.9);
	graphics->drawSprite(manaPotSpriteData, 355, GAME_HEIGHT - 62, 1.9);
	spriteText.print("HP: " + to_string(currentHealth) + "/" + to_string(maxHealth), 20, GAME_HEIGHT - 280);
	spriteText.print("MP: " + to_string(currentMana) + "/" + to_string(maxMana), GAME_WIDTH - 220, GAME_HEIGHT - 280);
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