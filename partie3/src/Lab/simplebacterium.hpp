#ifndef SIMPLEBACTERIUM_HPP
#define SIMPLEBACTERIUM_HPP

#include "bacterium.hpp"

class SimpleBacterium : public Bacterium
{
public:
    SimpleBacterium();
    j::Value& getConfig() const;
    Bacterium* clone() const;
};

#endif // SIMPLEBACTERIUM_HPP
