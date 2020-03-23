#ifndef NUTRIMENT_HPP
#define NUTRIMENT_HPP

#include <Lab/CircularBody.hpp>
#include <../Utility/Types.hpp>
#include <SFML/Graphics.hpp>
#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"

class Nutriment : public CircularBody, public Drawable, public Updatable
{
public:
    Nutriment(Quantity rayon, Vec2d centre);
    Quantity takeQuantity(Quantity q);
    void setQuantity(Quantity q);
    void drawOn(sf::RenderTarget& target) const;
    virtual j::Value const& getConfig() const =0; //n'a plus de raison d'être
    // getConfig est virtuelle pure car trop générale
    void update(sf::Time dt);

private:
    Quantity quantite;
};


#endif // NUTRIMENT_HPP
