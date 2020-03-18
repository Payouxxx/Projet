#ifndef LAB_HPP
#define LAB_HPP

#include "PetriDish.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Lab{
public:
    void update(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow) const;
    void reset();
    Lab();
    bool contains(const CircularBody& corps) const;
    void addNutriment(Nutriment* n);
private:
    PetriDish boite;
}

#endif // LAB_HPP
