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
};

#endif // NUTRIMENTA_HPP
