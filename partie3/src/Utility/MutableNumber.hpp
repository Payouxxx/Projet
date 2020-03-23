#ifndef MUTABLENUMBER_HPP
#define MUTABLENUMBER_HPP
#include "JSON/JSONImpl.hpp"

class MutableNumber {
private:
    double value;
    double pMutation; //probabilité : double positif entre 0 et 1
    bool borneInf;
    bool borneSup;
    double sigma;
    double min;
    double max;
public:
    MutableNumber(double val, double p, bool Inf, bool Sup, double std, double min, double max);
    MutableNumber(const j::Value &config);
    double get() const;
    void set(double val); //modifie la valeur tout en restant entre min et max
    void mutate(); //entraine un changement de la valeur selon un nombre tiré aléatoirement
    MutableNumber probability(double initialValue, double mutationProbability, double sigma);
    MutableNumber probability(j::Value const& config);
    MutableNumber positive(double initialValue, double mutationProbability, double sigma, bool hasMax, double max);
    MutableNumber positive(j::Value const& config, bool hasMax, double max);
};

#endif // MUTABLENUMBER_HPP
