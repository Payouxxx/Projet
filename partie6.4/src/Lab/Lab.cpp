#include "Lab.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"
#include <iostream>
#include "Utility/Vec2d.hpp"

using namespace std;

Lab::Lab()
    : boite(getApp().getCentre(), 0.95*getApp().getLabSize().x/2.0),
      lampe(getApp().getCentre(), 0.2*getApp().getLabSize().x/2.0)
{}

void Lab::drawOn(sf::RenderTarget &targetWindow) const
{
    boite.drawOn(targetWindow);
    if (lampe.isOn()) lampe.drawOn(targetWindow);
}

void Lab::update(sf::Time dt)
{
    boite.update(dt);
    automatique.update(dt); //nutrimentGenerator
    time += dt.asSeconds();
    if (lightOn()) lampe.update(dt);
}

void Lab::reset(){
    automatique.reset();
    boite.reset();
    resetControls();
}

bool Lab::contains(const CircularBody& body) const {
    return boite.contains(body);
}

bool Lab::contains(const Vec2d &point) const
{
    return boite.contains(point);
}

void Lab::addNutriment(Nutriment* n){
    if (!boite.addNutriment(n)) {
        delete n;
        n = nullptr;
    }
}//si pas possible d'ajouter alors supprimé de la zone mémoire

void Lab::addSwarm(Swarm *s)
{
    boite.addSwarm(s);
}

void Lab::addADN(ADN *a){
    if (!boite.addADN(a)) {
        delete a;
        a = nullptr;
    }
}

void Lab::addVirus(Virus* v){
    if (!boite.addVirus(v)) {
        delete v;
        v = nullptr;
    }
}

void Lab::addPoison(Poison *p){
    if (!boite.addPoison(p)) {
        delete p;
        p = nullptr;
    }
}

void Lab::addBacterium(Bacterium *b)
{
    if (!boite.addBacterium(b)) {
        delete b;
    }
} //si pas possible d'ajouter alors supprimé de la zone mémoire

bool Lab::lightOn() const
{
    return lampe.isOn();
}

void Lab::setState(bool onOff)
{
    lampe.setState(onOff);
}

bool Lab::doesCollideWithLight(const CircularBody &body) const
{
    return (lampe.contains(body));
}

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
}

bool Lab::doesCollideWithDish(CircularBody const& body) const
{
    return (boite&body and !(boite>body));
}

Nutriment* Lab::getNutrimentColliding(CircularBody const& body) const
{
    return boite.getNutrimentColliding(body);
}

ADN* Lab::getADNColliding(const CircularBody &body) const
{
    return boite.getADNcolliding(body);
}

Bacterium* Lab::getBacteriumColliding(const CircularBody &body) const
{
    return boite.getBacteriumColliding(body);
}

Poison* Lab::getPoisonColliding(const CircularBody &body) const
{
    return boite.getPoisonColliding(body);
}

double Lab::getPositionScore(const Vec2d& p) const
{
    return boite.getPositionScore(p);
}

double Lab::getPositionBact(const Vec2d &p) const
{
    return boite.getPositionBact(p);
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
    resetTime();
    resetLight();
}

Swarm* Lab::getSwarmWithId(string id)
{
    return boite.getSwarmWithId(id);
}

unordered_map<string, double> Lab::fetchData(const string & name) const
{
    return boite.fetchData(name);
}

double Lab::getTime() const
{
    return time;
}

void Lab::resetTime()
{
    time = 0;
}

void Lab::resetLight()
{
    lampe.reset();
}
