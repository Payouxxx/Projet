#ifndef SIMPLEBACTERIUM_HPP
#define SIMPLEBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    SimpleBacterium(Vec2d position);
    ~SimpleBacterium();

    j::Value& getConfig() const;
    Bacterium* clone() const;
    void move(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow) const;
    void update(sf::Time dt);
    Vec2d f(Vec2d position, Vec2d speed) const;

    void drawFlagelle(sf::RenderTarget& targetWindow) const;
    void updateFlagelle(sf::Time dt);
    Vec2d getSpeedVector() const;

    void basculement();

private:
    double t; //compteur pour le dessin du flagelle
    sf::Time dt; //compteur entre 2 basculements
};

#endif // SIMPLEBACTERIUM_HPP
