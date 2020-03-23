#ifndef NUTRIMENT_HPP
#define NUTRIMENT_HPP
#include "CircularBody.hpp"
#include "Utility/Types.hpp"
#include "SFML/Graphics.hpp"

class Nutriment : public CircularBody
{
public:
    Nutriment(Quantity q, const Vec2d& centre); //constructeur rendant interdépendant le rayon et la quantité de nutriment
    Quantity takeQuantity(Quantity q); //preleve une certaine quantité q de nutriments
    void setQuantity(Quantity q); //met à jour la quantité présente
    j::Value const& getConfig() const;
    void drawOn(sf::RenderTarget& target) const;
    void update(sf::Time dt);
private:
    Quantity quantite; //double
};

#endif // NUTRIMENT_HPP
