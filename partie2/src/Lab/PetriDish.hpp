#ifndef PETRIDISH_HPP
#define PETRIDISH_HPP

#include <iostream>
#include <vector>
#include "Nutriment.hpp"
#include "Bacterium.hpp"
#include <SFML/Graphics.hpp>
#include "CircularBody.hpp"

class PetriDish : public CircularBody
{
public:
    //faire évoluer les bactéries ici
    PetriDish(Vec2d centre, double r) : CircularBody(centre, r) {}
    PetriDish(const PetriDish&) = delete; //empecher la copie
    PetriDish& operator =(const PetriDish&) = delete; //empecher l'affectation
    ~PetriDish(); //destructeur pour réstituer la mémoire allouée

    bool addBacterium(Bacterium* b);
    bool addNutriment(Nutriment* n);
    void update(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow)const;
    void reset();
private:
    std::vector <Bacterium*> faune;
    std::vector <Nutriment*> food;
};

#endif // PETRIDISH_HPP
