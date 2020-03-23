#ifndef NUTRIMENTA_HPP
#define NUTRIMENTA_HPP

#include "Nutriment.hpp"

class NutrimentA : public Nutriment
{
public:
    NutrimentA(Quantity rayon, Vec2d centre);
    j::Value const& getConfig() const;
};

#endif // NUTRIMENTA_HPP
