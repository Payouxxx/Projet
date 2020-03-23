#ifndef LAB_HPP
#define LAB_HPP

#include "PetriDish.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class Lab : public Drawable, public Updatable{
public:
    void update(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow) const;
    void reset();
    Lab();
    bool contains(const CircularBody& corps) const;
    void addNutriment(Nutriment* n);
    double getTemperature() const;
    void increaseTemperature();
    void decreaseTemperature();
    void resetTemperature();
private:
    PetriDish boite;
}

#endif // LAB_HPP
