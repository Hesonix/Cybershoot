#pragma once

class RenderManager;
class ResourceManager;
class StateManager;
class ScoreManager;
class EnemyManager;
class BulletManager;
class PickupManager;
class UIManager;
class GameManager;

class ManagerLocator
{
private:
	static RenderManager* renderManager;
	static ResourceManager* resourceManager;
	static StateManager* stateManager;
	static ScoreManager* scoreManager;
	static EnemyManager* enemyManager;
	static BulletManager* bulletManager;
	static PickupManager* pickupManager;
	static UIManager* uiManager;
	static GameManager* gameManager;
public:
	static void SetRenderManager(RenderManager* manager) { renderManager = manager; }
	static void SetResourceManager(ResourceManager* manager) { resourceManager = manager; }
	static void SetStateManager(StateManager* manager) { stateManager = manager; }
	static void SetScoreManager(ScoreManager* manager) { scoreManager = manager; }
	static void SetEnemyManager(EnemyManager* manager) { enemyManager = manager; }
	static void SetBulletManager(BulletManager* manager) { bulletManager = manager; }
	static void SetPickupManager(PickupManager* manager) { pickupManager = manager; }
	static void SetUIManager(UIManager* manager) { uiManager = manager; }
	static void SetGameManager(GameManager* manager) { gameManager = manager; }
	
	static RenderManager& GetRenderManager() { return *renderManager; }
	static ResourceManager& GetResourceManager() { return *resourceManager; }
	static StateManager& GetStateManager() { return *stateManager; }
	static ScoreManager& GetScoreManager() { return *scoreManager; }
	static EnemyManager& GetEnemyManager() { return *enemyManager; }
	static BulletManager& GetBulletManager() { return *bulletManager; }
	static PickupManager& GetPickupManager() { return *pickupManager; }
	static UIManager& GetUIManager() { return *uiManager; }
	static GameManager& GetGameManager() { return *gameManager; }
};