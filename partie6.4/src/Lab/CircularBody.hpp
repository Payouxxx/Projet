#pragma once
#include <Utility/Vec2d.hpp>
#include <iostream>

/*!
 * @brief The CircularBody class representing every circular element
 */
class CircularBody
{
public:
    /*!
     * @brief Constructor
     * @param coordCentre
     * @param rayon
     */
    CircularBody(const Vec2d& coordCentre, double rayon);

    /*!
     * @brief Destructor
     */
    virtual ~CircularBody();

    /*!
     * @brief access to the position (center of the CircularBody)
     * @return position
     */
    const Vec2d& getPosition() const;

    /*!
     * @brief access to the radius
     * @return radius
     */
    double getRadius()const;

    /*!
     * @brief check if a Circular body is contained in another
     * @param other (CircularBody)
     * @return true if the current instance contains other
     */
    bool contains(const CircularBody& other)const;

    /*!
     * @brief check if 2 CircularBodies are colliding
     * @param other (CircularBody)
     * @return true if other is colliding with the current instance
     */
    bool isColliding(const CircularBody& other)const;

    /*!
     * @brief check if a point is contained in a CircularBody
     * @param point (Vec2d)
     * @return true if the point is inside the CircularBody
     */
    bool contains(const Vec2d& point)const;

    /*!
     * @brief assignement operator for a CiruclarBody
     * @param other (CiruclarBody)
     * @return a reference to the current instance
     */
    CircularBody& operator =(const CircularBody& other);

    /*!
     * @brief add a position to the current instance
     * @param add (Vec2d)
     * @return a reference to the modified current instance
     */
    CircularBody& move(const Vec2d& add);


protected:
    /*!
     * @brief copy constructor
     * @param other(CiruclarBody)
     */
    CircularBody(const CircularBody& other);

    /*!
     * @brief set the position of the current instance thanks to a parameter
     * @param position (Vec2d)
     */
    void setPosition(const Vec2d& position);

    /*!
     * @brief set the radius of the current instance thanks to a parameter
     * @param rayon (double)
     */
    void setRadius(double rayon);

private:
    Vec2d position;  ///< position (center)
    double radius;   ///< radius

};

/*!
 * @brief operator > use of the contains method
 * @param body1 (CiruclarBody)
 * @param body2 (CiruclarBody)
 * @return true if body1 contains body2
 */
bool operator>(const CircularBody& body1, const CircularBody& body2);

/*!
 * @brief operator & use of the isColliding method
 * @param body1 (CiruclarBody)
 * @param body2 (CiruclarBody)
 * @return true if body1 and body2 are colliding
 */
bool operator&(const CircularBody& body1, const CircularBody& body2);
/*!
 * @brief operator > use of the second contains method
 * @param body1 (CircularBody)
 * @param point (Vec2d)
 * @return true if body1 contains the point
 */
bool operator>(const CircularBody& body1, const Vec2d& point) ;

/*!
 * @brief operator << cout "CircularBody: position = position radius = radius"
 * @param outstream (flot de sortie)
 * @param other (CircularBody)
 * @return display other as a CircularBody
 */
std::ostream& operator<<(std::ostream& sortie, const CircularBody& other);
