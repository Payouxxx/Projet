#ifndef BACTERIUM_HPP
#define BACTERIUM_HPP

#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"
#include "CircularBody.hpp"
#include "Utility/MutableColor.hpp"
#include "Utility/Types.hpp"
#include <string>
#include <SFML/Graphics.hpp>

/*!
 * @brief The Bacterium class, a subClass of CircularBody, Drawable and Updatable
 */
class Bacterium : public CircularBody, public Drawable, public Updatable
{
public:
    /*!
     * @brief Constructor
     * @param nrj, position, dir, rayon, color
     */
    Bacterium(Quantity nrj, Vec2d position, Vec2d dir, double rayon, MutableColor color, bool abst = false);

    /*!
     * @brief Virual destructor each subClass must define its own destructor
     */
    virtual ~Bacterium() = 0;

    /*!
     * @brief draw the bacteria on the target (virtual method inherited from the abstract Drawable class)
     * @param targetWindow (display window)
     */
    virtual void drawOn(sf::RenderTarget& targetWindow) const;

    /*!
     * @brief update the bacteria (vitual method inherited from the abstract Updatable class)
     *        make the bacteria move thanks to call to the move method
     *        make the bacteria eat nutriments
     *        make the bacteria divide (random)
     *
     * @param dt (sf::Time)
     */
    virtual void update(sf::Time dt);

    /*!
     * @brief must be overrided by subClasses to make a bacteria move
     * @param dt (sf::Time)
     */
    virtual void move(sf::Time dt) =0;

    /*!
     * @brief must be overrided by subClasses to create a new bacteria pointer based on the current instance
     * @return a bacteria pointer to a clone of the current instance
     */
    virtual Bacterium* clone() const =0;

    /*!
     * @brief shortcut to access to getAppEnv() which must be overrided by subClasses to be used
     * @return a j::Value stored in the app.json file
     */
    virtual j::Value& getConfig() const =0;

    /*!
     * @brief tells us if the bacteria is still alive
     * @return true if the bacteria has a positive energy
     */
    bool alive() const;

    /*!
     * @brief withdraw some quantity of energy to the bacteria
     * @param qt (Quantity = double)
     */
    void consumeEnergy(Quantity qt);

    /*!
     * @brief add a property to the parameters of the bacteria
     * @param name (string)
     * @param m (MutableNumber)
     */
    void addProperty(const std::string&name, MutableNumber m);

    /*!
     * @brief access to a property thanks to its name
     *
     * @param name (string)
     *
     * @return a MutableNumber linked to the name
     */
    MutableNumber getProperty(const std::string& name) const;

    /*!
     * @brief call the mutate method of the MutableNumber class on each element of parametres and also on the couleur
     * @return a pointer on the new bacteria (either modified or not)
     */
    Bacterium* mutate();

    /*!
     * @brief if the bacteria has enough energy, it can produce a copy of itself with clone
     *        then the bacteria changes its direction to the opposite
     */
    void divide();

    /*!
     * @brief access to the minimum of energy a bacteria needs to divide
     * @return the EnergyMin (Quantity = double)
     */
    Quantity getEnergieMin() const;

    /*!
     * @brief access to the time between 2 "meals" of the bacteria (value from app.json)
     * @return the time before it can eat again a nutriment
     */
    sf::Time getDelay() const;

    /*!
     * @brief access to the energy withdraw to the bacteria at each "time"
     * @return the quantity taken to the bacteria
     */
    Quantity getConsumption() const;

    /*!
     * @brief access to the current direction of the bacteria
     * @return the direction as a Vec2d
     */
    Vec2d getDirection()const;

    /*!
     * @brief method to change the direction from the subClasses as its a private attribute
     * @param new direction
     */
    void setDirection(Vec2d dir);

    /*!
     * @brief access to the current angle of direction
     * @return the angle as a double
     */
    double getAngleDir()const;

    /*!
     * @brief method to change the angle of direction from the subClasses as its a private attribute
     * @param new angle
     */
    void setAngleDir(double angle);

    /*!
     * @brief access to the score of the bacteria's position
     * @return the score
     */
    double getScore() const;

    /*!
     * @brief access to the color of the bacteria (conversion from MutableColor to sf::Color)
     * @return color (sf::Color)
     */
    sf::Color getColor() const;

    /*!
     * @brief select best of 20 randow direction depending on score and set it as the new direction
     */
    void newDirection();

private:
    Quantity energie;                                   ///< energy of the bacteria
    Vec2d direction;                                    ///< direction
    MutableColor couleur;                               ///< color
    bool abstinence;                                    ///< true = the bacteria can eat
    sf::Time compteur;                                  ///< time between 2 meals
    std::map<std::string, MutableNumber> parametres;    ///< list of parameters
    double angleDir;                                    ///< direction angle
};


#endif // BACTERIUM_HPP
