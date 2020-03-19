#include "PetriDish.hpp"
#include "../Utility/Utility.hpp"
#include "Nutriment.hpp"
#include "../Application.hpp"

using namespace std;

PetriDish:: PetriDish(Vec2d centre, double r) : CircularBody(centre, r),
temperature(getAppConfig()["petri dish"]["temperature"]["default"].toDouble()) {}


bool PetriDish::addNutriment(Nutriment* n) {
    if (contains(*n)) {
        food.push_back(n);
    }
    return contains(*n);
}

void PetriDish::update(sf::Time dt) {
        for(auto nutriment : food) {
            nutriment->update(dt);
        }
}

void PetriDish::drawOn(sf::RenderTarget &targetWindow) const{
    auto border = buildAnnulus(getPosition(), getRadius(), sf::Color::Cyan, 5);
    targetWindow.draw(border);

    for (auto n : food) {
        n->drawOn(targetWindow);
    }
}

void PetriDish::reset() {
    for (auto& bacterie : faune) delete bacterie;
    for (auto& nutriment : food) delete nutriment;

    faune.clear();
    food.clear();
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
