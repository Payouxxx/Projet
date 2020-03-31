#include "Bacterium.hpp"
#include "../Application.hpp"
#include "JSON/JSONImpl.hpp"
#include "Utility/Utility.hpp"
#include <cmath>
#include "Utility/Vec2d.hpp"

using namespace std;

bool Bacterium::alive() const
{
    return (energie>0); //retourne true si en vie
}

Bacterium::Bacterium(Quantity nrj, Vec2d position, Vec2d dir, double rayon, MutableColor color)
    : CircularBody(position, rayon),
      energie(nrj),
      direction(dir),
      couleur(color),
      abstinence(false),
      compteur(sf::Time::Zero),
      angleDir(dir.angle())
{}


void Bacterium::drawOn(sf::RenderTarget &targetWindow) const
{ //couleur.get() pour avoir la couleur SFML
    auto const circle = buildCircle(getPosition(), getRadius(), couleur.get());
    targetWindow.draw(circle);

    if(isDebugOn()){
           int a(floor(energie)); //affichage d'entier et pas de double
           sf::Text const text = buildText(to_string(a), Vec2d(getPosition().x, getPosition().y + getRadius()), getAppFont(), 15, sf::Color::Black);
           targetWindow.draw(text);
       }
}

void Bacterium::update(sf::Time dt)
{
    move(dt);
    compteur += dt;
    if (getAppEnv().doesCollideWithDish(*this)) {
        direction = -(direction); //inverse direction
    }
    if (getAppEnv().getNutrimentColliding(*this) != nullptr) {
        if (!abstinence and compteur>=getDelay()){
            energie += (getAppEnv().getNutrimentColliding(*this)->takeQuantity(getConfig()["meal"]["max"].toDouble()));
            compteur = sf::Time::Zero;
            //ajout à l'energie de la bactérie de la quantité
            //max de nutriment qu'elle peut prélever
        }
    }
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

void Bacterium::consumeEnergy(Quantity qt)
{
    energie -= qt;
}

Vec2d Bacterium::getDirection()const
{
    return direction;
}

double Bacterium::getAngleDir() const
{
    return angleDir;
}

double Bacterium::getScore() const
{
    return getAppEnv().getPositionScore(getPosition());
}

//setter

void Bacterium::setAngleDir(double angle)
{
    angleDir = angle;
}
