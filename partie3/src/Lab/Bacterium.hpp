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
    Bacterium(Quantity nrj, Vec2d position, Vec2d dir, double rayon, MutableColor color);

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
    MutableNumber getProperty(const std::string& name) const;
    Bacterium *mutate();
    void divide();

    Quantity getEnergieMin() const;
    sf::Time getDelay() const;
    Quantity getConsumption() const;
    Vec2d getDirection()const;
    void setDirection(Vec2d dir);
    double getAngleDir()const;
    void setAngleDir(double angle);
    double getScore() const;
    double getpBasculement() const;
    void setpBasculement(double p);

private:
    Quantity energie;
    Vec2d direction;
    MutableColor couleur;
    bool abstinence;
    sf::Time compteur; //temps entre 2 consommation nutriments
    std::map<std::string, MutableNumber> parametres;
    double angleDir;
    double pBasculement;

};


#endif // BACTERIUM_HPP
