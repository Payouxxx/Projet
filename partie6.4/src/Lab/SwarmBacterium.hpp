#ifndef SWARMBACTERIUM_HPP
#define SWARMBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

class Swarm;


/*!
 * @brief The SwarmBacterium class, a subclass of the Bacterium class and DiffEqFunction class
 */

class SwarmBacterium : public Bacterium, public DiffEqFunction
{
public:
    /*!
     * @brief Constructor, increments static attributs
     * @param position (Vec2d)
     * @param pointer on the swarm where it belongs
     */
    SwarmBacterium(Vec2d position, Swarm* grp);

    /*!
     * @brief Copy constructor, also add the copy in the same swarm
     *        increments static attributs
     * @param other SwarmBacterium
     */
    SwarmBacterium(const SwarmBacterium& other);

    /*!
     * @brief virtual destructor, remove the bacterium from its Swarm, decreases static attributs
     */
    ~SwarmBacterium();

    /*!
     * @brief redefinition of the virtual method getConfig to access the SwarmBacterium data in the app.json file
     * @return getAppConfig()["swarm bacterium"]
     */
    j::Value& getConfig() const override;

    /*!
     * @brief redefinition of the virtual method move
     * the leader takes the best direction depending on the score and other bacteria follow the leader
     * @param dt (sf::Time)
     */
    void move(sf::Time dt) override;

    /*!
     * @brief redefinition of the virtual method clone, use the copy constructor
     * @return a bacterium pointer to a clone of the current instance
     */
    Bacterium* clone() const override;

    /*!
     * @brief redefinition of the f method of DiffEqFunction, which calculates the force exerced on the bacterium
     *        and influences the speed
     * @param position (Vec2d)
     * @param speed (double)
     * @return attractive force of the leader on other bacteria
     */
    Vec2d f(Vec2d position, Vec2d speed) const override;

    /*!
     * @brief call the drawOn method of the Bacterium class, and draw a red circle around the leader
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget &targetWindow) const override;

    /*!
     * @brief access to the speed as a Vec2d
     * @return the speed (depending on direction)
     */
    Vec2d getSpeedVector() const;

    /*!
     * @brief polymorphic method, redefinition, calls nutriment method "eatenBy"
     * @param nutriment eaten
     * @return quantity eatable by the bacterium with nutriment A
     */
    virtual Quantity eatableQuantity(NutrimentA& nutriment) override;

    /*!
     * @brief polymorphic method, redefinition, calls nutriment method "eatenBy"
     * @param nutriment eaten
     * @return quantity eatable by the bacterium with nutriment B
     */
    virtual Quantity eatableQuantity(NutrimentB& nutriment) override;

    /*!
     * @brief get in app.json the max eatable quantity for this bacterium
     * @return max eatable quantity by this bacterium
     */
    Quantity getMaxEatableQuantity() const;

    /*!
     * @brief if the bacterium collides with a piece of poison (which is not thrown by one of the bacteria
     * belonging to the same swarm), it is infected and loses some energy
     */
    void poisonned() override;

    static double compteur; ///< counter of created instances

private:
    Swarm* groupe;          ///< knowledge of the swarm where it belongs


};

#endif // SWARMBACTERIUM_HPP
