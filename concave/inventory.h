#pragma once
#include "window.h"
#include "item.h"

class Inventory : public Window
{
private:
	vector<Item> playerInventory;
	Texture inventoryTexture;
	GridMask inventoryGridMask;
	Image inventoryImage;
	SpriteData inventorySpriteData;

public:
	Inventory();
	~Inventory();

	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};
