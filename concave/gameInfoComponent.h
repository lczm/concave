#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class GameInfoComponent
{
private:

public:
	GameInfoComponent();
	void writeRecord(std::string file_name, std::string field_one, std::string field_two, std::string field_three);
	std::vector<std::string> readRecord(std::string file_name, std::string search_term);
	void read();
	//void create();
	//void readRowCol(int row, int col);
};