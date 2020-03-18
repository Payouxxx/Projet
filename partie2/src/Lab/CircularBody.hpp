#pragma once
#include <Utility/Vec2d.hpp>
#include <iostream>

class CircularBody
{
public:
    CircularBody(const Vec2d& coordCentre, double rayon); //constructeur
    CircularBody(const CircularBody& other); //constructeur copie
    /*!
     * \brief getPosition
     * \return
     */
    const Vec2d& getPosition() const;
    void setPosition(const Vec2d& position);
    double getRadius()const;
    void setRadius(double rayon);

    CircularBody& operator =(const CircularBody& other);
    CircularBody& move(const Vec2d& add); //ajout d'une position

    bool contains(const CircularBody& other)const;
    bool isColliding(const CircularBody& other)const;
    bool contains(const Vec2d& point)const;

protected:
    Vec2d centre;
    double radius;

};

bool operator>(const CircularBody& body1, const CircularBody& body2);
bool operator&(const CircularBody& body1, const CircularBody& body2);
bool operator>(const CircularBody& body1, const Vec2d& point) ;
std::ostream& operator<<(std::ostream& sortie, const CircularBody& other);
