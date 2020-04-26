#ifndef NUTRIMENTA_HPP
#define NUTRIMENTA_HPP

#include "Nutriment.hpp"


/*!
 * @brief the NutrimentA class modeling a green nutriment
 */

class NutrimentA : public Nutriment
{
public:
    /*!
     * @brief constructor
     * @param rayon
     * @param centre
     */
    NutrimentA(Quantity rayon, Vec2d centre);

    /*!
     * @brief shortcut to a location in the file app.json
     * @return shortcut
     */
    j::Value const& getConfig() const;

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
     * @return Quantity eaten (here max aetable)
     */
    virtual Quantity eatenBy(SimpleBacterium& bact) override;

    /*!
     * @brief case of TwitchingBacterium (redefinition)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max aetable)
     */
    virtual Quantity eatenBy(TwitchingBacterium& bact) override;

    /*!
     * @brief case of SwarmBacterium (redefinition)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten (here max aetable)
     */
    virtual Quantity eatenBy(SwarmBacterium& bact) override;
};

#endif // NUTRIMENTA_HPP
