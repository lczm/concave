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
std::vector<std::vector<std::string>> GameInfoComponent::searchForRecord(std::string file_name, std::string search_term, int numOfCols)
{	
	//first it reads all of the records
	std::vector<std::vector<std::string>> data = read(file_name, numOfCols);

	//then it searches for all that match the search term given
	std::vector<std::vector<std::string>> returned = searchMany(data,search_term);

	return returned;
}


//return many records 
std::vector<std::vector<std::string>> GameInfoComponent::searchMany(std::vector<std::vector<std::string>> records, std::string search_term)
{	
	std::vector<std::vector<std::string>> searchedRecords;
	for (int i = 0; i < records.size(); i++)
	{
		for (int j = 0; j < records[i].size(); j++)
		{
			if (records[i][j] == search_term)
			{
				searchedRecords.push_back(records[i]);
			}
		}
	}

	return searchedRecords;
}


/*
	std::vector<std::string> data = gm->readRecord(std::string file_name, std::string search_term);

	read the rows by indicating the index
	eg data[0]

*/
//modify this as well
std::vector<std::string> GameInfoComponent::searchRecord(std::string file_name, std::string search_term, int numOfcols)
{
	std::vector<std::string> record;
	std::ifstream file;
	file.open(file_name);
	bool found_record = false;

	std::string field_one;

	while (getline(file, field_one, ',') && !found_record)
	{	
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

		if (field_one == search_term)
		{	
			found_record = true;
			record = recordTest;
		}
	}

	file.close();
	return record;
}


/* first iteration of editing files*/
void GameInfoComponent::editRecord(std::string file_name, int editedCol,int numOfCols,std::string search_term, std::string newdata)
{
	//search for the record
	std::vector<std::string> data = searchRecord(file_name, search_term, numOfCols);

	//duplication happends here
	vector<std::vector<std::string>> allrecords = filterOutRecord(file_name, search_term, numOfCols);

	std::ofstream ofs(file_name);
	ofs.close();
	for (int i = 0; i < data.size(); i++)
	{
		if (i == editedCol)
		{
			data[i] = newdata;
		}
	}

	allrecords.push_back(data);

	for (int i = 0; i < allrecords.size(); i++)
	{
		writeRecord(file_name, allrecords[i]);
	}


	allrecords.clear();
	data.clear();

}


/* only works with 3 fields for now*/
// there is a duplicte record problem
vector<std::vector<std::string>> GameInfoComponent::filterOutRecord(std::string file_name, std::string search_term, int cols)
{
	vector<std::vector<std::string>> records;
	std::ifstream file;
	file.open(file_name);

	//std::string field_one;
	//std::string field_two;
	//std::string field_three;


	while (file.good())
	{	
		std::vector<std::string> oneRecord(cols);
		getline(file, oneRecord[0], ',');
		//I am sorry for uh, these if statements
		if (oneRecord[0] == search_term)
		{
			skip(file, 1.5, '\n');
		}
		if (oneRecord[0] == "")
		{
			skip(file, 1, '\n');
		}

		else if (oneRecord[0] != search_term)
		{

			for (int i = 1; i < cols; i++)
			{
				if (i == cols - 1)
				{
					getline(file, oneRecord[i], '\n'); //states the end of the record
				}
				else
				{
					getline(file, oneRecord[i], ','); //states the end of the record
				}
				oneRecord.push_back(oneRecord[i]);
			}

			//erase garbage data after specified cols
			oneRecord.erase(oneRecord.begin() + cols, oneRecord.end());
			records.push_back(oneRecord);
			oneRecord.clear();
		}
	}

	file.close();
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