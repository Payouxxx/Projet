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
    //move(dt);
}

void Lampe::move(sf::Time dt)
{
    if(getAppEnv().doesCollideWithDish(*this)){
        Vec2d dir(getPosition().fromRandomAngle());
        for(int i(0); i<20; ++i){
            Vec2d dir2(getPosition().fromRandomAngle());
            if(distance(dir2, getApp().getCentre()) < distance(dir, getApp().getCentre())){
                dir = dir2;
            }
        }
        direction = dir;
    }
    CircularBody::move(direction.normalised()*getConfig()["speed"].toDouble());
}
void Lampe::setState(bool state)
{
    ON = state;
}
