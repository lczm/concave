#include "hud.h"

HUD::HUD()
{}

HUD::~HUD()
{}

void HUD::initialize(Graphics* graphics, Input* input)
{
	HUD::graphics = graphics;
	HUD::input = input;
	hudTexture.initialize(HUD::graphics, IMAGE_PLAYER_INFO);
	playerInfoGM.initialize(0, 0, 642, 130, 0, 0, 0, 0 - GAME_HEIGHT + 130);
	playerInfoImage.initialize(&hudTexture, playerInfoGM);

}

SpriteData HUD::getSpriteData()
{
	SpriteData sd;
	playerInfoImage.getSpriteData(sd, test);
	return sd;
}

void HUD::releaseAll()
{}

void HUD::resetAll()
{}

void HUD::update()
{}

void HUD::render()
{}