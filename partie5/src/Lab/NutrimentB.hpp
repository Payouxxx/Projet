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
    j::Value const& getConfig() const override;

    /*!
     * @brief fist call to differenciate nutriment (redefinition)
     *        call method "eatableQuantity" of the bacteria
     * @param bacterium eating the current nutriment
     * @return Quantity eaten
     */
    virtual Quantity eatenBy(Bacterium& bact) override;

    /*!
     * @brief case of SimpleBacterium (redefinition)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max quantity divided by a resistance factor)
     */
    virtual Quantity eatenBy(SimpleBacterium& bact) override;

    /*!
     * @brief case of TwitchingBacterium (redefinition)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max aetable multiplied by a nutritive factor)
     */
    virtual Quantity eatenBy(TwitchingBacterium& bact) override;

    /*!
     * @brief case of SwarmBacterium (redefinition), make bacteria loose energy
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max aetable multiplied by a poison factor)
     */
    virtual Quantity eatenBy(SwarmBacterium& bact) override;
};

#endif // NUTRIMENTB_HPP
