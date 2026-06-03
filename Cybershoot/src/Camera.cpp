#include "Camera.h"
#include "WindowSettings.h"
#include "Lerp.h"

Camera::Camera()
{
	view.setCenter(0.0f, 0.0f);
	view.setSize(WindowSettings::WIDTH, WindowSettings::HEIGHT);
}

void Camera::Update(sf::Vector2f newPosition)
{
	sf::Vector2f newCenter = Lerp(view.getCenter(), newPosition, SMOOTH_SPEED);

	view.setCenter(newCenter);
}