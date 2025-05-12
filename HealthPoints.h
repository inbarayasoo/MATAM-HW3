#ifndef EX33_HEALTHPOINTS_H
#define EX33_HEALTHPOINTS_H

#include <iostream>
static const int DEFAULT_MAX_HP = 100;

class HealthPoints{
public:
    /*
        * throw exception when maxHealthPoint is invalid (small or equal to 0)
     */
    class InvalidArgument {};
    /*
        * Constructor of the HealthPoints class:
        * @param maxHealthPoint - MaxHealthPoint of player.
        * @result
        *      An instance of HealthPoints
    */
    HealthPoints(int maxHealthPoint = DEFAULT_MAX_HP);
    /*
        * Copy C'tor of the HealthPoints:
        * @param healthPoint - Reference to other object to copy from.
        * @result
        *      An copy of the object
    */
    HealthPoints(const HealthPoints& healthPoint) = default;
    /*
        * Assignment operator of the HealthPoints:
        * @param healthPoint - Assignment between two HealthPoints objects.
        * @result
        *      An object with the assigned parameters
    */
    HealthPoints& operator=(const HealthPoints& healthPoint) =default;
    /*
        * Destructor for the HealthPoints class.
    */
    ~HealthPoints() = default;
    /*
    * operator == of the HealthPoints:
    * @param healthPoint1, healthPoint2 - Compare between the current hp points of two objects.
    * @result
    *      true - if current hp points of two objects are equals, otherwise false.
    */
    friend bool operator==(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2);
    /*
        * operator < of the HealthPoints:
        * @param healthPoint1, healthPoint2 - Check between two objects which object has the higher current hp points.
        * @result
        *      true - if current hp points of hp1 is smaller than hp2, otherwise false.

    */
    friend bool operator<(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2);
    /*
        * operator << of the HealthPoints:
        * @param os, healthPoint - Print the current hp points and max hp points of an object.
        * @result
        *      ostream
    */
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoint);
    /*
        * operator += of the HealthPoints:
        * @param addHealthPoint - Add hp points to the current hp of the object.
        * @result
        *      an object with the added health points.
    */
    HealthPoints& operator+=(int addHealthPoint);
    /*
        * operator -= of the HealthPoints:
        * @param decreaseHealthPoint - Decrease hp points from the current hp of the object.
        * @result
        *      an object with decrease health points.
    */
    HealthPoints& operator-=(int decreaseHealthPoint);
    /*
        * - operator of the HealthPoints:
        * @param decreaseHealthPoint - Decrease hp points from the object.
        * @result
        *      an object with decrease health points.
    */
    HealthPoints operator-(int decreaseHealthPoint);


private:
    int m_healthPoint;
    int m_maxHealthPoint;
};

/*
    * operator > of the HealthPoints:
    * @param healthPoint1, healthPoint2 - Check if hp1 is bigger than hp2 (hp1 and hp2 are objects).
    * @result
        *      True - if hp1 is bigger than hp2, otherwise False.
*/

bool operator>(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2);

/*
    * operator != of the HealthPoints:
    * @param healthPoint1, healthPoint2 - Check if there is a difference between two objects .
    * @result
        *      True - if there is a difference, otherwise False.
*/

bool operator!=(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2);
/*
    * operator <= of the HealthPoints:
    * @param healthPoint1, healthPoint2 - Check if hp1 is smaller than hp2 or equal to him (hp1 and hp2 are objects).
    * @result
        *      True - if hp1 is smaller or equal to hp2, otherwise False.
*/

bool operator<=(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2);

/*
    * operator >= of the HealthPoints:
    * @param healthPoint1, healthPoint2 - Check if hp1 is bigger than hp2 or equal to him (hp1 and hp2 are objects).
    * @result
        *      True - if hp1 is bigger or equal to hp2, otherwise False.
*/

bool operator>=(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2);

/*
    * operator + of the HealthPoints:
    * @param addHealthPoint, healthPoint - add hp points to object from the left side.
    * @result
        *      an object with added points
*/

HealthPoints operator+(int addHealthPoint, const HealthPoints& healthPoint);
/*
    * operator + of the HealthPoints:
    * @param addHealthPoint , healthPoint - add hp points to object from the right side.
    * @result
        *      an object with added points
*/

HealthPoints operator+(const HealthPoints& healthPoint, int addHealthPoint);


#endif //EX33_HEALTHPOINTS_H
