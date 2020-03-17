#ifndef LAB_HPP
#define LAB_HPP
#include "PetriDish.hpp"


class Lab : public PetriDish{
public :
    Lab();
    void drawOn(sf::RenderTarget& targetWindow)const;
    void update(sf::Time dt);
};

#endif // LAB_HPP
