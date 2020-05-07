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
    void update(sf::Time dt) override;
    bool isOn() const;
    void move(sf::Time dt);
    void setState(bool state);
    void reset();

private:
    sf::Color color; ///< color
    bool ON;         ///< true if the lampe is on
    Vec2d direction; ///< random direction
};

#endif // LAMPE_HPP
