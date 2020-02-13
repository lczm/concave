#include "gameInfoComponent.h"

GameInfoComponent::GameInfoComponent()
{

}

void GameInfoComponent::read()
{
	ifstream fout("text\\gameInfo.csv");;
	std::string level, 
	noEnemies, 
	completed, 
	chests,
	levelName;

	while (fout.peek()!= EOF)
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
	return record;
}