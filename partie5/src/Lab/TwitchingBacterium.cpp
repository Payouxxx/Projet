#include "TwitchingBacterium.hpp"
#include "Application.hpp"
#include "JSON/JSONImpl.hpp"
#include "Random/Random.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Utility.hpp"
#include "Utility/Vec2d.hpp"
#include <iostream>
#include "Nutriment.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"

using namespace std;

TwitchingBacterium::TwitchingBacterium(Vec2d position)
    : Bacterium(uniform(getConfig()["energy"]), position,
      Vec2d::fromRandomAngle(), uniform(getConfig()["radius"]),
      getConfig()["color"]),
      grapin(position, getRadius()/4.0), //grapin initialisé à la même position mais avec un rayon 4 fois plus petit
      state(IDLE)
{
    addProperty("speed", MutableNumber::positive(getConfig()["tentacle"]["speed"]));
    addProperty("length tentacle", MutableNumber::positive(getConfig()["tentacle"]["length"]));
}

//getters

j::Value& TwitchingBacterium::getConfig() const
{
    return (getAppConfig()["twitching bacterium"]);
}

double TwitchingBacterium::getEnergieMove() const
{
    return (getConfig()["energy"]["consumption factor"]["move"].toDouble());
}

double TwitchingBacterium::getEnergieTentacle() const
{
    return (getConfig()["energy"]["consumption factor"]["tentacle"].toDouble());
}

Bacterium* TwitchingBacterium::clone() const
{
    TwitchingBacterium* c(new TwitchingBacterium(*this));
    c->grapin.~Grip();
    c->setPosition(Vec2d(getPosition().x +20,getPosition().y -20));
    return c;
}

void TwitchingBacterium::drawTentacle(sf::RenderTarget &targetWindow) const
{
    auto line = buildLine(grapin.getPosition(), this->getPosition(), getColor(), 1);
    targetWindow.draw(line);
    auto border = buildAnnulus(grapin.getPosition(), grapin.getRadius(), getColor(), 1);
    targetWindow.draw(border);
}

void TwitchingBacterium::drawOn(sf::RenderTarget &targetWindow) const
{
    drawTentacle(targetWindow);
    Bacterium::drawOn(targetWindow);

}

void TwitchingBacterium::moveGrip(Vec2d add)
{
    grapin.move(add);
}

void TwitchingBacterium::move(sf::Time dt)
{
    double vitesse_tentacule(getConfig()["tentacle"]["speed"]["initial"].toDouble());
    switch (state) {
        case IDLE: //tentacule au repos
            state = WAIT_TO_DEPLOY;
        break;
        case WAIT_TO_DEPLOY: //tentacule se préparant au deploiement
        newDirection();
        state = DEPLOY;
        break;

        case DEPLOY:
        //mouvement du grapin
        if(distance(grapin.getPosition(),getPosition()) < getConfig()["tentacle"]["length"]["initial"].toDouble()
                and not getAppEnv().doesCollideWithDish(grapin)){
            grapin.move(getDirection() * vitesse_tentacule * dt.asSeconds());

            //perte d'énergie
            consumeEnergy(getEnergieTentacle() * vitesse_tentacule * dt.asSeconds());

            //rencontre nutriment
            if(getAppEnv().getNutrimentColliding(grapin) != nullptr){
                state = ATTRACT;
            }
        } else {
            state = RETRACT;
            }
        break;

        case ATTRACT:
        if(getAppEnv().getNutrimentColliding(*this) != nullptr){
            state = EAT;
        } else if(getAppEnv().getNutrimentColliding(*this) == nullptr and getAppEnv().getNutrimentColliding(grapin) != nullptr){
            Vec2d dir_tentacule((grapin.getPosition() - getPosition()).normalised());
            this->CircularBody::move(dir_tentacule* vitesse_tentacule * getEnergieMove() * dt.asSeconds());
            consumeEnergy(getEnergieMove()*vitesse_tentacule * getEnergieMove() * dt.asSeconds());
        } else {
            state = RETRACT;
        }
        break;

        case RETRACT:
        if(distance(getPosition(), grapin.getPosition()) <= getRadius()){
            state = IDLE;
        } else {
            grapin.move((getPosition() - grapin.getPosition()).normalised());
            consumeEnergy(getEnergieTentacle() * vitesse_tentacule * dt.asSeconds());
        }
        break;

        case EAT:
            if(getAppEnv().getNutrimentColliding(*this) == nullptr){
                state = IDLE;
            }
        break;

        default:
            break;

    }
}


Quantity TwitchingBacterium::eatableQuantity(NutrimentB& nutriment)
{
    return nutriment.eatenBy(*this);
}

Quantity TwitchingBacterium::eatableQuantity(NutrimentA& nutriment)
{
    return nutriment.eatenBy(*this);
}

Quantity TwitchingBacterium::getMaxEatableQuantity() const
{
    return (getConfig()["meal"]["max"].toDouble());
}
