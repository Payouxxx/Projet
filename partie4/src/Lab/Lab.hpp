#ifndef LAB_HPP
#define LAB_HPP

#include "PetriDish.hpp"
#include <SFML/Graphics.hpp>
#include <vector>
#include "NutrimentGenerator.hpp"
#include "Swarm.hpp"

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
     * @param dt (sf::Time)
     */
    void update(sf::Time dt);

    /*!
     * @brief draw the PetriDish on the target (virtual method inherited from the abstract Drawable class)
     * @param targetWindow (display window)
     */
    void drawOn(sf::RenderTarget& targetWindow) const;

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
     *
     * @param body (CircularBody)
     *
     * @return true if body and the PetriDish are colliding
     */
    bool doesCollideWithDish(CircularBody const& body) const;

    /*!
     * @brief call the getNutrimentColliding method of the PetriDish
     *
     * @param body (CircularBody)
     *
     * @return a pointer on the nutriment if they are colliding otherwise it returns a nullptr
     */
    Nutriment* getNutrimentColliding(CircularBody const& body);

    /*!
     * @brief call the getPositionScore method of the PetriDish
     *
     * @param p (Vec2d)
     *
     * @return the score of the position p
     */
    double getPositionScore(const Vec2d&p) const;

    Swarm *getSwarmWithId(std::string id);
    void addSwarm(Swarm* s);

private:
    PetriDish boite;                ///< the PetriDish
    NutrimentGenerator automatique; ///< creation of new nutriments
}

#endif // LAB_HPP
