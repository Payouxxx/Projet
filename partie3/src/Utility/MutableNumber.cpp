#include "MutableNumber.hpp"
#include <iostream>
#include "Random/Random.hpp"
#include "../Application.hpp"
#include "../Config.hpp"
#include "Utility/Utility.hpp"
#include <../Utility/Types.hpp>

using namespace std;

MutableNumber::MutableNumber(double val, double p, double std, bool Inf, double min, bool Sup, double max)
    :value(val), pMutation(p), sigma(std), borneInf(Inf), min(min), borneSup(Sup), max(max) {}

MutableNumber::MutableNumber(const j::Value &config)
    : value(config["initial"].toDouble()),
      pMutation(config["rate"].toDouble()),
      sigma(config["sigma"].toDouble()),
      borneInf(config["clamp min"].toBool()),
      min(config["min"].toDouble()),
      borneSup(config["clamp max"].toBool()),
      max(config["max"].toDouble())
{}

double MutableNumber::get() const
{
    return value;
}

void MutableNumber::set(double val)
{
    value = val;
    if (borneInf and value<min){
        value = min;
    }
    if (borneSup and value>max){
        value = max;
    }
}

void MutableNumber::mutate()
{
    if(bernoulli(pMutation)) {
        set(value += normal(0, sigma*sigma));
    }
}

MutableNumber MutableNumber::probability(const j::Value &config)
{
    MutableNumber nom(config);
    nom.set(nom.value);
    return nom;
}

MutableNumber MutableNumber::probability(double initialValue, double mutationProbability, double sigma)
{
    return MutableNumber(initialValue, mutationProbability, sigma, true, 0, true, 1);
}

MutableNumber MutableNumber::positive(double initialValue, double mutationProbability, double sigma, bool hasMax, double max)
{
    return MutableNumber(initialValue, mutationProbability, sigma, true, 0, hasMax, max);
}

MutableNumber MutableNumber::positive(const j::Value &config, bool hasMax, double max)
{
    return MutableNumber(config["initial"].toDouble(), config["rate"].toDouble(), config["sigma"].toDouble(), true, 0, hasMax, max);
}
