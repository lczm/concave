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

	/* Functions that you can use*/
	std::vector<std::vector<std::string>> read(std::string file_name, int numOfcols);

	//write a record
	void writeRecord(std::string file_name, std::vector<std::string> record);

	//search for based on col
	std::vector<std::vector<std::string>> searchForRecord(std::string file_name, std::string search_term, int numOfCols, int searchCol);

	//edit record
	void editRecord(std::string file_name, int searchTermCol, int editedCol, int numOfCols, std::string search_term, std::string newdata);


	/* helper functions*/

	//helper function for searchForRecord
	std::vector<std::vector<std::string>> searchMany(std::vector<std::vector<std::string>> records, std::string search_term, int searchCol);

	//filter out
	vector<std::vector<std::string>> filterOutRecord(std::string file_name, std::string search_term, int cols, int searchTermCol);

	//search for one record
	void skip(std::istream& is, size_t n, char delim);
};