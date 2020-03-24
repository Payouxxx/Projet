#include "simplebacterium.hpp"
#include "../Application.hpp"

using namespace std;

SimpleBacterium::SimpleBacterium()
{}

j::Value& SimpleBacterium::getConfig() const
{
    return (getAppConfig()["simple bacterium"]);
}

Bacterium* SimpleBacterium::clone() const
{
    Bacterium* copie(*this);
    return copie;
}
