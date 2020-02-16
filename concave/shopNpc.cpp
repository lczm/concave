#include "shopNpc.h"


void ShopNpc::ShopMenu()
{
	std::vector<std::vector<std::string>> itemRecords = gm.read("text\\items.csv", 2);
	//draw menu
}

void ShopNpc::buyItem(Players player)
{
	std::vector<std::vector<std::string>> records = gm.read("text\\player.csv", 2);
	std::vector<std::vector<std::string>> itemRecords = gm.read("text\\items.csv", 2);
	int amtMoney = std::stoi(records[1][1]);

	bool canPurchase = false;
	vector<string> itemsCanBuy;

	for (int i = 1; i < itemRecords.size(); i++)
	{
		if (std::stoi(itemRecords[i][1]) < amtMoney)
		{
			itemsCanBuy.push_back(itemRecords[i][0]);
		}
	}

	//draw hud on items that can be bought
	std::vector<std::vector<std::string>> selected;

}

int ShopNpc::calculate(std::vector<std::vector<std::string>> selected)
{
	std::vector<std::vector<std::string>> itemRecords = gm.read("text\\items.csv", 2);
	return 0;
}