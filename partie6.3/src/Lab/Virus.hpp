#ifndef VIRUS_HPP
#define VIRUS_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include <SFML/Graphics.hpp>

class Virus : public CircularBody, public Drawable, public Updatable
{
public:
    Virus(Vec2d centre, double rayon);
    ~Virus();
    void drawOn(sf::RenderTarget &target) const override;
    void update(sf::Time dt) override;
    void move(sf::Time dt);
    j::Value const& getConfig() const;
    bool isDead() const;
    void infection();

private:
    sf::Time tempsVie;
    bool dead;
    Vec2d direction;
};

#endif // VIRUS_HPP
