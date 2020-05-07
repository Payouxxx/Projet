#ifndef LAMPE_HPP
#define LAMPE_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/MutableColor.hpp"

class Lampe : public CircularBody, public Drawable, public Updatable
{
public:
    Lampe(Vec2d centre, double rayon);
    j::Value const& getConfig() const;
    void drawOn(sf::RenderTarget& target) const override;
    void update(sf::Time dt) override;
    bool isOn() const;
    void move();
    void setState(bool state);

private:
    MutableColor color; ///< color
    bool ON;            ///< true if the lampe is on
    Vec2d direction;    ///< random direction
};

#endif // LAMPE_HPP
