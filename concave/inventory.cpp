#include "inventory.h"

Inventory::Inventory()
{}

Inventory::~Inventory()
{}

void Inventory::initialize()
{
	CoordI inventoryCoord = { 0,0 };
	inventoryTexture.initialize(Window::graphics, IMAGE_HUD_INVENTORY);
	inventoryGridMask.initialize(0, 0, 320, 352, 1, 1, 0, 0);
	inventoryImage.initialize(&inventoryTexture, inventoryGridMask);
	inventoryImage.getSpriteData(inventorySpriteData, inventoryCoord);
}

void Inventory::releaseAll()
{}

void Inventory::resetAll()
{}

void Inventory::update()
{}

void Inventory::render()
{
	graphics->drawSprite(inventorySpriteData, GAME_WIDTH - 320, 0, 1);
}