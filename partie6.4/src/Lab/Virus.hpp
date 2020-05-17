#ifndef VIRUS_HPP
#define VIRUS_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include <SFML/Graphics.hpp>


/*!
 * @brief The Virus class modeling a virus attacking the bacteria
 */
class Virus : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief constructor
     * @param centre (vec2d)
     * @param rayon (double)
     */
    Virus(Vec2d centre, double rayon);

    /*!
     * @brief destructor
     */
    ~Virus();

    /*!
     * @brief draw the lamp on the target (virtual method inherited from the abstract Drawable class),
     * thanks to a picture in the res folder
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget &target) const override;

    /*!
     * @brief update the virus, makes it move and lose energy
     * @param dt
     */
    void update(sf::Time dt) override;

    /*!
     * @brief select best of 20 randow direction depending on bacteria score and set it as the new direction
     * @param dt
     */
    void move(sf::Time dt);

    /*!
     * @brief getConfig allows a sortcut to some values in the app.json file
     * @return a j::value
     */
    j::Value const& getConfig() const;

    /*!
     * @brief method indicating the state of the virus
     * @return true if the virus has 0 or less energy
     */
    bool isDead() const;

    /*!
     * @brief if the virus collide with a bacteria it tries to infect it. If it's a success, the virus replicate
     * and the both instances recover the initial amount of energy, if not it simply dies
     */
    void infection();

private:
    sf::Time tempsVie; ///< life time decreasing as the time goes
    bool dead;         ///< state of the virus
    Vec2d direction;   ///< current direction of the virus
};

#endif // VIRUS_HPP
