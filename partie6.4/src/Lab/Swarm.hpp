#ifndef SWARM_HPP
#define SWARM_HPP

#include "Interface/Updatable.hpp"
#include <vector>
#include "Utility/Vec2d.hpp"
#include <SFML/Graphics.hpp>
#include "Utility/MutableColor.hpp"

class SwarmBacterium;

/*!
 * @brief Class Swarm sub class of Updatable, modeling a group of SwarmBacterium
 */

class Swarm : public Updatable
{
public:
    /*!
     * @brief Constructor
     * @param number of the swarm (identificator, std::string)
     */
    Swarm(std::string id);

    /*!
     * @brief add a bacteria in the swarm
     * @param pointer on SwarmBacterium added
     */
    void addSwarmBacterium(SwarmBacterium* bacteria);

    /*!
     * @brief remove a bacteria from the swarm
     * @param pointer on SwarmBacterium removed
     */
    void removeSwarmBacterium(const SwarmBacterium *bacteria);

    /*!
     * @brief get the position of the leader bacteria in the group
     * @return leader position (Vec2d)
     */
    Vec2d getPositionLeader() const;

    /*!
     * @brief get original color of the swarm (before mutation)
     * @return Mutable color
     */
    MutableColor getOriginalColor() const;

    /*!
     * @brief redefinition of the virtual method update, changes leader
     * @param dt (sf::Time), intervall of evolution
     */
    void update(sf::Time dt) override;

    /*!
     * @brief get number of the swarm
     * @return identifcator (std::string)
     */
    std::string getIdentificator() const;

    /*!
     * @brief virtual destructor (delete all abcteria and clear tab)
     */
    ~Swarm();

    int getSize() const;

private:
    std::string identificateur;                ///< number of the swarm
    std::vector<SwarmBacterium*> bacteries;    ///< bacteria which are part of the swarm
    SwarmBacterium* leader;                    ///< leader of the swarm (attracts others)
};

#endif // SWARM_HPP
