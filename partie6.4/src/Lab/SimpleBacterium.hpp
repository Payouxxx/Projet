#ifndef SIMPLEBACTERIUM_HPP
#define SIMPLEBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Utility/DiffEqSolver.hpp"

/*!
 * @brief The SimpleBacterium class, a subclass of Bacterium and DiffEqFunction
 */
class SimpleBacterium : public Bacterium, public DiffEqFunction
{
public:
    /*!
     * @brief Constructor, increments static attributs
     * @param position (Vec2d)
     */
    SimpleBacterium(Vec2d position);

    /*!
     * @brief Destructor, decrements static attributs
     */
    ~SimpleBacterium();

    /*!
     * @brief redefinition of the virtual method getConfig to access the SimpleBacterium data in the app.json file
     * @return getAppConfig()["simple bacterium"]
     */
    j::Value& getConfig() const override;

    /*!
     * @brief redefinition of the virtual method clone
     *        creation of a new pointer on a new bacterium based on the current instance
     *        increments static attributs
     * @return a bacterium pointer to a clone of the current instance
     */
    Bacterium* clone() const override;

    /*!
     * @brief redefinition of the virtual method move
     * Change the position of the bacterium thanks to a DiffEq
     * Withdraw of the necessary amount of energy to move
     * Call the basculement method to make the bacterium failover randomly
     * if the bacterium has evolved it goes faster but with lesser loss of energy
     * if the bacterium is under the light, energy decreases slower
     * @param dt
     */
    void move(sf::Time dt) override;

    /*!
     * @brief call the drawOn method of the Bacterium class, and the drawFlagelle method to display the "flagelle"
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget& targetWindow) const override;

    /*!
     * @brief call the update method of the Bacterium class, and the updateFlagelle method
     * @param dt (sf::Time)
     */
    void update(sf::Time dt) override;

    /*!
     * @brief redefinition of the f method of DiffEqFunction, which calculates the force exerced on the bacterium
     *        and influences the speed
     * @param position (Vec2d)
     * @param speed (double)
     * @return (0,0) (always for a SimpleBacterium)
     */
    Vec2d f(Vec2d position, Vec2d speed) const override;

    /*!
     * @brief draw the "Flagelle" at the back of the bacterium
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
     * @brief make the bacterium randomly change its direction
     */
    void basculement();

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
     * @return max quantity eatable by this bacterium
     */
    Quantity getMaxEatableQuantity() const;

    /*!
     * @brief after eating a piece of ADN, the bacterium has new parameters we have to take them into account
     * when calculating different stats, also it calls the Bacterium method competence
     * @param adn
     */
    virtual void competence(ADN* adn) override;

    /*!
     * @brief after colliding with a virus, the bacterium has new parameters we have to take them into account
     * when calculating different stats, also it calls the Bacterium method infection
     * @return true if the bacterium has been infected
     */
    virtual bool infection() override;

    /*!
     * @brief if the bacterium collides with a piece of poison it is infected and loses some energy
     */
    virtual void poisonned() override;

public:
    static double compteur;       ///< counter of created instances
    static double Mbetter;        ///< average values of mutableNumber tumble better
    static double Mworse;         ///< average values of mutableNumber tumble worse
    static double Mspeed;         ///< average speed

private:
    double t;              ///< counter to draw the "flagelle"
    sf::Time dt;           ///< counter between 2 failover
    double pBasculement;   ///< failover probability (random change of direction)

};


#endif // SIMPLEBACTERIUM_HPP
