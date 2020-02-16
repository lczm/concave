#include "item.h"

Item::Item()
{}

Item::Item(Graphics* graphics, UINT id, ItemType itemtype, vector<int> posInInven)
{
	CoordI itemSpriteMapCoord = { id, 0 };
	COLOR_ARGB customTranscolor = D3DCOLOR_ARGB(255, 73, 101, 101);
	itemID = id;
	vector<int> is;
	itemTexture.initialize(graphics, IMAGE_HUD_ITEMS, customTranscolor);

	switch (itemtype)
	{
	case ItemType::Elixr:
		itemType = ItemType::Elixr;
		itemGridMask.initialize(5, 348, 28, 28, 1, 0, 0, 0);
		itemImage.initialize(&itemTexture, itemGridMask);
		itemImage.getSpriteData(itemSpriteData, itemSpriteMapCoord);
		is = { 1, 1 };
		itemSize = is;
		break;
	case ItemType::Armor:
		itemType = ItemType::Armor;
		itemGridMask.initialize(1, 20, 56, 84, 1, 0, 0, 0);
		itemImage.initialize(&itemTexture, itemGridMask);
		itemImage.getSpriteData(itemSpriteData, itemSpriteMapCoord);
		is = { 3, 2 };
		itemSize = is;
		break;
	}
	posInInventory = posInInven;
}

Item::~Item()
{}


