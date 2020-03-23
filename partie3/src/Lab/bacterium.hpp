#ifndef BACTERIUM_HPP
#define BACTERIUM_HPP

#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"
#include "CircularBody.hpp"

class Bacterium : public CircularBody, public Drawable, public Updatable
{

};


#endif // BACTERIUM_HPP
