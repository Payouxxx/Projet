#ifndef PETRIDISH_HPP
#define PETRIDISH_HPP

#include<iostream>
#include <vector>
#include "Nutriment.hpp"
#include "bacterium.hpp"
#include <SFML/Graphics.hpp>
#include "CircularBody.hpp"
#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"

class PetriDish : public CircularBody, public Drawable, public Updatable
{
public:
    bool addBacterium(Bacterium* b);
    bool addNutriment(Nutriment* n);
    void update(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow) const;
    void reset();
    double getTemperature() const;
    void increaseTemperature();
    void decreaseTemperature();
    void resetTemperature();

    PetriDish(Vec2d centre, double r);
    PetriDish(const PetriDish&) = delete; //empecher la copie
    PetriDish& operator= (const PetriDish&) = delete; //empecher l'affectation
    ~PetriDish();

private:
    std::vector<Bacterium*> faune;
    std::vector<Nutriment*> food;
    double temperature;
};

#endif // PETRIDISH_HPP
