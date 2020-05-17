#include "Poison.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Utility.hpp"
#include "../Application.hpp"

Poison::Poison(Vec2d centre, double rayon, Vec2d dir, std::string id)
    : CircularBody(centre, rayon), color(210, 21, 230), direction(dir), vanished(false), identificateur(id)
{}

void Poison::drawOn(sf::RenderTarget &target) const
{
    auto const circle = buildCircle(getPosition(), getRadius(), color);
    target.draw(circle);
}

void Poison::move()
{
    if(getAppEnv().doesCollideWithDish(*this)){
        vanished = true;
    }
    CircularBody::move(direction);
}

Poison::~Poison()
{}

void Poison::update(sf::Time dt)
{
    move();
}

bool Poison::isVanished() const
{
    return vanished;
}

void Poison::setVanished(bool b)
{
    vanished = b;
}

std::string Poison::getId() const
{
    return identificateur;
}
