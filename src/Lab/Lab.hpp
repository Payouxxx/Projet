#ifndef LAB_HPP
#define LAB_HPP
#include "PetriDish.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Lab {
public :
    Lab();
    void drawOn(sf::RenderTarget& targetWindow) const;
    void update(sf::Time dt);
    void reset();
    bool contains(const CircularBody& corps) const; //verifie que le nutriment appartient bien au petridish
    void addNutriment(Nutriment* n);
    double getTemperature() const; //accès à la température du petridish
    void decreaseTemperature();
    void increaseTemperature();
    void resetTemperature();
private:
    PetriDish boite;
};

#endif // LAB_HPP
