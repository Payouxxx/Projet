#ifndef LAB_HPP
#define LAB_HPP

#include "PetriDish.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "NutrimentGenerator.hpp"
#include "Swarm.hpp"
#include "ADN.hpp"
#include "Lampe.hpp"
#include "Poison.hpp"

/*!
 * @brief The Lab class, a subclass of Drawable and Updatable, managing one PetriDish development
 */
class Lab : public Drawable, public Updatable
{
public:
    /*!
     * @brief Constructor (initialize the dish at the center of the environment)
     */
    Lab();

    /*!
     * @brief update of the PetriDish and the Nutriments (automatic generation of nutriments)
     *        update attributes "time" and "lampe"
     * (vitual method inherited from the abstract Updatable class)
     * @param dt (sf::Time)
     */
    void update(sf::Time dt) override;

    /*!
     * @brief draw the PetriDish on the target (virtual method inherited from the abstract Drawable class)
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget& targetWindow) const override;

    /*!
     * @brief delete everything in the PetriDish
     */
    void reset();

    /*!
     * @brief reset all the controls of the Lab (Temperature/Gradient exponent/Time/Light)
     */
    void resetControls();

    /*!
     * @brief call the contains method of its PetriDish
     * @param body (CircularBody)
     * @return true if the PetriDish contains body
     */
    bool contains(const CircularBody& body) const;

    /*!
     * @brief call the contains method of its PetriDish
     * @param point (Vec2d)
     * @return true if the PetriDish contains the point
     */
    bool contains(const Vec2d& point) const;

    /*!
     * @brief call the addNutriment method of its PetriDish
     * @param n (nutriment pointer)
     */
    void addNutriment(Nutriment* n);

    /*!
     * @brief call the addBacterium method of its PetriDish
     * @param b (bacteria pointer)
     */
    void addBacterium(Bacterium* b);

    /*!
     * @brief call the addADN method of its PetriDish
     * @param a (adn pointer)
     */
    void addADN(ADN* a);

    /*!
     * @brief call the addVirus method of its PetriDish
     * @param v (virus pointer)
     */
    void addVirus(Virus* v);

    /*!
     * @brief call the addPoison method of its PetriDish
     * @param p (poison pointer)
     */
    void addPoison(Poison *p);

    /*!
     * @brief call the getTemperature method of the PetriDish
     * @return Temperature (double)
     */
    double getTemperature() const;

    /*!
     * @brief call the increaseTemperature method of the PetriDish
     */
    void increaseTemperature();

    /*!
     * @brief call the decreaseTemperatre method of the PetriDish
     */
    void decreaseTemperature();

    /*!
     * @brief call de resetTemperature method of the PetriDish
     */
    void resetTemperature();


    /*!
     * @brief  call the getGradientExponent method of the PetriDish
     * @return GradientExponent
     */
    double getGradientExponent() const;

    /*!
     * @brief call the increaseGradientExponent method of the PetriDish
     */
    void increaseGradientExponent();

    /*!
     * @brief call the decreaseGradientExponent method of the PetriDish
     */
    void decreaseGradientExponent();

    /*!
     * @brief call the resetGradientExponent method of the PetriDish
     */
    void resetGradientExponent();

    /*!
     * @brief call the doesCollideWithDish method of the PetriDish
     * @param body (CircularBody)
     * @return true if body and the PetriDish are colliding
     */
    bool doesCollideWithDish(CircularBody const& body) const;

    /*!
     * @brief call the getNutrimentColliding method of the PetriDish
     * @param body (CircularBody)
     * @return a pointer on the nutriment if they are colliding otherwise it returns a nullptr
     */
    Nutriment* getNutrimentColliding(CircularBody const& body) const;

    /*!
     * @brief call the getADNColliding method of the PetriDish
     * @param body (CircularBody)
     * @return a pointer on the ADN if they are colliding otherwise it returns a nullptr
     */
    ADN* getADNColliding(CircularBody const& body) const;

    /*!
     * @brief call the getPoisonColliding method of the PetriDish
     * @param body (CircularBody)
     * @return a pointer on the Poison if they are colliding otherwise it returns a nullptr
     */
    Poison* getPoisonColliding(CircularBody const& body) const;

    /*!
     * @brief call the getBacteriumColliding method of the PetriDish
     * @param body (CircularBody)
     * @return a pointer on the Bacterium if they are colliding otherwise it returns a nullptr
     */
    Bacterium* getBacteriumColliding(CircularBody const& body) const;

    /*!
     * @brief call the getPositionScore method of the PetriDish
     * @param p (Vec2d)
     * @return the score of the position p
     */
    double getPositionScore(const Vec2d&p) const;

    /*!
     * @brief call the getPositionBact method of the PetriDish
     * @param p (Vec2d)
     * @return the score of the position p
     */
    double getPositionBact(const Vec2d &p) const;

    /*!
     * @brief call the getSwarmWithId method of the PetriDish
     * @param string id
     * @return pointer on swarm or nullptr if swarm not found
     */
    Swarm *getSwarmWithId(std::string id);

    /*!
     * @brief call the addSwarm method of the PetriDish
     * @param pointer on Swarm
     */
    void addSwarm(Swarm* s);

    /*!
     * @brief call the fetchData method of the PetriDish
     * @param string name (of the graph)
     * @return unordered_map<std::string, double> (set of all graph names and corresponding value)
     */
    std::unordered_map<std::string, double> fetchData(const std::string &name) const;

    /*!
     * @brief return current time
     * @return time (double)
     */
    double getTime() const;

    /*!
     * @brief reset counter of time
     */
    void resetTime();

    /*!
     * @brief switch off the light and put it in the center of the dish
     */
    void resetLight();

    /*!
     * @brief return current state of the light
     * @return bool
     */
    bool lightOn() const;

    /*!
     * @brief make light on or off
     * @param bool
     */
    void setState(bool onOff);

    /*!
     * @brief call the doesCollideWithLight method of the PetriDish
     * @param body (CircularBody)
     * @return true if body and the lampe are colliding
     */
    bool doesCollideWithLight(const CircularBody &body) const;

private:
    PetriDish boite;                ///< the PetriDish
    NutrimentGenerator automatique; ///< creation of new nutriments
    double time;                    ///< counter of time
    Lampe lampe;                    ///< light moving in the lab
};

#endif // LAB_HPP
