#include "Virus.hpp"
#include "Application.hpp"
#include "Utility/Utility.hpp"
#include "Bacterium.hpp"

Virus::Virus(Vec2d centre, double rayon)
    : CircularBody(centre, rayon),
      tempsVie(sf::seconds(getConfig()["life time"].toDouble())),
      dead(false),
      direction(Vec2d::fromRandomAngle())
{}

Virus::~Virus() {}

void Virus::drawOn(sf::RenderTarget &target) const
{
    auto const& texture = getAppTexture(getConfig()["texture"].toString());
    auto adnSprite = buildSprite(getPosition(), 6, texture);
    // adapte la taille du Sprite au rayon de l'ADN:
       adnSprite.setScale(2 * getRadius()/ texture.getSize().x, 2 *getRadius()/ texture.getSize().y);
       target.draw(adnSprite);
}

const j::Value &Virus::getConfig() const
{
    return getAppConfig()["Virus"];
}

void Virus::update(sf::Time dt)
{
    tempsVie -= dt;
    if (tempsVie <= sf::Time::Zero) dead = true;
    else {
        move(dt);
        infection();
    }
}

void Virus::move(sf::Time dt)
{
    Vec2d dir(getPosition().fromRandomAngle());
    for(int i(0); i<20; ++i){
        Vec2d dir2(getPosition().fromRandomAngle());
        if(getAppEnv().getPositionBact(dir+getPosition()) < getAppEnv().getPositionBact(dir2+getPosition())){
            dir = dir2;
        }
    }
    direction = dir;

    CircularBody::move(direction.normalised()*getConfig()["speed"].toDouble());
}

bool Virus::isDead() const
{
    return dead;
}

void Virus::infection()
{
    if (!dead and getAppEnv().getBacteriumColliding(*this) != nullptr){
        if (getAppEnv().getBacteriumColliding(*this)->infection()){
            tempsVie = sf::seconds(getConfig()["life time"].toDouble());
            getAppEnv().addVirus(new Virus(*this));
        } else dead = true;
    }
}
