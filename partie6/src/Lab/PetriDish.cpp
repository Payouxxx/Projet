#include "PetriDish.hpp"
#include "../Utility/Utility.hpp"
#include "Nutriment.hpp"
#include "../Application.hpp"
#include "JSON/JSONImpl.hpp"
#include <iostream>
#include <cmath>
#include "SimpleBacterium.hpp"
#include "SwarmBacterium.hpp"
#include "TwitchingBacterium.hpp"

using namespace std;

PetriDish:: PetriDish(Vec2d centre, double r)
    : CircularBody(centre, r),
      temperature(getAppConfig()["petri dish"]["temperature"]["default"].toDouble()),
      puissance((getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble() + getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble())/2)
{}

bool PetriDish::addNutriment(Nutriment* n) {
    if (contains(*n)) {
        food.push_back(n);
    }
    return contains(*n);
}

// IMPORTANCE DE PASSER LES POINTEURS PAR REFERENCE DANS LES BOUCLES

void PetriDish::update(sf::Time dt) {
        for(auto& nutriment : food) {
            if (nutriment->getRadius()==0) {
                delete nutriment;
                nutriment=nullptr;
            } //si la quantité (=rayon) vaut zéro le nutriment est supprimé

            if (nutriment != nullptr) nutriment->update(dt);
        }
        food.erase(remove(food.begin(), food.end(), nullptr), food.end());
        //enleve tous les pointeurs nuls d'un coup dans food

        for (auto& bacterie : faune) {
            if (!bacterie->alive()) {
                delete bacterie;
                bacterie=nullptr;
            } //si morte la bactérie doit disparaitre

            if (bacterie != nullptr) bacterie->update(dt);
        }
        faune.erase(remove(faune.begin(), faune.end(), nullptr), faune.end());
        //enleve tous les pointeurs nuls d'un coup dans faune

        for (auto& grp : groupes) {
            if (grp != nullptr) grp->update(dt);
        }

        for (auto& a : adn){
            if (a->getRadius() == 0){
                delete a;
                a = nullptr;
            }
        }
        adn.erase(remove(adn.begin(), adn.end(), nullptr), adn.end());
}

void PetriDish::drawOn(sf::RenderTarget &targetWindow) const{
    auto border = buildAnnulus(getPosition(), getRadius(), sf::Color::White, 5);
    targetWindow.draw(border);

    for (auto& n : food) {
        if (n != nullptr) n->drawOn(targetWindow);
    }
    for (auto& b : faune) {
        if (b != nullptr) b->drawOn(targetWindow);
    }
    for (auto& a : adn){
        if(a != nullptr) a->drawOn(targetWindow);
    }
}

void PetriDish::reset() {
    for (auto& bacterie : faune) delete bacterie;
    for (auto& nutriment : food) delete nutriment;
    for (auto& a : adn) delete a;

    faune.clear();
    food.clear();
    adn.clear();

    resetTemperature();
    resetGradientExponent();
}

void PetriDish::resetTemperature(){
    temperature = getAppConfig()["petri dish"]["temperature"]["default"].toDouble();
}

double PetriDish::getTemperature() const {
    return temperature;
}

void PetriDish::decreaseTemperature(){
    temperature -= getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}

void PetriDish::increaseTemperature(){
    temperature+= getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}


PetriDish::~PetriDish(){
    for (auto& bacterie : faune) {
        delete bacterie;
        bacterie=nullptr;
    }
    for (auto& nutriment : food){
        delete nutriment;
        nutriment = nullptr;
    }
    for (auto& a : adn){
        delete a;
        a = nullptr;
    }
}


bool PetriDish::addBacterium(Bacterium *b)
{
    if (contains(*b) and adn.size() < 5) {
        faune.push_back(b);
    }
    return (contains(*b) and adn.size() < 5);
}

bool PetriDish::addADN(ADN *a)
{
    if (contains(*a)){
        adn.push_back(a);
    }
    return contains(*a);
}


