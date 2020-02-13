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

void GameInfoComponent::writeRecord(std::string file_name, std::string field_one, std::string field_two, std::string field_three)
{
	std::ofstream file;
	file.open(file_name, std::ios_base::app);
	file << field_one << "," << field_two << "," << field_three << std::endl;
}

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