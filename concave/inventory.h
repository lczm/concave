#pragma once
#include "window.h"
#include "item.h"

class Inventory : public Window
{
private:
	vector<Item*> playerInventory;
	Texture inventoryTexture;
	GridMask inventoryGridMask;
	Image inventoryImage;
	SpriteData inventorySpriteData;
	UINT inventoryX;
	UINT inventoryY;

public:
	Inventory();
	~Inventory();

	void populateInventory(vector<int> playerInven);
	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
};
