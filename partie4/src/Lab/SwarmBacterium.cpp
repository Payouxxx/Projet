#include "SwarmBacterium.hpp"
#include "../Application.hpp"
#include "Random/Random.hpp"
#include "Utility/Utility.hpp"
#include "Swarm.hpp"

SwarmBacterium::SwarmBacterium(Vec2d position, Swarm* grp)
    : Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()), position,
                Vec2d::fromRandomAngle(), uniform(getConfig()["radius"]["min"].toDouble(), getConfig()["radius"]["max"].toDouble()),
                getConfig()["color"]),
      groupe(grp)
{
    groupe->addSwarmBacterium(this);
    //pas de caractéristiques mutables autre que couleur
}

j::Value& SwarmBacterium::getConfig() const
{
    return (getAppConfig()["swarm bacterium"]);
}

void SwarmBacterium::move(sf::Time dt)
{

}

Bacterium* SwarmBacterium::clone() const
{
    return new SwarmBacterium(*this);
}

Vec2d SwarmBacterium::f(Vec2d position, Vec2d speed) const
{
    //DiffEqResult resultat (stepDiffEq(position, speed, dt, this));
}

void SwarmBacterium::drawOn(sf::RenderTarget &targetWindow) const
{
    if(getPosition() == groupe->getPositionLeader() and isDebugOn()) {
        auto border = buildAnnulus(getPosition(), getRadius(), sf::Color::Red, 5);
        targetWindow.draw(border);
    }

    Bacterium::drawOn(targetWindow);
}

SwarmBacterium::~SwarmBacterium()
{
    groupe->removeSwarmBacterium(this);
}
