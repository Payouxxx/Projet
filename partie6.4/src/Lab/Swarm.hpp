#ifndef SWARM_HPP
#define SWARM_HPP

#include "Interface/Updatable.hpp"
#include <vector>
#include "Utility/Vec2d.hpp"
#include <SFML/Graphics.hpp>
#include "Utility/MutableColor.hpp"

class SwarmBacterium;

/*!
 * @brief Class Swarm, subclass of Updatable, modeling a group of SwarmBacterium
 */

class Swarm : public Updatable
{
public:
    /*!
     * @brief Constructor
     * @param id of the swarm (std::string)
     */
    Swarm(std::string id);

    /*!
     * @brief add a bacterium in the swarm
     * @param pointer on SwarmBacterium added
     */
    void addSwarmBacterium(SwarmBacterium* bacterium);

    /*!
     * @brief remove a bacterium from the swarm
     * @param pointer on SwarmBacterium removed
     */
    void removeSwarmBacterium(const SwarmBacterium *bacterium);

    /*!
     * @brief get the position of the leader bacterium in the group
     * @return leader position (Vec2d)
     */
    Vec2d getPositionLeader() const;

    /*!
     * @brief get original color of the swarm (before mutation)
     * @return Mutable color
     */
    MutableColor getOriginalColor() const;

    /*!
     * @brief redefinition of the virtual method update, changes leader depending on score
     * @param dt (sf::Time), intervall of evolution
     */
    void update(sf::Time dt) override;

    /*!
     * @brief get id of the swarm
     * @return identifcator (std::string)
     */
    std::string getIdentificator() const;

    /*!
     * @brief virtual destructor (delete all the bacteria and clear tab)
     */
    ~Swarm();

    /*!
     * @brief getConfig to access to some values in the app.json file associated to the swarms
     * @return getAppConfig()["swarms"][identificateur]
     */
    j::Value& getConfig() const;

private:
    std::string identificateur;                ///< id of the swarm
    std::vector<SwarmBacterium*> bacteries;    ///< bacteria which are part of the swarm
    SwarmBacterium* leader;                    ///< leader of the swarm (attracts others)
    Vec2d directionPoison;                     ///< direction the poisons thrown will take
    double timePoison;                         ///< time before throwing another piece of poison
};

#endif // SWARM_HPP
