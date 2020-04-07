#include "NutrimentB.hpp"
#include "../Application.hpp"
#include "../Config.hpp"
#include "JSON/JSONImpl.hpp"
#include "Utility/Utility.hpp"

using namespace std;

NutrimentB::NutrimentB(Quantity rayon, Vec2d centre)
    : Nutriment(rayon, centre) {}

j::Value const& NutrimentB::getConfig() const {
    return getAppConfig()["nutriments"]["B"];
}
