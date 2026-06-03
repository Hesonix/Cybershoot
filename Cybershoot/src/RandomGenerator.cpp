#include "RandomGenerator.h"
#include <chrono>

std::mt19937 RandomGenerator::engine;
bool RandomGenerator::isInitialized = false;

void RandomGenerator::Initialize()
{
	if (!isInitialized)
	{
		unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
		engine.seed(seed);
		isInitialized = true;
	}
}

int RandomGenerator::GetInt(int min, int max)
{
	Initialize();
	std::uniform_int_distribution<int> dist(min, max);
	return dist(engine);
}

float RandomGenerator::GetFloat(float min, float max)
{
	Initialize();
	std::uniform_real_distribution<float> dist(min, max);
	return dist(engine);
}