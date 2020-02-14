#include "gameInfoComponent.h"

GameInfoComponent::GameInfoComponent()
{

}

void GameInfoComponent::writeRecord(std::string file_name, std::vector<std::string> record)
{

	std::ofstream file;
	file.open(file_name, ios::app | ios::out);

	for (int i = 0; i < record.size(); i++)
	{
		if (i < record.size() - 1)
		{
			file << record[i] << ",";
		}
		else {
			file << record[i] << std::endl;
		}

	}
	file.close();
}

//read all records of a file
std::vector<std::vector<std::string>> GameInfoComponent::read(std::string file_name, int numOfcols)
{
	std::vector<std::vector<std::string>> record;
	std::ifstream file;
	file.open(file_name);
	bool found_record = false;

	std::string field_one;

	while (file.peek() != EOF)
	{
		getline(file, field_one, ',');
		std::vector<std::string> recordTest;
		recordTest.push_back(field_one);

		for (int i = 1; i < numOfcols; i++)
		{
			std::string field_two;
			if (i == numOfcols - 1)
			{
				getline(file, field_two, '\n'); //states the end of the record
			}
			else
			{
				getline(file, field_two, ','); //states the end of the record
			}
			recordTest.push_back(field_two);
		}

		record.push_back(recordTest);
		recordTest.clear();
	}

	file.close();
	return record;
}

//searchs for a particular col with the value that you want and returns all records with that value
std::vector<std::vector<std::string>> GameInfoComponent::searchForRecord(std::string file_name, std::string search_term, int numOfCols, int searchCol = -1)
{
	//first it reads all of the records
	std::vector<std::vector<std::string>> data = read(file_name, numOfCols);

	//then it searches for all that match the search term given
	std::vector<std::vector<std::string>> returned = searchMany(data, search_term, searchCol);

	return returned;
}


//return many records 
//modify to also search a specific column or all columns
std::vector<std::vector<std::string>> GameInfoComponent::searchMany(std::vector<std::vector<std::string>> records, std::string search_term, int searchCol = -1)
{
	std::vector<std::vector<std::string>> searchedRecords;
	for (int i = 0; i < records.size(); i++)
	{

		if (searchCol != -1)
		{	
			if (search_term == "")
			{
				searchedRecords.push_back(records[i]);
			}
			else if (records[i][searchCol] == search_term)
			{
				searchedRecords.push_back(records[i]);
			}
		}
		else
		{
			for (int j = 0; j < records[i].size(); j++)
			{
				if (records[i][j] == search_term)
				{
					searchedRecords.push_back(records[i]);
				}
			}
		}
	}

	return searchedRecords;
}


/*
	**Documentation**

	file_name = your filename
	search_term;
	searchTermCol = rows in which you want to get  (all col values)
	editedCol = col in the rows that you got from  searchTermCol in which you want to change the value
	newData =  data u want to put into the edited column
*/
void GameInfoComponent::editRecord(std::string file_name, int searchTermCol, int editedCol, int numOfCols, std::string search_term, std::string newdata)
{
	//search for the record
	vector<std::vector<std::string>>  data = searchForRecord(file_name, search_term, numOfCols, searchTermCol);

	//duplication happends here
	vector<std::vector<std::string>> allrecords = filterOutRecord(file_name, search_term, numOfCols, searchTermCol);

	std::ofstream ofs(file_name, std::ifstream::out | std::ifstream::trunc);
	ofs.close();

	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			if (j == editedCol)
			{
				data[i][editedCol] = newdata;
				allrecords.push_back(data[i]);
			}
		}
	}

	for (int i = 0; i < allrecords.size(); i++)
	{
		writeRecord(file_name, allrecords[i]);
	}

	allrecords.clear();
	data.clear();
}

/*
	**Documentation**
	file_name = your filename
	search_term;
	int cols = number of cols in the file
	searchTermCol = rows in which you want to get  (all col values)
*/
vector<std::vector<std::string>> GameInfoComponent::filterOutRecord(std::string file_name, std::string search_term, int cols, int searchTermCol)
{
	vector<std::vector<std::string>> records;
	// first it reads all of the records
	std::vector<std::vector<std::string>> data = read(file_name, cols);

	for (int i = 0; i < data.size(); i++)
	{	
		//write more elegant code yes
		if (data[i][searchTermCol] != search_term && search_term != "")
		{
			records.push_back(data[i]);
		}
	}

	return records;
}


void  GameInfoComponent::skip(std::istream& is, size_t n, char delim)
{
	size_t i = 0;
	while (i++ < n)
		is.ignore(80, delim);
	// ignores up to 80 chars but stops ignoring after delim
	// istream stream position var is changed. (we want that)
}