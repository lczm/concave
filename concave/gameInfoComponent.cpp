#include "gameInfoComponent.h"

GameInfoComponent::GameInfoComponent()
{

}

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

void GameInfoComponent::writeRecord(std::string file_name, std::vector<std::string> record)
{

	std::ofstream file;
	file.open(file_name, std::ios_base::app);

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
	std::cout << record[0] << " " << record[1] << " " << record[2];
	file.close();
	return record;
}


/* first iteration of editing files*/
void GameInfoComponent::appendRecord(std::string file_name, int col, std::string search_term, std::string newdata)
{
	//search for the record

	std::vector<std::string> data = readRecord(file_name, search_term);
	vector<std::vector<std::string>> allrecords = filterOutRecord(file_name, search_term);
	for (int i = 0; i < data.size(); i++)
	{
		if (i == col)
		{
			data[i] = newdata;
		}
	}

	allrecords.push_back(data);

	ifstream fout("text\\gameInfo.csv", std::ofstream::out | std::ofstream::trunc);
	for (int i = 0; i < allrecords.size(); i++)
	{
		writeRecord(file_name, allrecords[i]);
	}
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


	while (!file.eof())
	{
			getline(file, field_one, ',');
			getline(file, field_two, ',');
			getline(file, field_three, '\n'); //states the end of the record
			if (field_one != search_term)
			{
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