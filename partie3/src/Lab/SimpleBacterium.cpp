#include "SimpleBacterium.hpp"
#include "../Application.hpp"

using namespace std;


j::Value& SimpleBacterium::getConfig() const
{
    return (getAppConfig()["simple bacterium"]);
}
/*
Bacterium* SimpleBacterium::clone() const
{
    Bacterium* copie(this);
    return copie;
}
*/
