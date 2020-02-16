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
			inventoryGrid[i][j] = NULL;
		}
	}
	inventoryX = GAME_WIDTH - 320;
	inventoryY = 0;
	itemInvenX = inventoryX + 18;
	itemInvenY = inventoryY + 223;
	itemInvenX2 = itemInvenX + 290;
	itemInvenY2 = itemInvenY + 116;
	CoordI inventorySpriteMapCoord = { 0,0 };
	inventoryTexture.initialize(Window::graphics, IMAGE_HUD_INVENTORY);
	inventoryGridMask.initialize(0, 0, 320, 352, 1, 1, 0, 0);
	inventoryImage.initialize(&inventoryTexture, inventoryGridMask);
	inventorySpriteData = inventoryImage.getSpriteData(inventorySpriteMapCoord);
	CoordI invenPos = { 0,0 };
	Item* test1 = new Item(graphics, 1, ItemType::Armor, invenPos);
	invenPos = { 0,3 };
	Item* test2 = new Item(graphics, 1, ItemType::Elixr, invenPos);
	invenPos = { 1,3 };
	Item* test3 = new Item(graphics, 1, ItemType::Elixr, invenPos);
	playerInventory.push_back(test1);
	playerInventory.push_back(test2);
	playerInventory.push_back(test3);
	populateInventoryGrid();
}


void Inventory::releaseAll()
{}

void Inventory::resetAll()
{}

void Inventory::update()
{
	if (input->getMouseLButton())
	{
		input->setMouseLButton(false);
		int mouseX = input->getMouseX();
		int mouseY = input->getMouseY();
		if (holdingItem)
		{
			vector<vector<int>> overlapCoords;
			if (clickInInven(mouseX, mouseY))
			{
				CoordI invenPos = screenToGrid(mouseX, mouseY);
				CoordI placedCoords = { invenPos.x, invenPos.y };
				if (!inventoryGrid[invenPos.y][invenPos.x] == NULL)
				{
					Item* item = inventoryGrid[invenPos.y][invenPos.x];
					overlapCoords = checkItemCount(invenPos, heldItem.at(0)->getItemSize());
					placeItem(heldItem.at(0), overlapCoords, placedCoords);
				}
				else
				{
					overlapCoords = checkItemCount(invenPos, heldItem.at(0)->getItemSize());
					placeItem(heldItem.at(0), overlapCoords, placedCoords);
				}
			}
			else
			{
				dropItem(heldItem.at(0));
			}
		}
		else
		{
			if (clickInInven(mouseX, mouseY))
			{
				CoordI invenPos = screenToGrid(mouseX, mouseY);
				if (!inventoryGrid[invenPos.y][invenPos.x] == NULL)
				{
					Item* item = inventoryGrid[invenPos.y][invenPos.x];
					holdItem(item);
				}
			}
		}
	}
	if (input->getMouseRButton())
	{
		int mouseX = input->getMouseX();
		int mouseY = input->getMouseY();
		if (clickInInven(mouseX, mouseY))
		{
			CoordI invenPos = screenToGrid(mouseX, mouseY);
			if (!inventoryGrid[invenPos.y][invenPos.x] == NULL)
			{
				removeItem(inventoryGrid[invenPos.x][invenPos.y]);
			}
		}
	}
}

void Inventory::render()
{
	graphics->drawSprite(inventorySpriteData, inventoryX, inventoryY, 1);
	for (int i = 0; i < playerInventory.size(); i++)
	{
		SpriteData sd = playerInventory.at(i)->getItemSpriteData();
		CoordI invenPosition = playerInventory.at(i)->getInvenPos();
		CoordI inventoryCoords = gridToScreen(invenPosition);
		graphics->drawSprite(sd, inventoryCoords.x, inventoryCoords.y, 1);
	}
	for (int i = 0; i < heldItem.size(); i++)
	{
		SpriteData sd = heldItem.at(i)->getItemSpriteData();
		graphics->drawSprite(sd, input->getMouseX(), input->getMouseY(), 1);
	}

}

inline CoordI Inventory::gridToScreen(CoordI invenPos)
{
	int sx = itemInvenX + (invenPos.x * 29);
	int sy = itemInvenY + (invenPos.y * 29);

	CoordI screenCoords = { sx, sy };
	return screenCoords;
}

