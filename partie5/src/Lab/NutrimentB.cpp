#include "NutrimentB.hpp"
#include "../Application.hpp"
#include "../Config.hpp"
#include "JSON/JSONImpl.hpp"
#include "Utility/Utility.hpp"
#include "SwarmBacterium.hpp"
#include "SimpleBacterium.hpp"
#include "TwitchingBacterium.hpp"
#include "Bacterium.hpp"

using namespace std;

NutrimentB::NutrimentB(Quantity rayon, Vec2d centre)
    : Nutriment(rayon, centre) {}

j::Value const& NutrimentB::getConfig() const {
    return getAppConfig()["nutriments"]["B"];
}

Quantity NutrimentB::eatenBy(Bacterium &bact)
{
    return bact.eatableQuantity(*this);
}

Quantity NutrimentB::eatenBy(SimpleBacterium &bact)
{
    return takeQuantity(bact.getMaxEatableQuantity()/(getConfig()["resistance factor"].toDouble()));
}

Quantity NutrimentB::eatenBy(TwitchingBacterium &bact)
{
    return takeQuantity((getConfig()["nutritive factor"].toDouble())*bact.getMaxEatableQuantity());
}

Quantity NutrimentB::eatenBy(SwarmBacterium& bact)
{
    return takeQuantity(-(getConfig()["poison factor"].toDouble())*bact.getMaxEatableQuantity());
}
