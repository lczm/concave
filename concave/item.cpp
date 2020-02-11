#include "item.h"

Item::Item(UINT id, Graphics* graphics)
{
	CoordI itemCoord = { 0, id };
	itemID = id;

	itemTexture.initialize(graphics, IMAGE_HUD_ITEMS);
	itemGridMask.initialize(2, 355, 28, 28, 1, 0, 0, 0);
	itemImage.initialize(&itemTexture, itemGridMask);
	itemImage.getSpriteData(itemSpriteData, itemCoord);
}

Item::~Item()
{}


