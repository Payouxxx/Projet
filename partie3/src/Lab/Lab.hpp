#ifndef LAB_HPP
#define LAB_HPP

#include "PetriDish.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "NutrimentGenerator.hpp"

class Lab : public Drawable, public Updatable{
public:
    void update(sf::Time dt);
    void drawOn(sf::RenderTarget& targetWindow) const;
    void reset();
    Lab();
    bool contains(const CircularBody& corps) const;

    void addNutriment(Nutriment* n);
    void addBacterium(Bacterium* b);

    double getTemperature() const;
    void increaseTemperature();
    void decreaseTemperature();
    void resetTemperature();

    bool doesCollideWithDish(CircularBody const& body) const;
    Nutriment* getNutrimentColliding(CircularBody const& body);
private:
    PetriDish boite;
    NutrimentGenerator automatique;
}

#endif // LAB_HPP
