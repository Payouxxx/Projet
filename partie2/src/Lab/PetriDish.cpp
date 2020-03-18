#include "PetriDish.hpp"
#include "../Utility/Utility.hpp"
#include "Nutriment.hpp"

using namespace std;



bool PetriDish::addNutriment(Nutriment* n) {
    if (contains(*n)) {
        food.push_back(n);
    }
    return contains(*n);
}

void PetriDish::update(sf::Time dt) {
    //a faire
}

void PetriDish::drawOn(sf::RenderTarget &targetWindow) const{
    auto border = buildAnnulus(centre, radius, sf::Color::Cyan, 5);
    targetWindow.draw(border);

    for (auto n : food) {
        n->drawOn(targetWindow);
    }
}

void PetriDish::reset() {
    faune.clear();
    food.clear();
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
