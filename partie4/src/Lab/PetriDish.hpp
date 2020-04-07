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




/*!
 * @brief the PetriDish class modeling a petridish and all that it contains
 */

class PetriDish : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief add a bacteria in the petri dish (if contained)
     * @param bacteria we want to add (pointer)
     * @return booleen indicating if adding was successful or not
     */
    bool addBacterium(Bacterium* b);

    /*!
     * @brief add a nutriment in the petri dish (if contained)
     * @param nutriment we want to add (pointer)
     * @return booleen indicating if adding was successful or not
     */
    bool addNutriment(Nutriment* n);


    /*!
     * @brief updatde petri dish simulation
     * @param amount of time making simulation evolve (sf::Time dt)
     */
    void update(sf::Time dt);

    /*!
     * @brief draw a circle (border of the petridish) and call for drawOn of every bacteria and nutriment contained
     * (if not null pointers)
     * @param amount of time making simulation evolve (sf::Time dt)
     */
    void drawOn(sf::RenderTarget& targetWindow) const;

   /*!
     * @brief reset petridish simulation (erase everything contained and reset temperature and gradient exponent)
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

    PetriDish(Vec2d centre, double r);
    PetriDish(const PetriDish&) = delete; //empecher la copie
    PetriDish& operator= (const PetriDish&) = delete; //empecher l'affectation
    ~PetriDish();


    /*!
      * @brief get the first nutrient colliding with the circular body we chose
      * @param circular body which can collide against a nutriment
      * @return nullprr if the body isn't colliding with nutriment,
      * else a pointer toward the nutriment the body is collinding with
      */
    Nutriment* getNutrimentColliding(CircularBody const& body);

    /*!
      * @brief get position score depending on the formula where s is nutriment source and p a position:
      * score(p) = taille(s) / (distance(p,centre(s))puissance
      * @param position where we want the score to be calculated
      * @return gradient exponent for this position (double)
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

private:
    std::vector<Bacterium*> faune; ///< the whole bacteria in the petri dish
    //std::vector<Bacterium*> annexe; //bactéries créées par clonage
    std::vector<Nutriment*> food; ///< the whole nutriments in the petri dish
    double temperature; ///< temperature of the petri dish
    double puissance; ///< used to calculate gradient exponent
};

#endif // PETRIDISH_HPP
