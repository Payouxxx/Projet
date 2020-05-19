#ifndef NUTRIMENTGENERATOR_HPP
#define NUTRIMENTGENERATOR_HPP

#include <SFML/Graphics.hpp>
#include "../Interface/Updatable.hpp"


/*!
 * @brief generate randomly new nutriment in the current lab
 */

class NutrimentGenerator : public Updatable
{
public:
    /*!
     * @brief constructor (initialize time at zero)
     */
    NutrimentGenerator();

    /*!
     * @brief updatde nutriment generator simulation (create new nutriment randomly after a certain
     * amount of time then add it to the current lab)
     * @param amount of time making simulation evolve
     */
    void update(sf::Time dt) override;

    /*!
     * @brief reset time
     */
    void reset();

private:
    sf::Time dt; ///< time running (indicates time between two generations of nutriments)
};

#endif // NUTRIMENTGENERATOR_HPP
