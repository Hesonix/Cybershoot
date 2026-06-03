#include "GameManager.h"

#include "ManagerLocator.h"
#include "UIManager.h"

void GameManager::Update(float deltaTime)
{
    gameTime += deltaTime;
	ManagerLocator::GetUIManager().UpdateGameTimeText(gameTime);
}