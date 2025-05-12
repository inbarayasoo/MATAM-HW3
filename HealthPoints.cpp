//
// Created by inbar on 13/12/2022.
//
#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHealthPoint) : m_healthPoint(maxHealthPoint), m_maxHealthPoint(maxHealthPoint)
{
    if (maxHealthPoint <= 0)
    {
        throw InvalidArgument();
    }
}

bool operator==(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2)
{
    return healthPoint1.m_healthPoint == healthPoint2.m_healthPoint;
}

bool operator<(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2)
{
    return healthPoint1.m_healthPoint < healthPoint2.m_healthPoint;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoint)
{
    return os << healthPoint.m_healthPoint << "(" << healthPoint.m_maxHealthPoint << ")" ;
}

HealthPoints& HealthPoints::operator+=(int addHealthPoint)
{
    if(m_healthPoint + addHealthPoint <= 0)
    {
        m_healthPoint = 0;
    }
    else if(m_healthPoint + addHealthPoint >= m_maxHealthPoint)
    {
        m_healthPoint = m_maxHealthPoint;
    }
    else
    {
        m_healthPoint = m_healthPoint + addHealthPoint;
    }
    return *this;
}

HealthPoints& HealthPoints::operator-=(int decreaseHealthPoint)
{
    return *this += (-decreaseHealthPoint);
}

HealthPoints HealthPoints::operator-(int decreaseHealthPoint)
{
    return HealthPoints(*this) -= decreaseHealthPoint;
}

bool operator>(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2)
{
    return healthPoint2 < healthPoint1;
}

bool operator!=(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2)
{
    return !(healthPoint1 == healthPoint2);
}

bool operator<=(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2)
{
    return !(healthPoint2 < healthPoint1);
}

bool operator>=(const HealthPoints& healthPoint1, const HealthPoints& healthPoint2)
{
    return healthPoint2 <= healthPoint1;
}

HealthPoints operator+(int addHealthPoint, const HealthPoints& healthPoint)
{
    return (healthPoint + addHealthPoint);
}

HealthPoints operator+(const HealthPoints& healthPoint, int addHealthPoint)
{
    return HealthPoints(healthPoint) += addHealthPoint;
}


