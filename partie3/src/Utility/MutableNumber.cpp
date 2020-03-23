#include "MutableNumber.hpp"
#include <iostream>
#include "Random/Random.hpp"
#include "../Application.hpp"

using namespace std;

MutableNumber::MutableNumber(double val, double p, bool Inf, bool Sup, double std, double min, double max)
    :value(val), pMutation(p), borneInf(Inf), borneSup(Sup), sigma(std), min(min), max(max) {}

MutableNumber::MutableNumber(const j::Value &config)
    :value(config["initial"].toDouble()), pMutation(config["rate"].toDouble()), borneInf(config["clamp min"].toBool()),
      borneSup(config["clamp max"].toBool()), sigma(config["sigma"].toDouble()), min(config["min"].toDouble()), max(config["max"].toDouble())
{setValue(config["initial"].toDouble());}

double MutableNumber::getValue() const
{
    return value;
}

void MutableNumber::setValue(double val)
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


