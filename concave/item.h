#pragma once
#include "image.h"

class Item
{
private:
	Texture itemTexture;
	GridMask itemGridMask;
	Image itemImage;
	ItemType itemType;
	vector<int> posInInventory;
	vector<int> itemSize;
	SpriteData itemSpriteData;
	UINT itemID;

public:
	Item();
	Item(Graphics* graphics, UINT id, ItemType itemType, vector<int> posInInven);
	~Item();
	SpriteData getItemSpriteData() { return itemSpriteData; }
	vector<int> getInvenPos() { return posInInventory; }
};