#ifndef SWARM_HPP
#define SWARM_HPP

#include "Interface/Updatable.hpp"
#include <vector>
#include "Utility/Vec2d.hpp"
#include <SFML/Graphics.hpp>

class SwarmBacterium; //prédeclaration de classe pour casser
// dépendance circulaire

class Swarm : public Updatable
{
public:
    Swarm(std::string id);
    void addSwarmBacterium(SwarmBacterium* bacteria);
    void removeSwarmBacterium(SwarmBacterium* bacteria);
    Vec2d getPositionLeader() const;
    sf::Color getOriginalColor() const;
    void update(sf::Time dt);

    std::string getIdentificator() const;
    ~Swarm();
private:
    std::string identificateur;
    std::vector<SwarmBacterium*> bacteries;
    SwarmBacterium* leader; //pas sure pour le pointeur
};

#endif // SWARM_HPP
