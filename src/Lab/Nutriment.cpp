#include "Nutriment.hpp"
#include "../Application.hpp"
#include "Utility/Utility.hpp"
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

Nutriment::Nutriment(Quantity q, const Vec2d &centre)
    : CircularBody(centre, q), quantite(q) {}

Quantity Nutriment::takeQuantity(Quantity q)
{
    /*******************************
     si la quantité demandée est inférieure ou égale à la quantité disponible on peut la prélever
     sinon on prélève toute la quantité présente
      ******************************/
    if(q<=quantite){
        quantite -= q;
        setRadius(quantite);
        return q;
    } else {
        q = quantite;
        quantite = 0.0;
        setRadius(quantite);
        return q;
    }
}

void Nutriment::setQuantity(Quantity q)
{
    if(q>=0.0){
        quantite = q;
        setRadius(q);
    }
}

j::Value const& Nutriment::getConfig() const
{
    return getAppConfig()["nutriments"];
}

void Nutriment::drawOn(sf::RenderTarget& target) const
{
    int A(floor(quantite));
    auto const& texture = getAppTexture(getConfig()["texture"].toString());
    auto nutrimentSprite = buildSprite(getPosition(), 6, texture);
    nutrimentSprite.setScale(2 * getRadius() / texture.getSize().x, 2 * getRadius() / texture.getSize().y);
    target.draw(nutrimentSprite);
    if(isDebugOn()){
        auto const text = buildText(to_string(A), getPosition(), getAppFont(), 15, sf::Color::Black);
        target.draw(text);
    }
}

void Nutriment::update(sf::Time dt)
{
    /********************************
     si la quantité de nutriments présente dans la boite est inferieure au double d'une certaine quantité
     et que la source de nutriment ne déborde pas de l'assiette, alors on test de voir si la boite de petri associée
     au lab est à une température adaptée à la croissance des nutriments
     *******************************/
        if(getAppEnv().getTemperature() >= getAppConfig()["nutriments"]["growth"]["min temperature"].toDouble() and
                getAppEnv().getTemperature() <= getAppConfig()["nutriments"]["growth"]["max temperature"].toDouble() and
                quantite <= 2*getConfig()["quantity"]["max"].toDouble()){
            double speed(getConfig()["growth"]["speed"].toDouble());
            auto growth = speed * dt.asSeconds();
            quantite += growth;
            setRadius(quantite);
            if(not getAppEnv().contains(*this)){
                quantite -= growth;
                setRadius(quantite);
            }
        }
    }
