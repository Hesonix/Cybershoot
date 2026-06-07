#include "Manager/GameManager.h"

#include "Player.h"
#include "ManagerLocator.h"
#include "Manager/UIManager.h"
#include "Manager/StateManager.h"
#include "State/GameOverState.h"

void GameManager::Update(float deltaTime)
{
	if (Player::GetInstance().IsAlive())
	{
		gameTime += deltaTime;
		ManagerLocator::GetUIManager().UpdateGameTimeText(gameTime);
	}
	else
	{
		ManagerLocator::GetStateManager().PushState(std::make_unique<GameOverState>());
	}
}