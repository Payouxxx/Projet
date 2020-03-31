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
    void resetControls();
    Lab();
    bool contains(const CircularBody& corps) const;

    void addNutriment(Nutriment* n);
    void addBacterium(Bacterium* b);

    double getTemperature() const;
    void increaseTemperature();
    void decreaseTemperature();
    void resetTemperature();

    double getGradientExponent() const;
    void increaseGradientExponent();
    void decreaseGradientExponent();
    void resetGradientExponent();

    bool doesCollideWithDish(CircularBody const& body) const;
    Nutriment* getNutrimentColliding(CircularBody const& body);
    double getPositionScore(const Vec2d&p) const;
private:
    PetriDish boite;
    NutrimentGenerator automatique;
}

#endif // LAB_HPP
