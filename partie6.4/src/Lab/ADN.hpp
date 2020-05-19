#ifndef ADN_HPP
#define ADN_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"


class Bacterium;
class SwarmBacterium;
class TwitchingBacterium;
class SimpleBacterium;

/*!
 * @brief The ADN class, a subClass of CircularBody and Drawable
 */
class ADN : public CircularBody, public Drawable
{
public:
    /*!
     * @brief constructor
     * @param rayon
     * @param centre
     */
    ADN(double rayon, Vec2d centre);

    /*!
     * @brief destructor
     */
    ~ADN();

    /*!
     * @brief draw the ADN on the target (virtual method inherited from the abstract Drawable class)
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget& target) const;

    /*!
     * @brief shortcut to values in the app.json file
     * @return ["ADN"]
     */
    static j::Value const& getConfig();

    /*!
     * @brief eaten method, indicate that the piece of adn has been eaten, set its radius at 0
     */
    void eaten();
};

#endif // ADN_HPP
