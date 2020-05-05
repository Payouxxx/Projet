#ifndef ADN_HPP
#define ADN_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"


class Bacterium;
class SwarmBacterium;
class TwitchingBacterium;
class SimpleBacterium;

class ADN : public CircularBody, public Drawable
{
public:
    ADN(double rayon, Vec2d centre);
    ~ADN();
    void drawOn(sf::RenderTarget& target) const;
    static j::Value const& getConfig();
    void eaten();
};

#endif // ADN_HPP
