#include "PetriDish.hpp"
#include "Utility/Utility.hpp"

using namespace std;

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
    auto border = buildAnnulus(centre, radius, sf::Color::Cyan, 5);
      target.draw(border);
}
