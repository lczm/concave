#include "renderLevel.h"

RenderLevel::RenderLevel()
{

}

RenderLevel::~RenderLevel()
{

}
void RenderLevel::initialize(Graphics* graphics, Input* input)
{
	RenderLevel::graphics = graphics;
	RenderLevel::input = input;

	tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 128 / 2, 192 - TILE_HEIGHT - 1);
	tileImage.initialize(&tileTexture, tileGridMask);
}

void RenderLevel::renderMap(int map[mapWidth][mapHeight], int x, int y, SpriteData &sd)
{
	switch (map[x][y])
	{
		case ImageType::churchBlood:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchBlood));
			break;
		case ImageType::churchFloor:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchFloor));
			break;
		case ImageType::churchDoor:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchDoor));
			break;
		case ImageType::churchChest:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchChest));
			break;
		case ImageType::chruchWallEast:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::chruchWallEast));
			break;
		case ImageType::chruchWallWest:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::chruchWallWest));
			break;
	}

}

