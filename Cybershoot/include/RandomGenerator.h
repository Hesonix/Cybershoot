#pragma once

#include <random>
#include <vector>

class RandomGenerator
{
private:
	static void Initialize();

	static std::mt19937 engine;
	static bool isInitialized;
public:
	static int GetInt(int min, int max);
	static float GetFloat(float min, float max);
	template<typename T>
	static int GetIndex(const std::vector<T>& vec)
	{
		if (vec.empty()) return -1;
		return GetInt(0, static_cast<int>(vec.size()) - 1);
	}
};