#pragma once
#include "constants.h"
#include "players.h"
#include "gameInfoComponent.h"
class ShopNpc
{
private:
	GameInfoComponent gm;
	int money = 9999999;
public:
	void ShopMenu();
	void buyItem(Players player);
	int calculate(std::vector<std::vector<std::string>> selected);

};