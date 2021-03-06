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


	//reference to yh code
	//void initialize(int originX, int originY, int perWidth, int perHeight, int gapWidth, int gapHeight, int pivotX, int pivotY);
	//In game items
	itemTexture.initialize(graphics, IMAGE_ITEMS_DUNGEON);
	itemGridMask.initialize(0, 0, 130, 130, 1, 1, 59, 59);
	itemImage.initialize(&itemTexture, itemGridMask);


	//barrel png
	manyItemsTexture.initialize(graphics, IMAGE_BARRELITEMS_DUNGEON);
	manyItemsGridMask.initialize(0,0, 94, 119, 1,1, 45, 44);
	manyItemsImage.initialize(&manyItemsTexture, manyItemsGridMask);


	//cabinet
	cabinetGridMask.initialize(0, 0, 111, 110, 1, 1, 50, 55 );
	cabinetImage.initialize(&manyItemsTexture, cabinetGridMask);

	//fire
	flameGridMask.initialize(0, 0, 69, 107, 1, 1, -40, 20);
	flameImage.initialize(&manyItemsTexture, flameGridMask);

	//dead man
	deadPeopleGridMask.initialize(0, 0, 113, 131, 1, 1, 40, 20);
	deadPeopleImage.initialize(&manyItemsTexture, flameGridMask);

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
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchBlood));
			break;
		case ImageType::churchFloor:
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchFloor));
			break;
		case ImageType::churchDoor:
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchDoor));
			break;
		case ImageType::churchChest:
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchChest));
			break;
		case ImageType::churchWallEast:
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchWallEast));
			break;
		case ImageType::churchWallWest:
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchWallWest));
			break;
		case ImageType::churchWallConnect:
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchWallConnect));
			break;
		case ImageType::churchWallPath:
			tileImage.getSpriteData(IMAGE_MAP.at(ImageType::churchWallPath));
			break;
		//test objects
		case 8:
			itemImage.getSpriteData( CoordI{0,0});
			break;
		case 9:
			itemImage.getSpriteData( CoordI{21,0});
			break;
		case 10:
			tileImage.getSpriteData( CoordI{14,8});
			break;
		case 11:
			//barrel *add to constants
			manyItemsImage.getSpriteData(CoordI{ 0,0 });
			break;
		case 12:
			cabinetImage.getSpriteData(CoordI{ 0,6 });
			break;
		case 13:
			flameImage.getSpriteData(CoordI{ 0,3 });
			break;
		case 14: 
			deadPeopleImage.getSpriteData(CoordI{ 16,17 });
			break;
		}
	}
	else if (type == 1)
	{
		switch (map[x][y])
		{
			//changing between textures
		case ImageTypeCave::caveLava:
			tileImage.getSpriteData(IMAGE_MAP_CAVE.at(ImageTypeCave::caveLava));
			break;
		case ImageTypeCave::caveFloor:
			tileImage.getSpriteData(IMAGE_MAP_CAVE.at(ImageTypeCave::caveFloor));
			break;
		}
	}
}

void RenderLevel::renderMiniMap(int map[mapWidth][mapHeight])
{

}
