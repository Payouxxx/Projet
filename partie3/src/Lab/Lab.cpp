#include "Lab.hpp"
#include "../Application.hpp"
#include "../Utility/Utility.hpp"

using namespace std;

void Lab::drawOn(sf::RenderTarget &targetWindow) const {
        boite.drawOn(targetWindow);
}

void Lab::update(sf::Time dt) {
    boite.update(dt);
}

Lab::Lab() :
    boite(getApp().getCentre(), 0.95*getApp().getLabSize().x/2.0)
{}

void Lab::reset(){
    boite.reset();
}

bool Lab::contains(const CircularBody& corps) const {
    return boite.contains(corps);
}

void Lab::addNutriment(Nutriment* n){
    boite.addNutriment(n);
}

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
