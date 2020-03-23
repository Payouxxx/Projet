#include "MutableNumber.hpp"
#include <iostream>
#include "Random/Random.hpp"
#include "../Application.hpp"
#include "../Config.hpp"
#include "Utility/Utility.hpp"

using namespace std;

MutableNumber::MutableNumber(double val, double p, bool Inf, bool Sup, double std, double min, double max)
    :value(val), pMutation(p), borneInf(Inf), borneSup(Sup), sigma(std), min(min), max(max) {}

MutableNumber::MutableNumber(const j::Value &config)
    :value(config["initial"].toDouble()), pMutation(config["rate"].toDouble()), borneInf(config["clamp min"].toBool()),
      borneSup(config["clamp max"].toBool()), sigma(config["sigma"].toDouble()), min(config["min"].toDouble()), max(config["max"].toDouble())
{set(config["initial"].toDouble());}

double MutableNumber::get() const
{
    return value;
}

void MutableNumber::set(double val)
{
    value = val;
    if(value<min){
        value = min;
    }
    if(value>max){
        value = max;
    }
}

void MutableNumber::mutate()
{
    if(bernoulli(pMutation)) {
        value += normal(0, sigma*sigma);
    }
}

MutableNumber MutableNumber::probability(const j::Value &config)
{
    MutableNumber new;
    return new;
}

MutableNumber MutableNumber::probability(double initialValue, double mutationProbability, double sigma)
{
    MutableNumber new;
    return new;
}

MutableNumber MutableNumber::positive(double initialValue, double mutationProbability, double sigma, bool hasMax, double max)
{
    MutableNumber new;
    return new;
}

MutableNumber MutableNumber::positive(const j::Value &config, bool hasMax, double max)
{
    MutableNumber new;
    return new;
}
