#ifndef MUTABLECOLOR_HPP
#define MUTABLECOLOR_HPP
#include "MutableNumber.hpp"
#include <array>
#include "SFML/Graphics.hpp"

/*!
 * @brief The MutableColor class
 */
class MutableColor {

public:
    /*!
     * @brief Constructor
     * @param config (j::Value)
     */
    MutableColor(j::Value const& config);

    /*!
     * @brief call the mutate method on each MutableNumber of RGBA
     */
    void mutate();

    /*!
     * @brief access to the color for SFML
     * @return the traduction in SFML color
     */
    sf::Color get() const;

private:
    std::array <MutableNumber, 4> RGBA; ///< 4 MutableNumbers to code the color
};

#endif // MUTABLECOLOR_HPP
