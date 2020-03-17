#ifndef LAB_HPP
#define LAB_HPP
#include "PetriDish.hpp"


class Lab {
public :
    Lab();
    void drawOn(sf::RenderTarget& targetWindow)const;
    void update(sf::Time dt);
    void reset();
private:
    PetriDish boite;
};

#endif // LAB_HPP
