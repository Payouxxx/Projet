#include "Lab.hpp"
#include "Application.hpp"

using namespace std;

Lab::drawOn(sf::RenderTarget &targetWindow) const
{
    boite.drawOn(targetWindow);
}

Lab::update(sf::Time dt)
{
    boite.update(dt);
}

Lab::Lab() : PetriDish(getApp().getCentre(), ((0.95*getApp().getLabSize().x)/2)) {}
