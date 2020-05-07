#pragma once

#include "../Interface/Drawable.hpp"
#include "../Interface/Updatable.hpp"
#include <vector>
#include <memory>
#include <string>
#include "Utility/Types.hpp"
#include <iostream>
#include "Graph.hpp"
#include <SFML/Graphics.hpp>

typedef std::map<std::string, std::unique_ptr<Graph>> Label;



/*!
 * @brief The Bacterium class, a subClass of Drawable and Updatable
 */
class Stats: public Drawable, public Updatable
{
public:
    /*!
     * @brief Constructor, initialises idActif to 0 and time to sf::Time::Zero
     */
    Stats();

    /*!
     * @brief destructor, does nothing
     */
    ~Stats();

    /*!
     * @brief use current id to return current graph
     * @return string (current title of the graph)
     */
    std::string getCurrentTitle() const;

    /*!
     * @brief increments current id (changes current graph) modulo the number of possible graphs
     */
    void next();

    /*!
     * @brief decreases current id (changes current graph) modulo the number of possible graphs
     */
    void previous();

    /*!
     * @brief update the current graph every specific amount of time
     *        (vitual method inherited from the abstract Updatable class)
     * @param dt (sf::Time)
     */
    void update(sf::Time dt) override;

    /*!
     * @brief draw the current graph on the target (virtual method inherited from the abstract Drawable class)
     * @param target (display window)
     */
    void drawOn(sf::RenderTarget &target) const override;

    /*!
     * @brief reset current graph
     */
    void reset();

    /*!
     * @brief add a new graph in the stats
     * @param int id (becomes new current id)
     *        string (title of the new graph)
     *        series of title (param to create the graph)
     *        double min (param to create the graph)
     *        double max (param to create the graph)
     *        Vec2d size (param to create the graph)
     */
    void addGraph(int idGraph, std::string const& title, std::vector<std::string> const& series, double min, double max, Vec2d size);

    /*!
     * @brief set the current id to the id given
     * @param int
     */
    void setActive(int id);
private:
    std::map<int, std::string> names;  ///< associative table of id and names of possible graphs
    int idActif;                       ///< id current graph shown
    Label graphes;                     ///< associative table of names and pointers of graph of possible graph
    sf::Time dt;                       ///< time between updates
};

