#ifndef NUTRIMENTB_HPP
#define NUTRIMENTB_HPP

#include "Nutriment.hpp"


/*!
 * @brief the NutrimentB class modeling a green nutriment
 */

class NutrimentB : public Nutriment
{
public:
    /*!
     * @brief constructor
     * @param rayon
     * @param centre
     */
    NutrimentB(Quantity rayon, Vec2d centre);

    /*!
     * @brief shortcut to a location in the file app.json
     * @return shortcut
     */
    j::Value const& getConfig() const;

    virtual Quantity eatenBy(Bacterium& bact) override;
    virtual Quantity eatenBy(SimpleBacterium& bact) override;
    virtual Quantity eatenBy(TwitchingBacterium& bact) override;
    virtual Quantity eatenBy(SwarmBacterium& bact) override;
};

#endif // NUTRIMENTB_HPP