Nutriment* PetriDish::getNutrimentColliding(CircularBody const& body) const
{
        for (auto& nutriments : food) {
            if ((*nutriments)&(body)) return nutriments;
            //retourne seulement
            //le premier nutriment en collision avec
            //la bactérie passée en paramètre
        }
    return nullptr; //si n'a rien retourné avant
}

ADN* PetriDish::getADNcolliding(const CircularBody &body) const
{
    for (auto& a : adn){
        if((*a)&(body)) return a;
    }
    return nullptr;
}

double PetriDish::getPositionScore(const Vec2d &p) const
{
    double somme(0.0);
    for(auto& n : food){
        if (n != nullptr) somme += (n->getRadius())/(pow(distance(p,n->getPosition()), puissance));
        }
    return somme;
}

double PetriDish::getGradientExponent() const
{
    return puissance;
}

void PetriDish::increaseGradientExponent()
{
    puissance += getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();
}

void PetriDish::decreaseGradientExponent()
{
    puissance -= getAppConfig()["petri dish"]["gradient"]["exponent"]["delta"].toDouble();
}

void PetriDish::resetGradientExponent()
{
    puissance = (getAppConfig()["petri dish"]["gradient"]["exponent"]["max"].toDouble() + getAppConfig()["petri dish"]["gradient"]["exponent"]["min"].toDouble())/2;
}



Swarm* PetriDish::getSwarmWithId(string id)
{
    for(auto& grp : groupes) {
        if(grp->getIdentificator()==id) return grp;
    }
    return nullptr;
}

void PetriDish::addSwarm(Swarm* s)
{
    if (s != nullptr) groupes.push_back(s);
}

unordered_map<string, double> PetriDish::fetchData(const string & name) const
{
    unordered_map<string, double> new_data;
    statistic var;
    if(name == s::NUTRIMENT_QUANTITY){
        var = NUTRIMENT_QUANTITY;
    } else if(name == s::GENERAL){
        var = GENERAL;
    } else if(name == s::SIMPLE_BACTERIA){
        var = SIMPLE_BACTERIA;
    } else if(name == s::TWITCHING_BACTERIA){
        var = TWITCHING_BACTERIA;
    } else if(name == s::BACTERIA){
        var = BACTERIA;
    }
    switch (var) {
    case NUTRIMENT_QUANTITY :
        new_data = unordered_map<string, double> {{s::NUTRIMENT_QUANTITY, food.size()}};
        break;

    case GENERAL :
        new_data = unordered_map<string, double> {{s::SIMPLE_BACTERIA, SimpleBacterium::compteur},
                                                  {s::TWITCHING_BACTERIA, TwitchingBacterium::compteur},
                                                  {s::SWARM_BACTERIA, SwarmBacterium::compteur},
                                                  {s::NUTRIMENT_SOURCES, food.size()},
                                                  {"temperature", temperature}};
        break;

    case SIMPLE_BACTERIA :
        new_data = unordered_map<string, double> {{s::BETTER, SimpleBacterium::Mbetter},
                                                  {s::WORSE, SimpleBacterium::Mworse}};
        break;

    case TWITCHING_BACTERIA :
        new_data = unordered_map<string, double> {{s::TENTACLE_LENGTH, TwitchingBacterium::Mlength},
                                                  {s::TENTACLE_SPEED, TwitchingBacterium::Mspeed}};
        break;

    case BACTERIA :
    {
        double moyenne(0.0);
        if((SimpleBacterium::compteur+TwitchingBacterium::compteur+SwarmBacterium::compteur) != 0){
            moyenne = ((SimpleBacterium::Mspeed*SimpleBacterium::compteur)+(TwitchingBacterium::Mspeed*TwitchingBacterium::compteur)+(30*SwarmBacterium::compteur))/(SimpleBacterium::compteur+TwitchingBacterium::compteur+SwarmBacterium::compteur);
        }
        new_data = unordered_map<string, double> {{s::SPEED, moyenne}};
        break;
    }
    default:
        break;
    }
    return new_data;
}
