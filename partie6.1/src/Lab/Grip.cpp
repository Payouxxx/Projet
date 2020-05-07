#include "Grip.hpp"

Grip::Grip(Vec2d position, double rayon)
    : CircularBody(position, rayon)
{}

Grip::~Grip() {}

void Grip::move(const Vec2d &add)
{
    CircularBody::move(add);
}
