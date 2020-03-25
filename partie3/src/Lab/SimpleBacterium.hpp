#ifndef SIMPLEBACTERIUM_HPP
#define SIMPLEBACTERIUM_HPP

#include "Bacterium.hpp"

class SimpleBacterium : public Bacterium
{
public:
    j::Value& getConfig() const;
    //Bacterium* clone() const;
};

#endif // SIMPLEBACTERIUM_HPP
