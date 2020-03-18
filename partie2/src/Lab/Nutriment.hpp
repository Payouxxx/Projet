#ifndef NUTRIMENT_HPP
#define NUTRIMENT_HPP

#include <Lab/CircularBody.hpp>
#include <../Utility/Types.hpp>
#include <SFML/Graphics.hpp>

class Nutriment : public CircularBody {
public:
    Nutriment(Quantity rayon, Vec2d centre);
    Quantity takeQuantity(Quantity q);
    void setQuantity(Quantity q);
    void drawOn(sf::RenderTarget& target) const;
    j::Value const& getConfig() const;
private:
    Quantity quantite;
};

#endif // NUTRIMENT_HPP
