#pragma once

#include <string>

class ScoreManager
{
private:
	const std::string PATH = "saves/highscore.dat";

	int highscore = 0;
	void LoadHighscore();
public:
	ScoreManager();

	int GetHighscore() { return highscore; }
	void SaveHighscore(int score);
	bool HasHighscore() { return highscore > 0; }
};