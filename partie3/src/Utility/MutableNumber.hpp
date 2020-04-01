#ifndef MUTABLENUMBER_HPP
#define MUTABLENUMBER_HPP
#include "JSON/JSONImpl.hpp"

class MutableNumber {
private:
    double value;
    double pMutation; //probabilité : double positif entre 0 et 1
    double sigma;
    bool borneInf;
    double min;
    bool borneSup;
    double max;
public:
    MutableNumber(double val, double p, double std, bool Inf=false, double min=0, bool Sup=false, double max=0);
    MutableNumber(const j::Value &config);
    MutableNumber() = default;
    double get() const; //get valeur
    void set(double val); //modifie la valeur tout en restant entre min et max
    void mutate(); //entraine un changement de la valeur selon un nombre tiré aléatoirement
    static MutableNumber probability(double initialValue, double mutationProbability, double sigma);
    static MutableNumber probability(j::Value const& config);
    static MutableNumber positive(double initialValue, double mutationProbability, double sigma, bool hasMax=false, double max=0);
    static MutableNumber positive(j::Value const& config, bool hasMax=false, double max=0);
};

#endif // MUTABLENUMBER_HPP
