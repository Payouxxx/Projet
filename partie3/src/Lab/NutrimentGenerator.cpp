#include "NutrimentGenerator.hpp"
#include "Random/Random.hpp"
#include "../Application.hpp"
#include "NutrimentA.hpp"
#include "NutrimentB.hpp"
#include "../Config.hpp"

using namespace std;
using namespace sf;

NutrimentGenerator::NutrimentGenerator()
    : dt(Time::Zero) {}

void NutrimentGenerator::update(Time dt){
    this->dt+=dt; //incrémente le temps

    if(this->dt>=sf::seconds(getAppConfig()["generator"]["nutriment"]["delay"].toDouble())) {
        reset();

        //condition selon laquelle nutriment A/B choisis (proba)
        bool A(bernoulli(getAppConfig()["generator"]["nutriment"]["prob"].toDouble()));

        //position aléatoire du centre suivant loi normale
        Vec2d tailleEnv(getApp().getLabSize());
        Vec2d centreAleatoire(normal(tailleEnv.x/2.0, tailleEnv.x/4.0*tailleEnv.x/4.0), normal(tailleEnv.y/2.0, tailleEnv.y/4.0*tailleEnv.x/4.0));
        Nutriment* nouveau;
        if (A) { //génère A par le pointeur nouveau
            Quantity qte(uniform(getShortConfig().nutrimentA_min_qty, getShortConfig().nutrimentA_max_qty));
            nouveau = new NutrimentA(qte, centreAleatoire);
        }
        else { // génère B par le pointeur nouveau
            Quantity qte(uniform(getShortConfig().nutrimentB_min_qty, getShortConfig().nutrimentB_max_qty));
            nouveau = new NutrimentB(qte, centreAleatoire);
        }
        getAppEnv().addNutriment(nouveau);
    }
}

void NutrimentGenerator::reset() {
    dt = Time::Zero;
}
