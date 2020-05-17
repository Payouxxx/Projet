#ifndef NUTRIMENT_HPP
#define NUTRIMENT_HPP

#include <Lab/CircularBody.hpp>
#include <../Utility/Types.hpp>
#include <SFML/Graphics.hpp>
#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"


class Bacterium;
class SwarmBacterium;
class TwitchingBacterium;
class SimpleBacterium;


/*!
 * @brief the Nutriment class modeling a nutriment
 */

class Nutriment : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief constructor
     * @param rayon
     * @param centre
     */
    Nutriment(Quantity rayon, Vec2d centre);

    /*!
     * @brief destructor
     */
    ~Nutriment();

    /*!
     * @brief take quantity of a nutriment
     * @param quantity we want to take
     * @return quantity token
     */
    Quantity takeQuantity(Quantity q);

    /*!
     * @brief set quantity for a nutriment
     * @param new quantity
     */
    void setQuantity(Quantity q);

    /*!
     * @brief draw a nutriment and display quantity if debug is on
     * @param window on which we draw
     */
    void drawOn(sf::RenderTarget& target) const;

    /*!
     * @brief updatde nutriment simulation (make it grow if optimal temparature, new nutriment contained
     * in the petri dish and new quantity inferior than the double of the initial one)
     *        nutriment also grow if it is contained in the light
     *        nutriment starts to degrade after a time defined in the app.json file
     * @param amount of time making simulation evolve (sf::Time dt)
     */
    void update(sf::Time dt);

    /*!
     * @brief shortcut to a location in the file app.json
     * @return shortcut
     */
    virtual j::Value const& getConfig() const =0;

    /*!
     * @brief fist call to differenciate nutriment (virtual pure here)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten
     */
    virtual Quantity eatenBy(Bacterium& bact) = 0;

    /*!
     * @brief case of SimpleBacterium (virtual pure here)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten
     */
    virtual Quantity eatenBy(SimpleBacterium& bact) = 0;

    /*!
     * @brief case of TwitchingBacterium (virtual pure here)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten
     */
    virtual Quantity eatenBy(TwitchingBacterium& bact) = 0;

    /*!
     * @brief case of SwarmBacterium (virtual pure here)
     * @param bacterium eating the current nutriment
     * @return Quantity eaten
     */
    virtual Quantity eatenBy(SwarmBacterium& bact) = 0;

private:
    Quantity quantite; ///< quantity of the nutriment
    double compteur;   ///< counter since its creation
};


#endif // NUTRIMENT_HPP
