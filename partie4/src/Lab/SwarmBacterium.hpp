#ifndef SWARMBACTERIUM_HPP
#define SWARMBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class Swarm;

class SwarmBacterium : public Bacterium, public DiffEqFunction
{
public:
    SwarmBacterium(Vec2d position, Swarm* grp);
    ~SwarmBacterium();

    j::Value& getConfig() const;
    void move(sf::Time dt);
    Bacterium* clone() const;
    Vec2d f(Vec2d position, Vec2d speed) const;
    void drawOn(sf::RenderTarget &targetWindow) const;

private:
    Swarm* groupe;
};

#endif // SWARMBACTERIUM_HPP
