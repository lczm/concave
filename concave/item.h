#pragma once
#include "image.h"

class Item
{
private:
	Texture itemTexture;
	GridMask itemGridMask;
	Image itemImage;
	ItemType itemType;
	CoordI posInInventory;
	vector<int> itemSize;
	SpriteData itemSpriteData;
	UINT itemID;

public:
	Item();
	Item(Graphics* graphics, UINT id, ItemType itemType, CoordI posInInven);
	~Item();
	SpriteData getItemSpriteData() { return itemSpriteData; }
	CoordI getInvenPos() { return posInInventory; }
	vector<int> getItemSize() { return itemSize; }
	void setItemPos(CoordI pos) { posInInventory = pos; }
};