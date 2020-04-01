#include "CircularBody.hpp"
#include <iostream>

using namespace std;

CircularBody::CircularBody(const Vec2d& coordCentre, double rayon) //constructeur
    : centre(coordCentre), radius(rayon) {}

CircularBody::CircularBody(const CircularBody& other) //constructeur copie
    : centre(other.centre), radius(other.radius) {}

CircularBody::~CircularBody() {}

const Vec2d& CircularBody::getPosition() const{
    return centre;
}

void CircularBody::setPosition(const Vec2d& position){
    centre=position;
}
double CircularBody::getRadius() const{
    return radius;
}

void CircularBody::setRadius(double rayon){
    radius=rayon;
}

CircularBody& CircularBody::operator=(const CircularBody &other){
    centre=other.centre;
    radius=other.radius;
    return *this;
}

CircularBody& CircularBody:: move(const Vec2d& add){
    centre += add;
    return *this;
}

bool CircularBody::contains(const CircularBody& other)const {
    double difference(radius-other.radius);
    double dist (distance(centre, other.centre));
    return (difference>=0 and dist<=difference);
}

bool CircularBody::isColliding(const CircularBody& other)const {
    double somme(radius+other.radius);
    double dist (distance(centre, other.centre));
    return (dist<=somme);
}

bool CircularBody::contains(const Vec2d& point)const {
    return (distance(point, centre) <= radius);
}

bool operator>(const CircularBody& body1, const CircularBody& body2) {
    return body1.contains(body2);
}

bool operator&(const CircularBody& body1, const CircularBody& body2){
    return body1.isColliding(body2);
}

bool operator>(const CircularBody& body, const Vec2d& point) {
    return body.contains(point);
}

ostream& operator<<(ostream& out, const CircularBody& other) {
    out << "CircularBody: position = " << other.getPosition()
        << " radius = " << other.getRadius() << endl;
    return out;
}
