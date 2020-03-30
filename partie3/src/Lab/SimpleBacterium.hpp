#ifndef SIMPLEBACTERIUM_HPP
#define SIMPLEBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    SimpleBacterium(Vec2d position);

    j::Value& getConfig() const;
    Bacterium* clone() const;
    void move(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow) const;
    void update(sf::Time dt);
    //void updateFlagelle(sf::Time) const;
    Vec2d f(Vec2d position, Vec2d speed) const;
    Vec2d getSpeedVector() const;
private:
    double t; //compteur pour le dessin du flagelle
};

#endif // SIMPLEBACTERIUM_HPP
