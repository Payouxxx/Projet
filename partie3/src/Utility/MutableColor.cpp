#include "MutableColor.hpp"
#include <iostream>

using namespace std;

MutableColor::MutableColor(const j::Value &config)
    : RGBA({config["r"], config["g"], config["b"], config["a"]})
{}

void MutableColor::mutate()
{
    for(auto& nb : RGBA){
        nb.mutate();
    }
}

sf::Color MutableColor::get() const
{
    return { static_cast<sf::Uint8>(RGBA[0].get() * 255),
             static_cast<sf::Uint8>(RGBA[1].get() * 255),
             static_cast<sf::Uint8>(RGBA[2].get() * 255),
             static_cast<sf::Uint8>(RGBA[3].get() * 255) };
}
