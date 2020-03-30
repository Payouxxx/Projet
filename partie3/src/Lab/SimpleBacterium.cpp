#include "SimpleBacterium.hpp"
#include "../Application.hpp"
#include "Random/Random.hpp"
#include "Utility/Vec2d.hpp"
#include <cmath>

using namespace std;


j::Value& SimpleBacterium::getConfig() const
{
    return (getAppConfig()["simple bacterium"]);
}

Bacterium* SimpleBacterium::clone() const
{
    //Bacterium* copie(this);
    //return copie;
}


SimpleBacterium::SimpleBacterium(Vec2d position)
    : Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()), position,
      Vec2d::fromRandomAngle(), uniform(getConfig()["radius"]["min"].toDouble(), getConfig()["radius"]["max"].toDouble()),
      getConfig()["color"]),
      t(uniform(0.0, M_PI))
{}

Vec2d SimpleBacterium::f(Vec2d position, Vec2d speed) const
{
    return Vec2d(0,0);
}

Vec2d SimpleBacterium::getSpeedVector() const
{
    return getDirection().normalised()*10;
}

void SimpleBacterium::move(sf::Time dt)
{
    DiffEqResult resultat(stepDiffEq(getPosition(), getSpeedVector(), dt, *this, DiffEqAlgorithm::EC));
    Vec2d length(resultat.position - this->getPosition());
    if(length.lengthSquared() > 0.001){
        this->CircularBody::move(length);
        consumeEnergy(getConsumption()*length.length());
    }
    //La vitesse ne varie pas car la force est nulle
}

void SimpleBacterium::drawOn(sf::RenderTarget& targetWindow) const
{
    Bacterium::drawOn(targetWindow);
    auto set_of_points = sf::VertexArray(sf::TrianglesStrip);
    set_of_points.append({{0,0}, sf::Color::Black});
    for(size_t i(1); i<30; ++i){
        float x = static_cast<float>(-i * getRadius() / 10.0);
        float y = static_cast<float>(getRadius() * sin(t) * sin(2 * i / 10.0));
        set_of_points.append({{x,y}, sf::Color::Black});
    }
    targetWindow.draw(set_of_points);
}

void SimpleBacterium::update(sf::Time dt)
{
    Bacterium::update(dt);
    t += 3*dt.asSeconds();
}

