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
	boolean holdingItem;
	vector<Item*> heldItem;
	UINT inventoryX;
	UINT inventoryY;
	UINT itemInvenX;
	UINT itemInvenY;
	UINT itemInvenX2;
	UINT itemInvenY2;

public:
	Inventory();
	~Inventory();

	void initialize();
	void releaseAll();
	void resetAll();
	void update();
	void render();
	inline CoordI gridToScreen(CoordI invenPos);
	inline CoordI screenToGrid(int x, int y);
	void populateInventoryGrid();
	int gridToPlayerInven(Item* item);
	void removeItem(Item* item);
	void dropItem(Item* item);
	void holdItem(Item* item);
	vector<vector<int>> checkItemCount(CoordI invenPos, vector<int> itemSize);
	boolean clickInInven(int mX, int mY);
	void placeItem(Item* item, vector<vector<int>> overlaps, CoordI placedCoords);
};

