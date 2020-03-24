#include "bacterium.hpp"
#include "../Application.hpp"
#include "JSON/JSONImpl.hpp"
#include "Utility/Utility.hpp"
#include <cmath>

using namespace std;

bool Bacterium::alive() const
{
    return (energie>0); //retourne true si en vie
}

Bacterium::Bacterium(Vec2d position, double rayon, Quantity nrj, Vec2d dir, MutableColor color)
    : CircularBody(position, rayon),
      energie(nrj),
      direction(dir),
      couleur(color),
      abstinence(false)
{} //pas d'initialisation des paramètres : liste vide ?


void Bacterium::drawOn(sf::RenderTarget &targetWindow) const
{ //couleur.get() pour avoir la couleur SFML
    auto const circle = buildCircle(getPosition(), getRadius(), couleur.get());
    targetWindow.draw(circle);

    if(isDebugOn()){
           int a(floor(energie)); //affichage d'entier et pas de double
           sf::Text const text = buildText(to_string(a), getPosition(), getAppFont(), 15, sf::Color::Black);
           targetWindow.draw(text);
       }
}

void Bacterium::update(sf::Time dt)
{
    move(dt);
    if (getAppEnv().doesCollideWithDish(*this)) {
        -direction; //inverse direction
    }
    if (getAppEnv().)
}


//getters

Quantity Bacterium::getEnergieMin() const
{
    return getConfig()["energy"]["division"].toDouble();
}

sf::Time Bacterium::getDelay() const
{
    return sf::seconds(getConfig()["meal"]["delay"].toDouble());
}

Quantity Bacterium::getConsumption() const
{
    return getConfig()["energy"]["consumption factor"].toDouble();
}
