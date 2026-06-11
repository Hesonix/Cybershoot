#include "Camera.h"

#include "ManagerLocator.h"
#include "Manager/RenderManager.h"
#include "Util/Lerp.h"

Camera::Camera()
{
	view.setCenter(0.0f, 0.0f);
	view.setSize(WindowSettings::WIDTH, WindowSettings::HEIGHT);
}

void Camera::SetPosition(sf::Vector2f position)
{
	view.setCenter(position);
}

void Camera::Update(sf::Vector2f playerPosition)
{
	sf::Vector2f mouseWorldPosition = ManagerLocator::GetRenderManager().GetMouseWorldPosition();
	
	sf::Vector2f mouseOffsetFromPlayer = mouseWorldPosition - playerPosition;

	if (mouseOffsetFromPlayer.x > DEADZONE_X)
		mouseOffsetFromPlayer.x = DEADZONE_X;
	else if (mouseOffsetFromPlayer.x < -DEADZONE_X)
		mouseOffsetFromPlayer.x = -DEADZONE_X;

	if (mouseOffsetFromPlayer.y > DEADZONE_Y)
		mouseOffsetFromPlayer.y = DEADZONE_Y;
	else if (mouseOffsetFromPlayer.y < -DEADZONE_Y)
		mouseOffsetFromPlayer.y = -DEADZONE_Y;

	sf::Vector2f targetPosition = playerPosition + mouseOffsetFromPlayer;

	sf::Vector2f newCenter = Lerp(view.getCenter(), targetPosition, SMOOTH_SPEED);

	view.setCenter(newCenter);
}