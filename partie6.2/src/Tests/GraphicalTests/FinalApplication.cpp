/*
 * prjsv 2020
 * Marco Antognini & Jamila Sam
 */

#include <Config.hpp>
#include <Lab/SimpleBacterium.hpp>
#include <Lab/Swarm.hpp>
#include <Lab/SwarmBacterium.hpp>
#include <Lab/TwitchingBacterium.hpp>
#include <Lab/NutrimentA.hpp>
#include <Lab/NutrimentB.hpp>
#include "FinalApplication.hpp"

#include <cassert>
#include <iostream>

IMPLEMENT_MAIN(FinalApplication);

void FinalApplication::onRun()
{
    // Basic setup
    Application::onRun();
	// add graphs for statistics
    setStats(true);
    addGraph(s::GENERAL, { s::SIMPLE_BACTERIA, s::TWITCHING_BACTERIA, s::SWARM_BACTERIA, s::NUTRIMENT_SOURCES,s::DISH_TEMPERATURE}, 0, 150);
    addGraph(s::NUTRIMENT_QUANTITY, {s::NUTRIMENT_QUANTITY}, 0, 500); //min réduit pour graphe plus parlant
    addGraph(s::SIMPLE_BACTERIA, { s::BETTER, s::WORSE}, 0, 10);
    addGraph(s::TWITCHING_BACTERIA, { s::TENTACLE_LENGTH, s::TENTACLE_SPEED}, 0, 150);
    addGraph(s::BACTERIA, { s::SPEED}, 20, 50);
    setActiveGraph(0);
}

void FinalApplication::onSimulationStart()
{
    Application::onSimulationStart();
    for (auto i = 1; i <= 5; ++i) {
        auto id = std::to_string(i);
        getEnv().addSwarm(new Swarm(id));
    }
}

void FinalApplication::onEvent(sf::Event event, sf::RenderWindow&)
{
    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
        default:
            break;

        case sf::Keyboard::S:
            getEnv().addBacterium(new SimpleBacterium(getCursorPositionInView()));
            break;

        case sf::Keyboard::A:
            getEnv().addADN(new ADN(30, getCursorPositionInView()));
            break;

        case sf::Keyboard::L:
            if (getEnv().lightOn()) setState(false);
            else setState(true);
            break;

        case sf::Keyboard::T:
            getEnv().addBacterium(new TwitchingBacterium(getCursorPositionInView()));
            break;

        case sf::Keyboard::Num1: {
            auto swarm = getEnv().getSwarmWithId("1");
            assert(swarm != nullptr);
            getEnv().addBacterium(new SwarmBacterium(getCursorPositionInView(), swarm));
        } break;

        case sf::Keyboard::Num2: {
            auto swarm = getEnv().getSwarmWithId("2");
            assert(swarm != nullptr);
            getEnv().addBacterium(new SwarmBacterium(getCursorPositionInView(), swarm));
        } break;

        case sf::Keyboard::Num3: {
            auto swarm = getEnv().getSwarmWithId("3");
            assert(swarm != nullptr);
            getEnv().addBacterium(new SwarmBacterium(getCursorPositionInView(), swarm));
        } break;

        case sf::Keyboard::Num4: {
            auto swarm = getEnv().getSwarmWithId("4");
            assert(swarm != nullptr);
            getEnv().addBacterium(new SwarmBacterium(getCursorPositionInView(), swarm));
        } break;

        case sf::Keyboard::Num5: {
            auto swarm = getEnv().getSwarmWithId("5");
            assert(swarm != nullptr);
            getEnv().addBacterium(new SwarmBacterium(getCursorPositionInView(), swarm));
        } break;

        case sf::Keyboard::N: {
            constexpr int NUT_QTY(50);
            Nutriment* lastCreated = nullptr;
            if (event.key.shift) {
                lastCreated = new NutrimentB(NUT_QTY, getCursorPositionInView());
            } else {
                lastCreated = new NutrimentA(NUT_QTY, getCursorPositionInView());
            }
            getEnv().addNutriment(lastCreated);
          } break;
        }
    }
}

