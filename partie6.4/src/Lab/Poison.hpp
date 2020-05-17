#ifndef POISON_HPP
#define POISON_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"

class Poison : public CircularBody, public Drawable, public Updatable
{
public:
    Poison(Vec2d centre, double rayon, Vec2d dir, std::string id);

    void drawOn(sf::RenderTarget& target) const override;

    ~Poison();

    void move();

    void update(sf::Time dt);

    bool isVanished() const;

    void setVanished(bool b);

    std::string getId() const;
private:
    sf::Color color;
    Vec2d direction;
    bool vanished;
    std::string identificateur;
};

#endif // POISON_HPP
