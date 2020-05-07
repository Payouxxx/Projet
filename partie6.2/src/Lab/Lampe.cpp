#include "Lampe.hpp"
#include "../Application.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Constants.hpp"
#include "Utility/Utility.hpp"

Lampe::Lampe(Vec2d centre, double rayon)
    : CircularBody(centre, rayon),
      color(getConfig()["color"]),
      ON(false),
      direction(Vec2d::fromAngle(rayon))
{}

j::Value const& Lampe::getConfig() const
{
    return getAppConfig()["Lampe"];
}

void Lampe::drawOn(sf::RenderTarget &target) const
{
    auto const circle = buildCircle(getPosition(), getRadius(), color.get());
    target.draw(circle);
}

bool Lampe::isOn() const
{
    return ON;
}

void Lampe::update(sf::Time dt)
{
    move();

}

void Lampe::move()
{
    if(getAppEnv().doesCollideWithDish(*this)){
        direction = Vec2d::fromRandomAngle(PI);
    }
    CircularBody::move(getPosition()+(direction.normalised())*getConfig()["speed"].toDouble());
}
void Lampe::setState(bool state)
{
    ON = state;
}
