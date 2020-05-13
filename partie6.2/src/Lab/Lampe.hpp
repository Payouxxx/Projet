#ifndef LAMPE_HPP
#define LAMPE_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include "Utility/MutableColor.hpp"

/*!
 * @brief The Lampe class, a subclass of CircularBody, drawable and Updatable
 */
class Lampe : public CircularBody, public Drawable, public Updatable
{
public:

    /*!
     * @brief constructor
     * @param centre
     * @param rayon
     */
    Lampe(Vec2d centre, double rayon);

    /*!
     * @brief shortcut to access to "Lampe" data
     * @return a j::Value stored in the app.json file
     */
    static j::Value const& getConfig();

    /*!
     * @brief draw the lamp on the target (virtual method inherited from the abstract Drawable class)
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget& target) const override;

    /*!
     * @brief updatde Lamp simulation (make it move)
     * @param amount of time making simulation evolve (sf::Time dt)
     */
    void update(sf::Time dt) override;

    /*!
     * @brief return state of the lampe (on or off)
     * @return bool
     */
    bool isOn() const;

    /*!
     * @brief make light move, choosing random direction when collide with the petridish
     * @param amount of time making simulation evolve (sf::Time dt)
     */
    void move(sf::Time dt);

    /*!
     * @brief turn the light on or off
     * @param bool
     */
    void setState(bool state);

    /*!
     * @brief reset position of the light (center of the lab)
     *        turn it off
     */
    void reset();

private:
    sf::Color color; ///< color
    bool ON;         ///< true if the lampe is on
    Vec2d direction; ///< random direction
};

#endif // LAMPE_HPP
