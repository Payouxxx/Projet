#ifndef SWARMBACTERIUM_HPP
#define SWARMBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class Swarm;


/*!
 * @brief The TwitchingBacterium class, a subclass of the Bacterium class
 */

class SwarmBacterium : public Bacterium, public DiffEqFunction
{
public:
    /*!
     * @brief Constructor
     * @param position (Vec2d)
     * @param pointer on the swarm where it belongs
     */
    SwarmBacterium(Vec2d position, Swarm* grp);

    /*!
     * @brief virtual destructor, remove the bacteria from its Swarm
     */
    ~SwarmBacterium();


    /*!
     * @brief redefinition of the virtual method getConfig to access the TwitchingBacterium datas in the app.json file
     * @return shortcut towards adaptated values
     */
    j::Value& getConfig() const;

    /*!
     * @brief redefinition of the virtual method move
     * @param dt (sf::Time)
     */
    void move(sf::Time dt);

    /*!
     * @brief redefinition of the virtual method clone
     * @return a bacteria pointer to a clone of the current instance
     */
    Bacterium* clone() const;

    /*!
     * @brief redefinition of the f method of DiffEqFunction, which calculate the force exerced on the bacteria
     *        and influences the speed
     * @param position (Vec2d)
     * @param speed (double)
     * @return attractive force of the leader on other bacteria
     */
    Vec2d f(Vec2d position, Vec2d speed) const;

    /*!
     * @brief call the drawOn method of the Bacteria class, and draw a red circle around the leader one
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget &targetWindow) const;

    /*!
     * @brief access to the speed as a Vec2d
     * @return the speed (depending on direction)
     */
    Vec2d getSpeedVector() const;
private:
    Swarm* groupe;  ///< knowledge of the swarm where it belongs
};

#endif // SWARMBACTERIUM_HPP
