#include "Lab.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"
#include <iostream>
#include "Utility/Vec2d.hpp"

using namespace std;

Lab::Lab()
    : boite(getApp().getCentre(), 0.95*getApp().getLabSize().x/2.0)
{}

void Lab::drawOn(sf::RenderTarget &targetWindow) const
{
    boite.drawOn(targetWindow);
}

void Lab::update(sf::Time dt)
{
    boite.update(dt);
    automatique.update(dt); //nutrimentGenerator
}

void Lab::reset(){
    automatique.reset();
    boite.reset();
}

bool Lab::contains(const CircularBody& body) const {
    return boite.contains(body);
}

void Lab::addNutriment(Nutriment* n){
    if (!boite.addNutriment(n)) delete n;
}//si pas possible d'ajouter alors supprimé de la zone mémoire

//TEMPERATURE

double Lab::getTemperature() const {
    return boite.getTemperature();
}

void Lab::increaseTemperature(){
    boite.increaseTemperature();
}

void Lab::decreaseTemperature(){
    boite.decreaseTemperature();
}

void Lab::resetTemperature() {
    boite.resetTemperature();
};


void Lab::addBacterium(Bacterium *b)
{
    if (!boite.addBacterium(b)) delete b;
} //si pas possible d'ajouter alors supprimé de la zone mémoire


bool Lab::doesCollideWithDish(CircularBody const& body) const
{
    return (boite&body and !(boite>body));
}


Nutriment* Lab::getNutrimentColliding(CircularBody const& body)
{
    return boite.getNutrimentColliding(body);
}

double Lab::getPositionScore(const Vec2d& p) const
{
    return boite.getPositionScore(p);
}

//GRADIENT EXPONENT

double Lab::getGradientExponent() const
{
    return boite.getGradientExponent();
}

void Lab::increaseGradientExponent()
{
    return boite.increaseGradientExponent();
}

void Lab::decreaseGradientExponent()
{
    return boite.decreaseGradientExponent();
}

void Lab::resetGradientExponent()
{
    boite.resetGradientExponent();
}

void Lab::resetControls()
{
    resetTemperature();
    resetGradientExponent();
}




Swarm* Lab::getSwarmWithId(string id)
{
    return boite.getSwarmWithId(id);
}

void Lab::addSwarm(Swarm *s)
{
    boite.addSwarm(s);
}









