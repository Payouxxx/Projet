#ifndef MUTABLENUMBER_HPP
#define MUTABLENUMBER_HPP
#include "JSON/JSONImpl.hpp"
#include "../Config.hpp"
#include "Utility/Utility.hpp"

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
    double getValue() const;
    void setValue(double val); //modifie la valeur tout en restant entre min et max
    void mutate(); //entraine un changement de la valeur selon un nombre tiré aléatoirement
    MutableNumber probability(double initialValue, double mutationProbability, double sigma);
};

#endif // MUTABLENUMBER_HPP
