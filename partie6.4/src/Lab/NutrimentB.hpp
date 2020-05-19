#ifndef NUTRIMENTB_HPP
#define NUTRIMENTB_HPP

#include "Nutriment.hpp"


/*!
 * @brief the NutrimentB class modeling a blue nutriment, a subClass of Nutriment
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
     * @return getAppConfig()["nutriment B"]
     */
    j::Value const& getConfig() const override;

    /*!
     * @brief first call to differenciate nutriment (redefinition)
     *        call method "eatableQuantity" of the bacteria
     * @param bacterium eating the current nutriment
     * @return Quantity eaten
     */
    virtual Quantity eatenBy(Bacterium& bact) override;

    /*!
     * @brief case of SimpleBacterium (redefinition)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max eatable quantity divided by a resistance factor)
     */
    virtual Quantity eatenBy(SimpleBacterium& bact) override;

    /*!
     * @brief case of TwitchingBacterium (redefinition)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max eatable quantity multiplied by a nutritive factor)
     */
    virtual Quantity eatenBy(TwitchingBacterium& bact) override;

    /*!
     * @brief case of SwarmBacterium (redefinition), make bacteria loose energy
     *        if the bacteria has evolved it gains resistance to poison
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max eatable quantity multiplied by a poison factor)
     */
    virtual Quantity eatenBy(SwarmBacterium& bact) override;
};

#endif // NUTRIMENTB_HPP
