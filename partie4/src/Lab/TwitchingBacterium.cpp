#include "TwitchingBacterium.hpp"
#include "Application.hpp"
#include "JSON/JSONImpl.hpp"
#include "Random/Random.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Utility.hpp"
#include "Utility/Vec2d.hpp"
#include <iostream>

using namespace std;

TwitchingBacterium::TwitchingBacterium(Vec2d position)
    : Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()), position,
      Vec2d::fromRandomAngle(), uniform(getConfig()["radius"]["min"].toDouble(), getConfig()["radius"]["max"].toDouble()),
      getConfig()["color"]),
      grapin(position, getRadius()/4.0) //grapin initialisé à la même position mais avec un rayon 4 fois plus petit
{
    addProperty("speed", MutableNumber::positive(getConfig()["tentacle"]["speed"]));
    addProperty("length tentacle", MutableNumber::positive(getConfig()["tentacle"]["length"]));
}

TwitchingBacterium::TwitchingBacterium(TwitchingBacterium &other)
    : TwitchingBacterium(other.getPosition())
{}

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
    TwitchingBacterium* c(new TwitchingBacterium(this->getPosition()));
    c->grapin.~Grip();
    c->setPosition(Vec2d(getPosition().x +20,getPosition().y -20));
    return c;
}

void TwitchingBacterium::drawTentacle(sf::RenderTarget &targetWindow) const
{
    auto line = buildLine(grapin.getPosition(), this->getPosition(), sf::Color::Red, 1);
    targetWindow.draw(line);
    auto border = buildAnnulus(grapin.getPosition(), grapin.getRadius(), sf::Color::Red, 1);
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
    enum etat {IDLE, WAIT_TO_DEPLOY, DEPLOY, ATTRACT, RETRACT, EAT};
    etat state(IDLE);
    double vitesse_tentacule(getConfig()["tentacle"]["speed"]["initial"].toDouble());
    switch (state) {
        case IDLE: //tentacule au repos
            state = WAIT_TO_DEPLOY;
        case WAIT_TO_DEPLOY: //tentacule se préparant au deploiement
    {
        Vec2d dir(Vec2d::fromRandomAngle());
        for(int i(0); i<20; ++i){
            Vec2d dir2(Vec2d::fromRandomAngle());
            if(getAppEnv().getPositionScore(dir+getPosition()) < getAppEnv().getPositionScore(dir2+getPosition())){
                dir = dir2;
            }
        }
        this->getDirection() = dir;
        state = DEPLOY;
    }
        case DEPLOY:
    {
        //mouvement du grapin
        grapin.move(getPosition() * vitesse_tentacule * dt.asSeconds());

        //perte d'énergie
        consumeEnergy(getEnergieTentacle() * vitesse_tentacule * dt.asSeconds());

        //rencontre nutriment
        Nutriment* n(getAppEnv().getNutrimentColliding(grapin));
        if(n != nullptr){
            state = ATTRACT;
        } else {
            state = RETRACT;
        }
    }

        case ATTRACT:
    {
        if(getAppEnv().getNutrimentColliding(*this) != nullptr){
            state = EAT;
        } else {
            Vec2d dir_tentacule((grapin.getPosition() - getPosition()).normalised());
            CircularBody::move(dir_tentacule* vitesse_tentacule * getEnergieMove() * dt.asSeconds());
        }
    }
        case RETRACT:
    {
        if(distance(getPosition(), grapin.getPosition()) <= getRadius()){
            state = IDLE;
        } else {
            grapin.move((getPosition() - grapin.getPosition()).normalised());
            consumeEnergy(getEnergieTentacle() * vitesse_tentacule * dt.asSeconds());
        }
    }

        case EAT:
            if(getAppEnv().getNutrimentColliding(*this) == nullptr) state = IDLE;

        default:
            break;
   }

}


