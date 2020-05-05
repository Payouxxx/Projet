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
     * @brief Constructor, increments statics attributs
     * @param position (Vec2d)
     * @param pointer on the swarm where it belongs
     */
    SwarmBacterium(Vec2d position, Swarm* grp);

    /*!
     * @brief Copy constructor, also add he copy in the same swarm
     *        increments statics attributs
     * @param other SwarmBacterium
     */
    SwarmBacterium(const SwarmBacterium& other);

    /*!
     * @brief virtual destructor, remove the bacteria from its Swarm, decreases statics attributs
     */
    ~SwarmBacterium();

    /*!
     * @brief redefinition of the virtual method getConfig to access the TwitchingBacterium datas in the app.json file
     * @return shortcut towards adaptated values
     */
    j::Value& getConfig() const override;

    /*!
     * @brief redefinition of the virtual method move
     * @param dt (sf::Time)
     */
    void move(sf::Time dt) override;

    /*!
     * @brief redefinition of the virtual method clone
     * @return a bacteria pointer to a clone of the current instance
     */
    Bacterium* clone() const override;

    /*!
     * @brief redefinition of the f method of DiffEqFunction, which calculate the force exerced on the bacteria
     *        and influences the speed
     * @param position (Vec2d)
     * @param speed (double)
     * @return attractive force of the leader on other bacteria
     */
    Vec2d f(Vec2d position, Vec2d speed) const override;

    /*!
     * @brief call the drawOn method of the Bacteria class, and draw a red circle around the leader one
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget &targetWindow) const override;

    /*!
     * @brief access to the speed as a Vec2d
     * @return the speed (depending on direction)
     */
    Vec2d getSpeedVector() const;

    /*!
     * @brief polymorphic method, redefinition, calls nutriment fonction "eatenBy"
     * @param nutriment eaten
     * @return quantity eatable by the bacteria with nutriment A
     */
    virtual Quantity eatableQuantity(NutrimentA& nutriment) override;

    /*!
     * @brief polymorphic method, redefinition, calls nutriment fonction "eatenBy"
     * @param nutriment eaten
     * @return quantity eatable by the bacteria with nutriment B
     */
    virtual Quantity eatableQuantity(NutrimentB& nutriment) override;

    /*!
     * @brief get in app.json the max eatable quantity for this bacteria
     * @return max quantity eatable by this bacteria
     */
    Quantity getMaxEatableQuantity() const;

    static double compteur; ///< counter of created instances
private:
    Swarm* groupe;          ///< knowledge of the swarm where it belongs

};

#endif // SWARMBACTERIUM_HPP
