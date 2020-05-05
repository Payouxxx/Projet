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
    j::Value const& getConfig() const;

    void eatenBy(Bacterium& bact);
    void eatenBy(SimpleBacterium& bact);
    void eatenBy(TwitchingBacterium& bact);
    void eatenBy(SwarmBacterium& bact);

};

#endif // ADN_HPP