inline CoordI Inventory::screenToGrid(int sx, int sy)
{
	int invenX = sx - itemInvenX;
	invenX = invenX / 29;
	int invenY = sy - itemInvenY;
	invenY = invenY / 29;

	CoordI invenCoord = { invenX, invenY };
	return invenCoord;
}

void Inventory::populateInventoryGrid()
{
	for (int i = 0; i < playerInventory.size(); i++)
	{
		Item* item = playerInventory.at(i);
		vector<int> itemSize = item->getItemSize();
		CoordI itemPosition = item->getInvenPos();
		for (int j = 0; j < itemSize[1]; j++)
		{
			for (int k = 0; k < itemSize[0]; k++)
			{
				inventoryGrid[itemPosition.y + k][itemPosition.x + j] = item;
			}
		}
	}
}

void Inventory::removeItem(Item* item)
{
	CoordI itemPosition = item->getInvenPos();
	vector<int> itemSize = item->getItemSize();
	int index = gridToPlayerInven(item);
	playerInventory.erase(playerInventory.begin() + index);

	for (int j = 0; j < itemSize[1]; j++)
	{
		for (int k = 0; k < itemSize[0]; k++)
		{
			inventoryGrid[itemPosition.y + k][itemPosition.x + j] = NULL;
		}
	}
}

int Inventory::gridToPlayerInven(Item* item)
{
	CoordI itemCoords = item->getInvenPos();
	for (int i = 0; i < playerInventory.size(); i++)
	{
		CoordI itemCoordsInPlayerInven = playerInventory.at(i)->getInvenPos();
		if (itemCoordsInPlayerInven.x == itemCoords.x && itemCoordsInPlayerInven.y == itemCoords.y)
		{
			return i;
		}
	}
}

void Inventory::dropItem(Item* item)
{

}

void Inventory::holdItem(Item* item)
{
	heldItem.push_back(item);
	removeItem(item);
	holdingItem = true;
}

boolean Inventory::clickInInven(int mX, int mY)
{
	if (mX > itemInvenX&& mY > itemInvenY&& mX < itemInvenX2 && mY < itemInvenY2)
	{
		return true;
	}
	return false;
}

vector<vector<int>> Inventory::checkItemCount(CoordI invenPos, vector<int> itemSize)
{
	vector<Item*> overlappingItems;
	vector<vector<int>> itemCoords;
	int count = 0;
	for (int i = 0; i < itemSize[1]; i++)
	{
		for (int j = 0; j < itemSize[0]; j++)
		{
			if (!inventoryGrid[invenPos.y + j][invenPos.x + i] == NULL)
			{
				overlappingItems.push_back(inventoryGrid[invenPos.y + j][invenPos.x + i]);
			}
		}
	}

	for (int i = 0; i < overlappingItems.size(); i++)
	{
		CoordI currentItemCoord = overlappingItems.at(i)->getInvenPos();
		vector<int> vectorCoord = { currentItemCoord.x, currentItemCoord.y };
		
		if (find(itemCoords.begin(), itemCoords.end(), vectorCoord) == itemCoords.end())
		{
			itemCoords.push_back(vectorCoord);
		}
	}

	return itemCoords;
}

void Inventory::placeItem(Item* item, vector<vector<int>> overlaps, CoordI placedCoords)
{
	int numOfOverlaps = overlaps.size();
	vector<int> itemSize = item->getItemSize();
	if (numOfOverlaps == 0)
	{
		if (placedCoords.y + itemSize.at(0) < 5 && placedCoords.y + itemSize.at(1) < 10)
		{
			item->setItemPos(placedCoords);
			playerInventory.push_back(item);
			holdingItem = false;
		}
		else
		{
			return;
		}
	}
	else if (numOfOverlaps == 1)
	{
		if (placedCoords.y + itemSize.at(0) < 5 && placedCoords.y + itemSize.at(1) < 10)
		{
			Item* takenItem = inventoryGrid[overlaps[0][1]][overlaps[0][0]];
			item->setItemPos(placedCoords);
			playerInventory.push_back(item);
			heldItem.push_back(takenItem);
			removeItem(takenItem);
		}
		else
		{
			return;
		}
	}
	else
	{
		return;
	}
	populateInventoryGrid();
	heldItem.erase(heldItem.begin());
}



