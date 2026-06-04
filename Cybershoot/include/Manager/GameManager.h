#pragma once

class GameManager
{
private:
	float gameTime = 0.0f;
public:
	float GetGameTime() { return gameTime; }

	void Update(float deltaTime);
};