#include "ManagerLocator.h"

RenderManager* ManagerLocator::renderManager = nullptr;
ResourceManager* ManagerLocator::resourceManager = nullptr;
StateManager* ManagerLocator::stateManager = nullptr;
EnemyManager* ManagerLocator::enemyManager = nullptr;
BulletManager* ManagerLocator::bulletManager = nullptr;
GameManager* ManagerLocator::gameManager = nullptr;
UIManager* ManagerLocator::uiManager = nullptr;
PickupManager* ManagerLocator::pickupManager = nullptr;