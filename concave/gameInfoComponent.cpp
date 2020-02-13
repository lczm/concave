#include "gameInfoComponent.h"

GameInfoComponent::GameInfoComponent()
{

}
/*
void GameInfoComponent::read()
{
	ifstream fout("text\\gameInfo.csv", std::ofstream::out | std::ofstream::trunc);;
	std::string level,
		noEnemies,
		completed,
		chests,
		levelName;

	while (fout.peek() != EOF)
	{
		getline(fout, level, ',');
		getline(fout, noEnemies, ',');
		getline(fout, completed, ',');

	}

	fout.close();
}
*/

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

/*
	std::vector<std::string> data = gm->readRecord(std::string file_name, std::string search_term);

	read the rows by indicating the index
	eg data[0]

*/

//modify this as well
std::vector<std::string> GameInfoComponent::readRecord(std::string file_name, std::string search_term)
{
	std::vector<std::string> record;

	std::ifstream file;
	file.open(file_name);

	bool found_record = false;

	std::string field_one;
	std::string field_two;
	std::string field_three;

	while (getline(file, field_one, ',') && !found_record)
	{
		getline(file, field_two, ',');
		getline(file, field_three, '\n'); //states the end of the record
		if (field_one == search_term)
		{
			found_record = true;
			record.push_back(field_one);
			record.push_back(field_two);
			record.push_back(field_three);
		}
	}
	file.close();
	return record;
}


/* first iteration of editing files*/
void GameInfoComponent::appendRecord(std::string file_name, int col, std::string search_term, std::string newdata)
{
	//search for the record
	std::vector<std::string> data = readRecord(file_name, search_term);

	//duplication happends here
	vector<std::vector<std::string>> allrecords = filterOutRecord(file_name, search_term);

	std::ofstream ofs("text\\gameInfo.csv");
	ofs.close();
	for (int i = 0; i < data.size(); i++)
	{
		if (i == col)
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
vector<std::vector<std::string>> GameInfoComponent::filterOutRecord(std::string file_name, std::string search_term)
{
	vector<std::vector<std::string>> records;
	std::vector<std::string> oneRecord;
	std::ifstream file;
	file.open(file_name);


	std::string field_one;
	std::string field_two;
	std::string field_three;

	
	while (file.good())
	{		
			
			getline(file, field_one, ',');
			if (field_one == search_term)
			{
				skip(file, 1, '\n');
			}

			else if (field_one != search_term)
			{
				getline(file, field_two, ',');
				getline(file, field_three, '\n'); //states the end of the record

				oneRecord.push_back(field_one);
				oneRecord.push_back(field_two);
				oneRecord.push_back(field_three);

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