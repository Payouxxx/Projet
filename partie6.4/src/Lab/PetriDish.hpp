#ifndef PETRIDISH_HPP
#define PETRIDISH_HPP

#include<iostream>
#include <vector>
#include "Nutriment.hpp"
#include "Bacterium.hpp"
#include <SFML/Graphics.hpp>
#include "CircularBody.hpp"
#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"
#include "Swarm.hpp"
#include "Utility/Constants.hpp"
#include "ADN.hpp"
#include "Virus.hpp"
#include "Poison.hpp"



/*!
 * @brief the PetriDish class modeling a petridish and all that it contains
 * a subClass of CircularBody, Drawable and Updatable
 */
class PetriDish : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief add a bacterium in the petri dish (if it is contained in the dish)
     * @param bacterium we want to add (pointer)
     * @return booleen indicating if adding was successful or not
     */
    bool addBacterium(Bacterium* b);

    /*!
     * @brief add a nutriment in the petri dish (if it is contained in the dish)
     * @param nutriment we want to add (pointer)
     * @return booleen indicating if adding was successful or not
     */
    bool addNutriment(Nutriment* n);

    /*!
     * @brief add an ADN in the petridish (if it is contained in the dish)
     * @param adn we want to add (pointer)
     * @return booleen indicating if adding was successful or not
     */
    bool addADN(ADN* a);

    /*!
     * @brief add a virus in the petridish (if it is contained in the dish)
     * @param virus we want to add (pointer)
     * @return booleen indicating if adding was successful or not
     */
    bool addVirus(Virus* v);

    /*!
     * @brief add a poison in the petridish (if it is contained in the dish)
     * @param poison we want to add (pointer)
     * @return booleen indicating if adding was successful or not
     */
    bool addPoison(Poison* p);

    /*!
     * @brief updatde petri dish simulation
     * @param amount of time making simulation evolve (sf::Time dt)
     */
    void update(sf::Time dt) override;

    /*!
     * @brief draw a circle (border of the petridish) and call for drawOn of every bacterium,
     * nutriment, DNA, Virus and Poison contained (if it is not nullptr)
     * @param amount of time making simulation evolve (sf::Time dt)
     */
    void drawOn(sf::RenderTarget& targetWindow) const override;

   /*!
     * @brief reset petridish simulation (erase everything contained and
     * reset temperature, gradient exponent and graphs)
     */
    void reset();

    /*!
      * @brief get current temperature of the petri dish
      * @return current temperature (double)
      */
    double getTemperature() const;

    /*!
      * @brief increase temperature of the petri dish
      */
    void increaseTemperature();

    /*!
      * @brief decrease temperature of the petri dish
      */
    void decreaseTemperature();

    /*!
      * @brief reset temperature of the petri dish
      */
    void resetTemperature();

    /*!
     * @brief constructor
     * @param centrer
     * @param radius
     */
    PetriDish(Vec2d centre, double r);

    /*!
     * @brief prevent and forbid the copy of a petridish
     */
    PetriDish(const PetriDish&) = delete;

    /*!
     * @brief prevent and forbid the affectation operator
     */
    PetriDish& operator= (const PetriDish&) = delete;

    /*!
     * @brief destructor
     */
    ~PetriDish();

    /*!
      * @brief get the first nutriment colliding with the circular body we chose
      * @param circular body which can collide a nutriment
      * @return nullptr if the body isn't colliding with any nutriment,
      * else a pointer toward the nutriment the body is collinding with
      */
    Nutriment* getNutrimentColliding(CircularBody const& body) const;

    /*!
     * @brief get the first ADN colliding with the circular body we chose
     * @param circular body which can collide a piece of adn
     * @return nullptr if the body isn't colliding with any adn,
     * else a pointer toward the adn the body is collinding with
     */
    ADN* getADNcolliding(CircularBody const& body) const;

    /*!
     * @brief get the first Poison colliding with the circular body we chose
     * @param circular body which can collide a piece of poison
     * @return nullptr if the body isn't colliding with any poison,
     * else a pointer toward the poison the body is collinding with
     */
    Poison* getPoisonColliding(CircularBody const& body) const;

    /*!
     * @brief get the first Bacterium colliding with the circular body we chose
     * @param circular body which can collide a bacterium
     * @return nullptr if the body isn't colliding with any bacterium,
     * else a pointer toward the bacterium the body is collinding with
     */
    Bacterium* getBacteriumColliding(CircularBody const& body) const;

    /*!
      * @brief get position score depending on the formula where "s" is bacteria source and "p" a position:
      * score(p) = taille(s) / (distance(p,centre(s))puissance
      * @param position where we want the score to be calculated
      * @return score (of bacteria) for this position (double)
      */
    double getPositionBact(const Vec2d &p) const;

    /*!
      * @brief get position score depending on the formula where "s" is nutriment source and "p" a position:
      * score(p) = taille(s) / (distance(p,centre(s))puissance
      * @param position where we want the score to be calculated
      * @return score (of nutriments) for this position (double)
      */
    double getPositionScore(const Vec2d& p) const;


    /*!
      * @brief get current gradient exponent of the petri dish
      * @return gradient exponent (double)
      */
    double getGradientExponent() const;

    /*!
      * @brief increase gradient of the petri dish
      */
    void increaseGradientExponent();

    /*!
      * @brief decrease gradient of the petri dish
      */
    void decreaseGradientExponent();

    /*!
      * @brief reset gradient of the petri dish
      */
    void resetGradientExponent();

    /*!
      * @brief add a swarm in the petri dish
      * @param pointer on a swarm
      */
    void addSwarm(Swarm* s);

    /*!
     * @brief search and return the swarm with matching id given
     * @param string id
     * @return pointer on swarm or nullptr if not found
     */
    Swarm *getSwarmWithId(std::string id);

    /*!
     * @brief for a graph given, return the name of each curve and a new point on it
     * @param string name (of the graph)
     * @return unordered_map<std::string, double>
     */
    std::unordered_map<std::string, double> fetchData(const std::string &name) const;

    /*!
     * @brief The statistic enumerate type to handle the different type of graphs
     */
    enum statistic {NUTRIMENT_QUANTITY, GENERAL, SIMPLE_BACTERIA, TWITCHING_BACTERIA, BACTERIA};

private:
    std::vector<Bacterium*> faune;   ///< all the bacteria in the petri dish
    std::vector<Nutriment*> food;    ///< all the nutriments in the petri dish
    double temperature;              ///< temperature of the petri dish
    double puissance;                ///< used to calculate gradient exponent
    std::vector<Swarm*> groupes;     ///< all the swarms in the petri dish
    std::vector<ADN*> adn;           ///< all the ADN in the petri dish
    std::vector<Virus*> phages;      ///< all the virus in the petri dish
    std::vector<Poison*> poison;     ///< all the poison in the petri dish

};

#endif // PETRIDISH_HPP
