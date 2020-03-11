#pragma once
#include "Utility/Vec2d.hpp"
#include <iostream>

class CircularBody
{
public:
    CircularBody(const Vec2d& coordCentre, double rayon) //constructeur
        : centre(coordCentre), radius(rayon) {}
    CircularBody(const CircularBody& other) //constructeur de copie
        : centre(other.centre), radius(other.radius) {}

    const Vec2d& getPosition()const;
    void setPosition(const Vec2d& position);
    double getRadius() const;
    void setRadius(double rayon);

    CircularBody& operator =(const CircularBody& other);

    CircularBody& move(const Vec2d& add); //ajout d'une position à l'instance courante
    bool contains(const CircularBody& other) const; //retourne vrai si l'instance courante contient other
    bool isColliding(const CircularBody& other) const; //retourne vrai si les 2 objets entrent en collision
    bool contains(const Vec2d& point) const; //retourne vrai si un point est contenu dans l'instance cournante

private:
    Vec2d centre;
    double radius;
};

bool operator >(const CircularBody& body1, const CircularBody& body2); //true-->body2 inclus dans body1
bool operator &(const CircularBody& body1, const CircularBody& body2); //true-->body2 en collision avec body1
bool operator >(const CircularBody& body, const Vec2d& point); //true-->point inclus dans body1
std::ostream& operator <<(std::ostream& out, const CircularBody& other); //

