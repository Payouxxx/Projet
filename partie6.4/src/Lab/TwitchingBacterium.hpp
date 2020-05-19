#ifndef TWITCHINGBACTERIUM_HPP
#define TWITCHINGBACTERIUM_HPP

#include "Bacterium.hpp"
#include "Grip.hpp"

/*!
 * @brief The TwitchingBacterium class, a subclass of the Bacterium class
 */
class TwitchingBacterium : public Bacterium
{
public:
    /*!
     * @brief Constructor, increments static attributs
     * @param position (Vec2d)
     */
    TwitchingBacterium(Vec2d position);

    /*!
     * @brief Destructor, decreases static attributs
     */
    ~TwitchingBacterium();

    /*!
     * @brief redefinition of the virtual method getConfig to access the TwitchingBacterium data in the app.json file
     * @return getAppConfig()["twitching bacterium"]
     */
    j::Value& getConfig() const override;

    /*!
     * @brief redefinition of the virtual method move
     * depending on the state of the bacterium, the grip deploys or retracts, or attracts the bacterium
     * if it collides with a nutriment
     * @param dt (sf::Time)
     */
    void move(sf::Time dt) override;

    /*!
     * @brief redefinition of the virtual method clone
     *        its position is a bit different of the initial one
     *        increments static attributs
     *        the grip can absorb DNA if it encounters one
     * @return a bacterium pointer to a clone of the current instance
     */
    Bacterium* clone() const override;

    /*!
     * @brief call the drawOn method of the Bacterium class, and the drawTentacle method
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget& targetWindow) const override;

    /*!
     * @brief access to the value of the move consumption factor
     * @return the value of the move consumption factor
     */
    double getEnergieMove() const;

    /*!
     * @brief access to the value of the tentacle consumption factor
     * @return the value of the tentacle consumption factor
     */
    double getEnergieTentacle() const;

    /*!
     * @brief draw the tentacle and the grip of the twitching bacteria
     * @param targetWindow (display window)
     */
    void drawTentacle(sf::RenderTarget& targetWindow) const;

    /*!
     * @brief call the move method of the Grip class
     * @param add (Vec2d)
     */
    void moveGrip(Vec2d add);

    /*!
     * @brief The etat enum of the different states of the bacteria
     */
    enum etat {IDLE, WAIT_TO_DEPLOY, DEPLOY, ATTRACT, RETRACT, EAT};


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
     * @brief if the bacterium has enough energy, it can produce a copy of itself with clone
     *        then the bacterium changes its direction to the opposite
     * if the bacterium has evolved the clone has 2/3 of the initial energy
     */
    virtual void divide();

    /*!
     * @brief after eating a piece of DNA, the bacterium has new parameters we have to take them into account
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
    static double Mlength;   ///< average values of mutableNumber tenatcule length
    static double Mspeed;    ///< average values of mutableNumber tentacule speed
    static double compteur;  ///< counter of created instances
private:
    Grip grapin;             ///< grip of the twitching bacterium (CircularBody)
    etat state;              ///< state of the bacterium

};


#endif // TWITCHINGBACTERIUM_HPP
