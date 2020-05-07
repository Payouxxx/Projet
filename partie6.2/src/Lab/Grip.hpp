#ifndef GRIP_HPP
#define GRIP_HPP

#include "CircularBody.hpp"

/*!
 * @brief The Grip class
 */
class Grip : public CircularBody
{
public:
    /*!
     * @brief Constructor
     * @param position
     * @param rayon
     */
    Grip(Vec2d position, double rayon);

    /*!
     *@brief destructor
     */
    ~Grip();

    /*!
     * @brief move method of a grip, calling the move of CircularBody
     * @param add (Vec2d)
     */
    void move(const Vec2d &add);
};

#endif // GRIP_HPP
