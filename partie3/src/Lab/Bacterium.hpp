#ifndef BACTERIUM_HPP
#define BACTERIUM_HPP

#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"
#include "CircularBody.hpp"
#include "Utility/MutableColor.hpp"
#include "Utility/Types.hpp"
#include <string>
#include <SFML/Graphics.hpp>

class Bacterium : public CircularBody, public Drawable, public Updatable
{
public:
    void drawOn(sf::RenderTarget& targetWindow) const;
    void update(sf::Time dt);
    virtual void move(sf::Time dt) =0;
    virtual Bacterium* clone() const =0;
    bool alive() const;
    virtual j::Value& getConfig() const =0;
    void consumeEnergy(Quantity qt);

    Quantity getEnergieMin() const;
    sf::Time getDelay() const;
    Quantity getConsumption() const;

    Bacterium(Quantity nrj, Vec2d position, Vec2d dir, double rayon, MutableColor color);

private:
    Quantity energie;
    Vec2d direction;
    MutableColor couleur;
    bool abstinence;
    sf::Time compteur; //temps entre 2 consommation nutriments
    std::map<std::string, MutableNumber> parametres;
};


#endif // BACTERIUM_HPP
