#pragma once
#include "image.h"

class Item
{
private:
	Texture itemTexture;
	GridMask itemGridMask;
	Image itemImage;
	SpriteData itemSpriteData;
	UINT itemID;

public:
	Item(UINT id, Graphics* graphics, ItemType itemType);
	~Item();
	SpriteData getItemSpriteData() { return itemSpriteData; }
};