#ifndef SIMPLEBACTERIUM_HPP
#define SIMPLEBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

/*!
 * @brief The SimpleBacterium class, a subclass of Bacterium and DiffEgFunction
 */
class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    /*!
     * @brief Constructor
     * @param position (Vec2d)
     */
    SimpleBacterium(Vec2d position);

    /*!
     * @brief redefinition of the virtual method getConfig to access the SimpleBacterium datas in the app.json file
     * @return getAppConfig()["simple bacterium"]
     */
    j::Value& getConfig() const;

    /*!
     * @brief redefinition of the virtual method clone
     *        creation of a new pointer of a new bacteria based on the current instance
     *
     * @return a bacteria pointer to a clone of the current instance
     */
    Bacterium* clone() const;

    /*!
     * @brief redefinition of the virtual method move
     *
     * Change the position of the bacteria thanks to a DiffEq
     * Withdraw of the necessary amount of energy to move
     * Call the basculement method to make the bacteria failover randomly
     *
     * @param dt
     */
    void move(sf::Time dt);

    /*!
     * @brief call the drawOn method of the Bacteria class, and the drawFlagelle method to display the "flagelle"
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget& targetWindow) const;

    /*!
     * @brief call the update method of the Bacteria class, and the updateFlagelle method
     * @param dt (sf::Time)
     */
    void update(sf::Time dt);

    /*!
     * @brief redefinition of the f method of DiffEqFunction, which calculate the force exerced on the bacteria
     *        and influences the speed
     *
     * @param position (Vec2d)
     * @param speed (double)
     *
     * @return 0 (always for a SimpleBacterium)
     */
    Vec2d f(Vec2d position, Vec2d speed) const;

    /*!
     * @brief draw the "Flagelle" at the end of the bacteria
     * @param targetWindow (display window)
     */
    void drawFlagelle(sf::RenderTarget& targetWindow) const;

    /*!
     * @brief update the "Flagelle"
     * @param dt (sf::Time)
     */
    void updateFlagelle(sf::Time dt);

    /*!
     * @brief access to the speed as a Vec2d
     * @return the speed (depending on direction)
     */
    Vec2d getSpeedVector() const;

    /*!
     * @brief make randomly the bacteria change its direction
     */
    void basculement();

    virtual Quantity eatableQuantity(NutrimentA& nutriment) override;
    virtual Quantity eatableQuantity(NutrimentB& nutriment) override;
    Quantity getMaxEatableQuantity() const;

private:
    double t;              ///< counter to draw the "flagelle"
    sf::Time dt;           ///< counter between 2 failover
    double pBasculement;   ///< failover probability (random change of direction)
};

#endif // SIMPLEBACTERIUM_HPP
