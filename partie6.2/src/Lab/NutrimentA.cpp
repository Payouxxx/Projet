#include "NutrimentA.hpp"
#include "../Application.hpp"
#include "../Config.hpp"
#include "JSON/JSONImpl.hpp"
#include "Utility/Utility.hpp"
#include "SwarmBacterium.hpp"
#include "SimpleBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "Bacterium.hpp"

using namespace std;

NutrimentA::NutrimentA(Quantity rayon, Vec2d centre)
    : Nutriment(rayon, centre) {}

j::Value const& NutrimentA::getConfig() const {
    return getAppConfig()["nutriments"]["A"];
}

Quantity NutrimentA::eatenBy(Bacterium &bact)
{
    return bact.eatableQuantity(*this);
}

Quantity NutrimentA::eatenBy(SimpleBacterium &bact)
{
    return takeQuantity(bact.getMaxEatableQuantity());
}

Quantity NutrimentA::eatenBy(TwitchingBacterium &bact)
{
    return takeQuantity(bact.getMaxEatableQuantity());
}

Quantity NutrimentA::eatenBy(SwarmBacterium& bact)
{
    return takeQuantity(bact.getMaxEatableQuantity());
}

