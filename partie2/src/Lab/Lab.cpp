#include "Lab.hpp"
#include "Application.hpp"
#include "PetriDish.hpp"

using namespace std;

void Lab::drawOn(sf::RenderTarget &targetWindow) const
{
    boite.drawOn(targetWindow);
}

void Lab::update(sf::Time dt)
{
    boite.update(dt);
}

Lab::Lab() : PetriDish(getApp().getCentre(), 0.95*getApp().getLabSize().x/2) {}
/*
 constructeur, initialise la boite de petri au centre de la fenetre associée au Lab
 et d'un rayon faisant 95% de la largeur de la fenetre
 */
void Lab::reset()
{
    boite.reset();
}
