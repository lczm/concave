#include "item.h"

Item::Item(UINT id, Graphics* graphics)
{
	CoordI itemCoord = { id, 0 };
	itemID = id;

	itemTexture.initialize(graphics, IMAGE_HUD_ITEMS);
	itemGridMask.initialize(4, 348, 28, 28, 1, 0, 0, 0);
	itemImage.initialize(&itemTexture, itemGridMask);
	itemImage.getSpriteData(itemSpriteData, itemCoord);
}

Item::~Item()
{}


