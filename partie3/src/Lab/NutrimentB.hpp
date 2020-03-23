#ifndef NUTRIMENTB_HPP
#define NUTRIMENTB_HPP

#include "Nutriment.hpp"

class NutrimentB : public Nutriment
{
public:
    NutrimentB(Quantity rayon, Vec2d centre);
    j::Value const& getConfig() const;
};

#endif // NUTRIMENTB_HPP
