#ifndef MUTABLECOLOR_HPP
#define MUTABLECOLOR_HPP
#include "MutableNumber.hpp"
#include <array>
#include "SFML/Graphics.hpp"

class MutableColor {
private:
    std::array <MutableNumber, 4> RGBA;
public:
    MutableColor(j::Value const& config);
    void mutate();
    sf::Color get() const;
};

#endif // MUTABLECOLOR_HPP
