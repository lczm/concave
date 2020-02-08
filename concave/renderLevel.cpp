#include "renderLevel.h"

RenderLevel::RenderLevel()
{

}

RenderLevel::~RenderLevel()
{

}
void RenderLevel::initialize(Graphics* graphics, Input* input, int type)
{
	RenderLevel::graphics = graphics;
	RenderLevel::input = input;


	if (type == 0)
	{
		tileTexture.initialize(graphics, IMAGE_TILES_DUNGEON);
	}
	else
	{
		tileTexture.initialize(graphics, IMAGE_TILES_CAVE);
	}


	tileGridMask.initialize(0, 0, 128, 192, 1, 1, 128 / 2, 192 - TILE_HEIGHT - 1);
	tileImage.initialize(&tileTexture, tileGridMask);
}

void RenderLevel::renderMap(int map[mapWidth][mapHeight], int x, int y, SpriteData& sd, int type)
{

	//choose between the standard coordinates to load maps
	if (type == 0)
	{
		switch (map[x][y])
		{
			//changing between textures
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
		case ImageType::churchWallEast:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchWallEast));
			break;
		case ImageType::churchWallWest:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchWallWest));
			break;
		case ImageType::churchWallConnect:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchWallConnect));
			break;
		case ImageType::churchWallPath:
			tileImage.getSpriteData(sd, IMAGE_MAP.at(ImageType::churchWallPath));
			break;
		}
	}
	else if (type == 1)
	{
		switch (map[x][y])
		{
			//changing between textures
		case ImageTypeCave::caveLava:
			tileImage.getSpriteData(sd, IMAGE_MAP_CAVE.at(ImageTypeCave::caveLava));
			break;
		case ImageTypeCave::caveFloor:
			tileImage.getSpriteData(sd, IMAGE_MAP_CAVE.at(ImageTypeCave::caveFloor));
			break;
		}
	}
}

