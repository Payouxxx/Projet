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
     * @brief Constructor
     * @param position (Vec2d)
     */
    TwitchingBacterium(Vec2d position);

    ~TwitchingBacterium();

    /*!
     * @brief redefinition of the virtual method getConfig to access the TwitchingBacterium datas in the app.json file
     * @return getAppConfig()
     */
    j::Value& getConfig() const override;

    /*!
     * @brief redefinition of the virtual method move
     * @param dt (sf::Time)
     */
    void move(sf::Time dt) override;

    /*!
     * @brief redefinition of the virtual method clone
     *
     * the clone does not have tentacle and its position is a bit different of the initial one
     *
     * @return a bacteria pointer to a clone of the current instance
     */
    Bacterium* clone() const override;

    /*!
     * @brief call the drawOn method of the Bacteria class, and the drawTentacle method
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
     * @brief The etat enum of the differents states of the bacteria
     */
    enum etat {IDLE, WAIT_TO_DEPLOY, DEPLOY, ATTRACT, RETRACT, EAT};


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

    static double getCompteur();
    static double compteur;  ///< counter of created instances
private:
    Grip grapin;            ///< grip of the twitching bacteria (CircularBody)
    etat state;             ///< state of the bacteria

};


#endif // TWITCHINGBACTERIUM_HPP
