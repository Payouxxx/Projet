#include <Stats/Stats.hpp>
#include <iostream>
#include "../Application.hpp"

using namespace std;

Stats::Stats() : idActif(0)
{}

Stats::~Stats() {}

void Stats::next()
{
    if(idActif == int(names.size() -1)) {
        idActif=0;
    } else {
        ++idActif;
    }
}

void Stats::previous()
{
    if(idActif==0) {
        idActif=(names.size() -1);
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
    setActive(idGraph);
    names[idGraph] = title;
    unique_ptr<Graph> pointeur;
    pointeur.reset(new Graph(series, size, min, max));
    graphes[title] = std::move(pointeur);
}

void Stats::update(sf::Time dt)
{
    this->dt+=dt;

    if(this->dt >= sf::seconds(getAppConfig()["stats"]["refresh rate"].toDouble())){
        for(auto& graphe : graphes){
            (graphe.second)->updateData(this->dt, getAppEnv().fetchData(getCurrentTitle()));
        }
        this->dt = sf::Time::Zero;
    }
}

void Stats::drawOn(sf::RenderTarget &target) const
{
    string name(names.at(idActif));
    (graphes.at(name))->drawOn(target);
}

void Stats::setActive(int id)
{
    idActif = id;
}
