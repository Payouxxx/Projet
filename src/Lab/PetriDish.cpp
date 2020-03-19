#include "PetriDish.hpp"
#include "Utility/Utility.hpp"
#include "Application.hpp"

using namespace std;

PetriDish::PetriDish(Vec2d centre, double r)
    : CircularBody(centre, r), temperature(getAppConfig()["petri dish"]["temperature"]["default"].toDouble()) {}

PetriDish::~PetriDish()
{
    for (auto& bacterie : faune){
        delete bacterie;
        bacterie = nullptr;
    }
    for (auto& nutriment : food){
        delete nutriment;
        nutriment = nullptr;
    }
}

void PetriDish::drawOn(sf::RenderTarget &targetWindow) const
{
    auto border = buildAnnulus(getPosition(), getRadius(), sf::Color::Cyan, 5);
    targetWindow.draw(border);
    for (auto& n : food){
        n->drawOn(targetWindow);
    }

}

void PetriDish::reset()
{
    for (auto& b : faune){
        delete b;
        faune.clear();
    }
    for (auto& n : food) {
        delete n;
        food.clear();
    }
    resetTemperature();
}

void PetriDish::resetTemperature()
{
    temperature = getAppConfig()["petri dish"]["temperature"]["default"].toDouble();
}

void PetriDish::update(sf::Time dt)
{
     for (auto& n : food){
            n->update(dt);
     }
}

bool PetriDish::addBacterium(Bacterium* b)
{

}

bool PetriDish::addNutriment(Nutriment* n)
{
    if(contains(*n)){
        food.push_back(n);
        return true;
    } else {
        return false;
    }
}

double PetriDish::getTemperature() const
{
    return temperature;
}

void PetriDish::decreaseTemperature()
{
    temperature -= getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}

void PetriDish::increaseTemperature()
{
    temperature += getAppConfig()["petri dish"]["temperature"]["delta"].toDouble();
}
