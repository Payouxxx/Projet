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

class Stats: public Drawable, public Updatable
{
public:
    Stats();
    ~Stats();
    std::string getCurrentTitle() const;
    void next();
    void previous();
    void update(sf::Time dt) override;
    void drawOn(sf::RenderTarget &target) const override;
    void reset();
    void addGraph(int idGraph, std::string const& title, std::vector<std::string> const& series, double min, double max, Vec2d size);
    void setActive(int id);
private:
    std::map<int, std::string> names;
    int idActif;
    Label graphes;
    sf::Time dt;
};

