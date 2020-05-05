#include "Bacterium.hpp"
#include "../Application.hpp"
#include "JSON/JSONImpl.hpp"
#include "Utility/Utility.hpp"
#include <cmath>
#include "Utility/Vec2d.hpp"
#include "Nutriment.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"

using namespace std;


Bacterium::Bacterium(Quantity nrj, Vec2d position, Vec2d dir, double rayon, MutableColor color, bool abst)
    : CircularBody(position, rayon),
      energie(nrj),
      direction(dir),
      couleur(color),
      abstinence(abst),
      compteur(sf::Time::Zero),
      angleDir(dir.angle())
{}

Bacterium::~Bacterium() {}

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
            //ajout à l'energie de la bactérie de la quantité
            //max de nutriment qu'elle peut prélever
            eat(*(getAppEnv().getNutrimentColliding(*this)));
            compteur = sf::Time::Zero;
        }
    }
    divide();
}

bool Bacterium::alive() const
{
    return (energie>0); //retourne true si en vie
}

Bacterium* Bacterium::mutate() //retourne pointeur sur elle même pour réutilistion dans addBacterium
{
    map<string, MutableNumber>::iterator it = parametres.begin();
    while(it != parametres.end()){
        it->second.mutate();
        ++it;
    }
    couleur.mutate();
    return this;
}


void Bacterium::consumeEnergy(Quantity qt)
{
    energie -= qt;
}

void Bacterium::divide()
{ //si assez énergie ajoute copie d'elle même à l'assiette, nrj/2 et mutation possible pour la nouvelle +inverse dir
    if(energie > getEnergieMin()){
        consumeEnergy(energie/2.0);
        //notre solution pour ajouter bacterie
        //solution prof : taleau annexe à ajouter avec append(v1, v2)
        getAppEnv().addBacterium(clone()->mutate());
        direction = -direction;
    }
}

void Bacterium::addProperty(const string & name, MutableNumber m)
{
    parametres[name]= m;
}

//getters

Quantity Bacterium::getEnergieMin() const
{
    return getConfig()["energy"]["division"].toDouble();
}

MutableNumber Bacterium::getProperty(const string &name) const
{
    try{
        auto paire = parametres.find(name);
        return paire->second;
    } catch(out_of_range){
        cerr << "out of range";
    } catch(invalid_argument){
        cerr << "invalid argument";
    }
}

sf::Time Bacterium::getDelay() const
{
    return sf::seconds(getConfig()["meal"]["delay"].toDouble());
}

Quantity Bacterium::getConsumption() const
{
    return getConfig()["energy"]["consumption factor"].toDouble();
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
    return (getAppEnv().getPositionScore(getPosition()));
}

sf::Color Bacterium::getColor() const
{
    return couleur.get();
}


//setter

void Bacterium::setAngleDir(double angle)
{
    angleDir = angle;
}

void Bacterium::setDirection(Vec2d dir)
{
    direction = dir;
}


void Bacterium::newDirection()
{
    Vec2d dir(getPosition().fromRandomAngle());
    for(int i(0); i<20; ++i){
        Vec2d dir2(getPosition().fromRandomAngle());
        if(getAppEnv().getPositionScore(dir+getPosition()) < getAppEnv().getPositionScore(dir2+getPosition())){
            dir = dir2;
        }
    }
    setDirection(dir);
}


void Bacterium::eat(Nutriment &nutriment)
{
    Quantity eaten(nutriment.eatenBy(*this));
    energie += eaten;
}


void Bacterium::competence(ADN& adn)
{

}
