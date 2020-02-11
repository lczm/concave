#include "item.h"

Item::Item(UINT id, Graphics* graphics, ItemType itemType)
{
	CoordI itemCoord = { id, 0 };
	COLOR_ARGB customTranscolor = D3DCOLOR_ARGB(255, 73, 101, 101);
	itemID = id;

	switch (itemType)
	{
	case ItemType::Elixr:
		itemTexture.initialize(graphics, IMAGE_HUD_ITEMS, customTranscolor);
		itemGridMask.initialize(5, 348, 28, 28, 1, 0, 0, 0);
		itemImage.initialize(&itemTexture, itemGridMask);
		itemImage.getSpriteData(itemSpriteData, itemCoord);
	}
}

Item::~Item()
{}


