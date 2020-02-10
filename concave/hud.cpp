#include "hud.h"

HUD::HUD()
{
	spriteText = new SpriteText();
}

HUD::~HUD()
{}

void HUD::initialize(Graphics* graphics, Input* input)
{
	HUD::graphics = graphics;
	HUD::input = input;
	spriteText->initialize(graphics, IMAGE_HUD_FONT);
	hudTexture.initialize(HUD::graphics, IMAGE_HUD_PLAYER_INFO);
	playerInfoGM.initialize(0, 0, 642, 130, 0, 0, 0-(GAME_WIDTH/2 - 642/2), 0 - GAME_HEIGHT + 130);
	playerInfoImage.initialize(&hudTexture, playerInfoGM);

}

SpriteData HUD::getSpriteData()
{
	SpriteData sd;
	playerInfoImage.getSpriteData(sd, test);
	return sd;
}

void HUD::print()
{
	spriteText->print("AB 123\nA", 0, -100);
}

void HUD::releaseAll()
{}

void HUD::resetAll()
{}

void HUD::update()
{}

void HUD::render()
{}