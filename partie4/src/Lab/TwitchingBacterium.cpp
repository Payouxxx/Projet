#include "TwitchingBacterium.hpp"
#include "Application.hpp"
#include "JSON/JSONImpl.hpp"
#include "Random/Random.hpp"
#include "SFML/Graphics.hpp"
#include "Utility/Utility.hpp"

TwitchingBacterium::TwitchingBacterium(Vec2d position)
    : Bacterium(uniform(getConfig()["energy"]["min"].toDouble(),getConfig()["energy"]["max"].toDouble()), position,
      Vec2d::fromRandomAngle(), uniform(getConfig()["radius"]["min"].toDouble(), getConfig()["radius"]["max"].toDouble()),
      getConfig()["color"]),
      grapin(position, getRadius()/4.0) //grapin initialisé à la même position mais avec un rayon 4 fois plus petit
{
    addProperty("speed", MutableNumber::positive(getConfig()["tentacle"]["speed"]));
    addProperty("length tentacle", MutableNumber::positive(getConfig()["tentacle"]["length"]));
}

TwitchingBacterium::TwitchingBacterium(TwitchingBacterium &other)
    : TwitchingBacterium(other.getPosition())
{}

//getters

j::Value& TwitchingBacterium::getConfig() const
{
    return (getAppConfig()["twitching bacterium"]);
}

double TwitchingBacterium::getEnergieMove() const
{
    return (getConfig()["energy"]["consumption factor"]["move"].toDouble());
}

double TwitchingBacterium::getEnergieTentacle() const
{
    return (getConfig()["energy"]["consumption factor"]["tentacle"].toDouble());
}

void TwitchingBacterium::move(sf::Time dt)
{

}

Bacterium* TwitchingBacterium::clone() const
{
    TwitchingBacterium* c(new TwitchingBacterium(this->getPosition()));
    c->grapin.~Grip();
    c->setPosition(Vec2d(getPosition().x +20,getPosition().y -20));
    return c;
}

void TwitchingBacterium::drawTentacle(sf::RenderTarget &targetWindow) const
{
    auto line = buildLine(grapin.getPosition(), this->getPosition(), sf::Color::Red, 1);
    targetWindow.draw(line);
    auto border = buildAnnulus(grapin.getPosition(), grapin.getRadius(), sf::Color::Red, 1);
    targetWindow.draw(border);
}

void TwitchingBacterium::drawOn(sf::RenderTarget &targetWindow) const
{
    drawTentacle(targetWindow);
    Bacterium::drawOn(targetWindow);

}

void TwitchingBacterium::moveGrip(Vec2d add)
{
    grapin.move(add);
}



