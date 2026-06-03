#include "GameState.h"

#include "StateManager.h"
#include "MainMenuState.h"
#include "ManagerLocator.h"
#include "RenderManager.h"
#include "Camera.h"
#include "GameTypes.h"

GameState::GameState()
{
	Initialize();

	player.SetWeapon(WeaponType::Rifle);
}

void GameState::Initialize()
{
	ManagerLocator::SetEnemyManager(&enemyManager);
	ManagerLocator::SetBulletManager(&bulletManager);
	ManagerLocator::SetGameManager(&gameManager);
	ManagerLocator::SetUIManager(&uiManager);
	ManagerLocator::SetPickupManager(&pickupManager);
}

void GameState::HandleInput(sf::Event& event, sf::RenderWindow& window)
{
	switch (event.type)
		{
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				ManagerLocator::GetStateManager().ChangeState(std::make_unique<MainMenuState>());
			}
			else if (event.key.code == sf::Keyboard::R)
			{
				player.GetWeapon().Reload();
			}
			break;
		}
		case sf::Event::MouseButtonPressed:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				player.GetWeapon().StartFiring();
			}
			break;
		}
		case sf::Event::MouseButtonReleased:
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				player.GetWeapon().StopFiring();
			}
			break;
		}
	}
}

void GameState::Update(float deltaTime)
{
	player.Update(deltaTime);
	if (player.HasWeapon()) player.GetWeapon().Update(deltaTime);
	tileManager.Update();
	bulletManager.Update(deltaTime);
	enemyManager.Update(deltaTime);
	pickupManager.Update();
	collisionManager.Update();
	gameManager.Update(deltaTime);
	spawnManager.Update(deltaTime);
	ManagerLocator::GetRenderManager().GetCamera().Update(player.GetPosition());
}
void GameState::Render(sf::RenderWindow& window)
{
	window.setView(ManagerLocator::GetRenderManager().GetCamera().GetView());
	window.draw(tileManager);
	window.draw(pickupManager);
	window.draw(player);
	window.draw(bulletManager);
	window.draw(player.GetWeapon());
	window.draw(enemyManager);
	window.setView(window.getDefaultView());
	window.draw(uiManager);
}