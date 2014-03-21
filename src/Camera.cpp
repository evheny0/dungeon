#include "Camera.h"

Camera::Camera()
{

}

Camera::~Camera()
{

}


void Camera::setDefault()
{
    window->setView(window->getDefaultView());
}

void Camera::reset(int x, int y, int width, int height)
{
    view.reset(sf::FloatRect(x, y, width, height));
    //view.zoom(3);
    //view.rotate(-30);
}

void Camera::rotate(int angle)
{
    view.rotate(angle);
}

void Camera::setViewport(int x, int y, int width, int height)
{
    view.setViewport(sf::FloatRect(x, y, width, height));
}

void Camera::apply()
{
    window->setView(view);
}

void Camera::move(int x, int y)
{
    view.move(x, y);
}

void Camera::setCenter(int x, int y)
{
    view.setCenter(x, y);
}
