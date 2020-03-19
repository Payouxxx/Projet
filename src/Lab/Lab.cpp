#include "Lab.hpp"
#include "Application.hpp"
#include "PetriDish.hpp"
#include <iostream>

using namespace std;

void Lab::drawOn(sf::RenderTarget &targetWindow) const
{
    boite.drawOn(targetWindow);
}

void Lab::update(sf::Time dt)
{
    boite.update(dt);
}

Lab::Lab() : boite(getApp().getCentre(), 0.95*getApp().getLabSize().x/2) {}
/*
 constructeur, initialise la boite de petri au centre de la fenetre associée au Lab
 et d'un rayon faisant 95% de la largeur de la fenetre
 */
void Lab::reset()
{
    boite.reset();
}

bool Lab::contains(const CircularBody &corps) const
{
    return boite.contains(corps); //verifie que le nutriment appartient bien à la boite de pétri
}

void Lab::addNutriment(Nutriment* n)
{
    boite.addNutriment(n);
}

double Lab::getTemperature() const
{
    return boite.getTemperature();
}

void Lab::decreaseTemperature()
{
    boite.decreaseTemperature();
}

void Lab::increaseTemperature()
{
    boite.increaseTemperature();
}

void Lab::resetTemperature()
{
    boite.resetTemperature();
}
