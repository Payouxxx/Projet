#include "NutrimentA.hpp"
#include "../Application.hpp"
#include "../Config.hpp"
#include "JSON/JSONImpl.hpp"
#include "Utility/Utility.hpp"

using namespace std;

NutrimentA::NutrimentA(Quantity rayon, Vec2d centre)
    : Nutriment(rayon, centre) {}

j::Value const& NutrimentA::getConfig() const {
    return getAppConfig()["nutriments"]["A"];
}
