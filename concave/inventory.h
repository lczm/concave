#pragma once
#include "window.h"
#include "item.h"

class Inventory : public Window
{
private:
	vector<vector<Item*>> inventoryGrid;
	vector<Item*> playerInventory;
	Texture inventoryTexture;
	GridMask inventoryGridMask;
	Image inventoryImage;
	SpriteData inventorySpriteData;
	UINT inventoryX;
	UINT inventoryY;
	UINT itemInvenX;
	UINT itemInvenY;

public:
	Inventory();
	~Inventory();

	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};

