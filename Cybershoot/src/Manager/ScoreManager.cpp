#include "Manager/ScoreManager.h"

#include <fstream>

ScoreManager::ScoreManager()
{
	LoadHighscore();
}

void ScoreManager::LoadHighscore()
{
	std::ifstream file(PATH, std::ios::binary);
	if (file.is_open())
	{
		file.read(reinterpret_cast<char*>(&highscore), sizeof(highscore));
	}
	else
	{
		highscore = 0;
	}
}

void ScoreManager::SaveHighscore(int score)
{
	if (score > highscore)
	{
		highscore = score;

		std::ofstream file(PATH, std::ios::binary);
		if (file.is_open())
		{
			file.write(reinterpret_cast<const char*>(&highscore), sizeof(highscore));
			file.close();
		}
	}
}