#include "Poison.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Utility.hpp"

Poison::Poison(Vec2d centre, double rayon, Vec2d dir)
    : CircularBody(centre, rayon), color(233, 21, 218), direction(dir)
{}

void Poison::drawOn(sf::RenderTarget &target) const
{
    auto const circle = buildCircle(getPosition(), getRadius(), color);
    target.draw(circle);
}

void Poison::move()
{

}
