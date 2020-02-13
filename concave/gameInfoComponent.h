#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>

using namespace std;

class GameInfoComponent
{
private:

public:
	GameInfoComponent();
	void writeRecord(std::string file_name, std::vector<std::string> record);
	vector<std::vector<std::string>> filterOutRecord(std::string file_name, std::string search_term);

	void appendRecord(std::string file_name, int col, std::string search_term, std::string newdata);



	std::vector<std::string> readRecord(std::string file_name, std::string search_term);
	void read();
	void skip(std::istream& is, size_t n, char delim);
	//void create();
	//void readRowCol(int row, int col);
};