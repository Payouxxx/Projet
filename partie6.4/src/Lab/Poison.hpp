#ifndef POISON_HPP
#define POISON_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"

class Poison : public CircularBody, public Drawable
{
public:
    Poison(Vec2d centre, double rayon, Vec2d dir);

    void drawOn(sf::RenderTarget& target) const override;

    ~Poison();

    void move();

private:
    sf::Color color;
    Vec2d direction;
};

#endif // POISON_HPP
