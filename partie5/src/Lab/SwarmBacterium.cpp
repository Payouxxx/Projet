#include "SwarmBacterium.hpp"
#include "../Application.hpp"
#include "Random/Random.hpp"
#include "Utility/Utility.hpp"
#include "Swarm.hpp"
#include <iostream>
#include "Nutriment.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"

using namespace std;

SwarmBacterium::SwarmBacterium(Vec2d position, Swarm* grp) //uniform fait automatiquement entre min et max
    : Bacterium(uniform(getConfig()["energy"]), position,
                Vec2d::fromRandomAngle(), uniform(getConfig()["radius"]),
                grp->getOriginalColor()),
      groupe(grp)
{
    groupe->addSwarmBacterium(this);
    //pas de caractéristiques mutables autre que couleur
}

SwarmBacterium::SwarmBacterium(const SwarmBacterium &other)
    : Bacterium(other), groupe(other.groupe)
{
    groupe->addSwarmBacterium(this);
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
        setDirection(resultat.speed.normalised());
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
    if(isDebugOn() and groupe->getPositionLeader()==getPosition()) {
        auto border = buildAnnulus(getPosition(), getRadius()+5, sf::Color::Red, 3);
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


Quantity SwarmBacterium::eatableQuantity(NutrimentB& nutriment)
{
    return nutriment.eatenBy(*this);
}

Quantity SwarmBacterium::eatableQuantity(NutrimentA& nutriment)
{
    return nutriment.eatenBy(*this);
}

Quantity SwarmBacterium::getMaxEatableQuantity() const
{
    return (getConfig()["meal"]["max"].toDouble());
}
