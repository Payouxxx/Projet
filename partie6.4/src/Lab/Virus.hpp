#ifndef VIRUS_HPP
#define VIRUS_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"
#include <SFML/Graphics.hpp>


/*!
 * @brief The Virus class modeling a virus attacking the bacteria
 * a subClass of CircularBody, Drawable and Updatable
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
     * @brief draw the virus on the target (virtual method inherited from the abstract Drawable class),
     * thanks to a picture in the res folder
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget &target) const override;

    /*!
     * @brief update the virus, makes it move and lose life time
     * @param dt
     */
    void update(sf::Time dt) override;

    /*!
     * @brief select best of 20 random direction depending on bacteria score and set it as the new direction
     * @param dt
     */
    void move(sf::Time dt);

    /*!
     * @brief getConfig allows a sortcut to some values in the app.json file
     * @return getAppConfig()["Virus"]
     */
    j::Value const& getConfig() const;

    /*!
     * @brief method indicating the state of the virus
     * @return true if the virus has 0 or less life time
     */
    bool isDead() const;

    /*!
     * @brief if the virus collides with a bacterium, it tries to infect it. If it's a success, the virus replicates
     * and the both instances recover the initial amount of life time, if not it simply dies
     */
    void infection();

private:
    sf::Time tempsVie; ///< life time decreasing as the time goes on
    bool dead;         ///< state of the virus
    Vec2d direction;   ///< current direction of the virus
};

#endif // VIRUS_HPP
