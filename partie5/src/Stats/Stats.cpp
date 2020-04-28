#include <Stats/Stats.hpp>
#include <iostream>
#include "../Application.hpp"

using namespace std;

Stats::Stats() : idActif(0)
{}

Stats::~Stats() {}

void Stats::next()
{
    if(idActif == int(names.size())) {
        idActif=0;
    } else {
        ++idActif;
    }
}

void Stats::previous()
{
    if(idActif==0) {
        idActif=names.size();
    } else {
        --idActif;
    }
}

string Stats::getCurrentTitle() const
{
    try {
        auto paire = names.find(idActif);
        return paire->second;
    } catch(out_of_range) {
        cerr << "out of range";
    } catch(invalid_argument){
        cerr << "invalid argument";
    }
}

void Stats::reset()
{
    Label::iterator it = graphes.begin();
    while(it != graphes.end()){
        (it->second)->reset();
        ++it;
    }
}

void Stats::addGraph(int idGraph, const string &title, const std::vector<string> &series, double min, double max, Vec2d size)
{
    try {
        auto paire = names.find(idGraph);
        auto couple = graphes.find(paire->second);
        (couple->second)->reset();
        (couple->second) = unique_ptr<Graph(new Graph(series, size, min, max))>;
        (paire->second) = title;
        idActif = idGraph;
    } catch(out_of_range) {
        cerr << "out of range";
    } catch(invalid_argument){
        cerr << "invalid argument";
    }
}

void Stats::update(sf::Time dt)
{
    this->dt+=dt;

    if(this->dt >= sf::seconds(getAppConfig()["stats"]["refresh rate"].toDouble())){
        for(auto& graphe : graphes){
            (graphe.second)->updateData(this->dt, getAppEnv().fetchData(getCurrentTitle()));
        }
    }
}

void Stats::drawOn(sf::RenderTarget &target) const
{
    for(auto& couple : graphes){
        (couple.second)->drawOn(target);
    }
}

void Stats::setActive(int id)
{
    idActif = id;
}
