#include "Lampe.hpp"
#include "../Application.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Constants.hpp"
#include "Utility/Utility.hpp"
#include <iostream>

using namespace std;

Lampe::Lampe(Vec2d centre, double rayon)
    : CircularBody(centre, rayon),
      color(229, 232, 114, 120),
      ON(false),
      direction(Vec2d::fromRandomAngle())
{}

j::Value const& Lampe::getConfig()
{
    return getAppConfig()["Lampe"];
}

void Lampe::drawOn(sf::RenderTarget &target) const
{
    auto const circle = buildCircle(getPosition(), getRadius(), color);
    target.draw(circle);
}

bool Lampe::isOn() const
{
    return ON;
}

void Lampe::update(sf::Time dt)
{
    move(dt);
}

void Lampe::move(sf::Time dt)
{
    if(getAppEnv().doesCollideWithDish(*this)){
        Vec2d dir(Vec2d::fromRandomAngle().normalised());
        while (!(getAppEnv().contains(getPosition() + dir))){
            dir = Vec2d::fromRandomAngle().normalised();
        }
        direction = dir;
    }
    CircularBody::move(direction*getConfig()["speed"].toDouble());
}
void Lampe::setState(bool state)
{
    ON = state;
}

void Lampe::reset()
{
    ON = false;
    setPosition(getApp().getCentre());
}
