#include "inventory.h"

Inventory::Inventory()
{}

Inventory::~Inventory()
{}

void Inventory::initialize()
{
	for (int i = 0; i < 4; i++)
	{
		inventoryGrid.push_back({});
		inventoryGrid.at(i).resize(10);
		for (int j = 0; j < 10; j++)
		{
			inventoryGrid[i][j] = new Item;
		}
	}
	inventoryX = GAME_WIDTH - 320;
	inventoryY = 0;
	itemInvenX = inventoryX + 18;
	itemInvenY = inventoryY + 223;
	CoordI inventorySpriteMapCoord = { 0,0 };
	inventoryTexture.initialize(Window::graphics, IMAGE_HUD_INVENTORY);
	inventoryGridMask.initialize(0, 0, 320, 352, 1, 1, 0, 0);
	inventoryImage.initialize(&inventoryTexture, inventoryGridMask);
	inventoryImage.getSpriteData(inventorySpriteData, inventorySpriteMapCoord);
	vector<int> invenPos = { 0,0 };
	Item* test1 = new Item(graphics, 1, ItemType::Armor, invenPos);
	invenPos = { 0,3 };
	Item* test2 = new Item(graphics, 1, ItemType::Elixr, invenPos);
	playerInventory.push_back(test1);
	playerInventory.push_back(test2);
}


void Inventory::releaseAll()
{}

void Inventory::resetAll()
{}

void Inventory::update()
{
	if (input->getMouseLButton())
	{
		int i = 1;
	}
}

void Inventory::render()
{
	graphics->drawSprite(inventorySpriteData, inventoryX, inventoryY, 1);
	for (int i = 0; i < playerInventory.size(); i++)
	{
		SpriteData sd = playerInventory.at(i)->getItemSpriteData();
		int itemX = itemInvenX + (playerInventory.at(i)->getInvenPos().at(0) * 29);
		int itemY = itemInvenY + (playerInventory.at(i)->getInvenPos().at(1) * 29);
		graphics->drawSprite(sd, itemX, itemY, 1);
	}
}