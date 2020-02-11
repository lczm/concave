#include "inventory.h"

Inventory::Inventory()
{}

Inventory::~Inventory()
{}

void Inventory::initialize()
{
	inventoryX = GAME_WIDTH - 320;
	inventoryY = 0;
	CoordI inventoryCoord = { 0,0 };
	inventoryTexture.initialize(Window::graphics, IMAGE_HUD_INVENTORY);
	inventoryGridMask.initialize(0, 0, 320, 352, 1, 1, 0, 0);
	inventoryImage.initialize(&inventoryTexture, inventoryGridMask);
	inventoryImage.getSpriteData(inventorySpriteData, inventoryCoord);
	vector<int> testInven;
	testInven.push_back(1);
	testInven.push_back(2);
	testInven.push_back(3);
	populateInventory(testInven);
}

void Inventory::populateInventory(vector<int> playerInven)
{
	for (int i = 0; i < playerInven.size(); i++)
	{
		Item* item = new Item(playerInven.at(i), Window::graphics);
		playerInventory.push_back(item);
	}
}


void Inventory::releaseAll()
{}

void Inventory::resetAll()
{}

void Inventory::update()
{}

void Inventory::render()
{
	graphics->drawSprite(inventorySpriteData, inventoryX, inventoryY, 1);
	for (int i = 0; i < playerInventory.size(); i++)
	{
		graphics->drawSprite(playerInventory.at(i)->getItemSpriteData(), inventoryX + (30 * (i+1)), inventoryY, 1);
	}
}