#include "SwarmBacterium.hpp"
#include "../Application.hpp"
#include "Random/Random.hpp"
#include "Utility/Utility.hpp"
#include "Swarm.hpp"
#include <iostream>

using namespace std;

SwarmBacterium::SwarmBacterium(Vec2d position, Swarm* grp)
    : Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()), position,
                Vec2d::fromRandomAngle(), uniform(getConfig()["radius"]["min"].toDouble(), getConfig()["radius"]["max"].toDouble()),
                grp->getOriginalColor()),
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
{    //déplacement
    DiffEqResult resultat(stepDiffEq(getPosition(), getSpeedVector(), dt, *this));
    Vec2d deplacement(resultat.position - getPosition());
    if(deplacement.lengthSquared() > 0.01){ //empêche tremblotements
        this->CircularBody::move(deplacement);
        consumeEnergy(getConsumption()*deplacement.length());
        //setDirection(resultat.speed.normalised());
    }
    if (getPosition() == groupe->getPositionLeader()) newDirection();
}

Bacterium* SwarmBacterium::clone() const
{
    return new SwarmBacterium(*this);
}

Vec2d SwarmBacterium::f(Vec2d position, Vec2d speed) const
{
    double coeffForce(getAppConfig()["swarms"][groupe->getIdentificator()]["force factor"].toDouble());
    return (coeffForce*(groupe->getPositionLeader()-position));
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

Vec2d SwarmBacterium::getSpeedVector() const
{
    return getDirection().normalised()*getConfig()["speed"]["initial"].toDouble();
}
