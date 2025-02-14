#include "PetriDish.hpp"
#include "../Utility/Utility.hpp"
#include "Nutriment.hpp"
#include "../Application.hpp"
#include "JSON/JSONImpl.hpp"
#include <iostream>
#include <cmath>

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
}

void PetriDish::reset() {
    for (auto& bacterie : faune) delete bacterie;
    for (auto& nutriment : food) delete nutriment;

    faune.clear();
    food.clear();

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
}


bool PetriDish::addBacterium(Bacterium *b)
{
    if (contains(*b)) {
        faune.push_back(b);
    }
    return contains(*b);
}


Nutriment* PetriDish::getNutrimentColliding(CircularBody const& body)
{
        for (auto& nutriments : food) {
            if ((*nutriments)&(body)) return nutriments;
            //retourne seulement
            //le premier nutriment en collision avec
            //la bactérie passée en paramètre
        }
    return nullptr; //si n'a rien retourné avant
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

