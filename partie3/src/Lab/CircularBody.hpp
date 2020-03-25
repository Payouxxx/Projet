#pragma once
#include <Utility/Vec2d.hpp>
#include <iostream>

class CircularBody
{
public:
    CircularBody(const Vec2d& coordCentre, double rayon); //constructeur
    /*!
     * \brief getPosition
     * \return
     */
    const Vec2d& getPosition() const;
    double getRadius()const;

    bool contains(const CircularBody& other)const;
    // true si instance contient CircularBody (other dans instance)
    bool isColliding(const CircularBody& other)const;
    // true si CircularBody en collision avec instance
    bool contains(const Vec2d& point)const;
    // true si l'instance contient le point

    CircularBody& operator =(const CircularBody& other);
    CircularBody& move(const Vec2d& add); //ajout d'une position

protected:
    CircularBody(const CircularBody& other); //constructeur copie
    void setPosition(const Vec2d& position);
    void setRadius(double rayon);

private:
    Vec2d centre;
    double radius;

};

bool operator>(const CircularBody& body1, const CircularBody& body2);
bool operator&(const CircularBody& body1, const CircularBody& body2);
bool operator>(const CircularBody& body1, const Vec2d& point) ;
std::ostream& operator<<(std::ostream& sortie, const CircularBody& other);
