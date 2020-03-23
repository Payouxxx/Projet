#ifndef NUTRIMENTGENERATOR_HPP
#define NUTRIMENTGENERATOR_HPP

#include <SFML/Graphics.hpp>
#include "../Interface/Updatable.hpp"

class NutrimentGenerator : public Updatable
{
public:
    NutrimentGenerator();
    void update(sf::Time dt);
    void reset();
private:
    sf::Time dt;
};

#endif // NUTRIMENTGENERATOR_HPP
