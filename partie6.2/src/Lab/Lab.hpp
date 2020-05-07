#ifndef LAB_HPP
#define LAB_HPP

#include "PetriDish.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "NutrimentGenerator.hpp"
#include "Swarm.hpp"
#include "ADN.hpp"
#include "Lampe.hpp"

/*!
 * @brief The Lab class, a subclass of Drawable and Updatable, managing one PetriDish development and its nutriments
 */
class Lab : public Drawable, public Updatable{
public:
    /*!
     * @brief Constructor
     */
    Lab();

    /*!
     * @brief update of the PetriDish and the Nutriments (vitual method inherited from the abstract Updatable class)
     *        update attribute time
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
     * @brief reset all the controls of the Lab (Temperature/Gradient exponent)
     */
    void resetControls();

    /*!
     * @brief call the contains method of its PetriDish
     *
     * @param body (CircularBody)
     *
     * @return true if the PetriDish contains body
     */
    bool contains(const CircularBody& body) const;

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
     * @brief call the getTemperature method of the PetriDish
     * @return Temperature
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
    Nutriment* getNutrimentColliding(CircularBody const& body);

    /*!
     * @brief call the getADNColliding method of the PetriDish
     * @param body (CircularBody)
     * @return a pointer on the ADN if they are colliding otherwise it returns a nullptr
     */
    ADN* getADNColliding(CircularBody const& body);

    /*!
     * @brief call the getPositionScore method of the PetriDish
     * @param p (Vec2d)
     * @return the score of the position p
     */
    double getPositionScore(const Vec2d&p) const;

    /*!
     * @brief call the getPositionScore method of the PetriDish
     * @param string id
     * @return pointer on swarm or nullptr if swarm not found
     */
    Swarm *getSwarmWithId(std::string id);

    /*!
     * @brief call the getPositionScore method of the PetriDish
     * @param pointer on Swarm
     */
    void addSwarm(Swarm* s);

    /*!
     * @brief call the getPositionScore method of the PetriDish
     * @param string name (of the graph)
     * @return unordered_map<std::string, double>
     */
    std::unordered_map<std::string, double> fetchData(const std::string &name) const;

    /*!
     * @brief return current time
     * @return time (double)
     */
    double getTime() const;

    /*!
     * @brief reset comptor of time
     */
    void resetTime();

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
     * @brief call the doesCollideWithDish method of the PetriDish
     * @param body (CircularBody)
     * @return true if body and the lampe are colliding
     */
    bool doesCollideWithLight(const CircularBody &body) const;

private:
    PetriDish boite;                ///< the PetriDish
    NutrimentGenerator automatique; ///< creation of new nutriments
    double time;                    ///< comptor of time
    Lampe lampe;                    ///< lampe moving in the lab
};

#endif // LAB_HPP
