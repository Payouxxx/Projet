#ifndef POISON_HPP
#define POISON_HPP

#include "CircularBody.hpp"
#include "Interface/Drawable.hpp"
#include "Interface/Updatable.hpp"

/*!
 * @brief The Poison class a subclass of Circular body, modeling a poison thrown by swarmbacteria
 */
class Poison : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief Constructor
     * @param centre (Vec2d)
     * @param rayon (double)
     * @param dir (Vec2d)
     * @param id corresponding to the swarm(string)
     */
    Poison(Vec2d centre, double rayon, Vec2d dir, std::string id);

    /*!
     * @brief redefinition of the drawOn method inhereted from the Drawable Class
     * each piece of poison is a cricle
     * @param target
     */
    void drawOn(sf::RenderTarget& target) const override;

    /*!
     * @brief destructor
     */
    ~Poison();

    /*!
     * @brief move method, if the instance collides with dish then it is deleted
     */
    void move();

    /*!
     * @brief update method, just call the move method each dt
     * @param dt
     */
    void update(sf::Time dt);

    /*!
     * @brief isVanished method
     * @return true if the poison has to be deleted
     */
    bool isVanished() const;

    /*!
     * @brief set the vanished attribute to the value in parmaeters
     * @param booleen
     */
    void setVanished(bool b);

    /*!
     * @brief getId
     * @return the identificator associated to the poison
     */
    std::string getId() const;
private:
    sf::Color color;            ///< color of the poison
    Vec2d direction;            ///< direction it's gonna take
    bool vanished;              ///< state of the piece of poison
    std::string identificateur; ///< identificator of the swarm which has created the poison
};

#endif // POISON_HPP
