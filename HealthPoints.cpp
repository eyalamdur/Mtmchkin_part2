#include "HealthPoints.h"


/* C'tor of HealthPoints class - 1 param.
 * @param maxHealthPoints - how many max health points.
 * @return a new instance of HealthPoints. */
HealthPoints::HealthPoints(int maxValue){
    // If the input is below zero.
    if(maxValue <= 0){                           
        throw HealthPoints::InvalidArgument();
    }
    m_maxHealthPoints = maxValue;
    m_healthPoints = maxValue;
}

/*Addition operator*/
HealthPoints& HealthPoints::operator+(int healthPointsAddition){
    return HealthPoints(*this) += healthPointsAddition;
}

/*Addition operator*/
HealthPoints& operator+(int healthPointsAddition, HealthPoints& currentHealthPoints){
    return HealthPoints(currentHealthPoints) += healthPointsAddition;
}

/*Addition and assigning operator*/
HealthPoints& HealthPoints::operator+=(int healthPointsAddition){
    if(m_healthPoints + healthPointsAddition >= m_maxHealthPoints){
        m_healthPoints = m_maxHealthPoints;
    }

    else if(m_healthPoints + healthPointsAddition <= MIN_HEALTH_POINTS ){
        m_healthPoints = MIN_HEALTH_POINTS;
    }

    else{
        m_healthPoints = m_healthPoints+healthPointsAddition;
    }

    return *this;
}

/*Subtraction and assigning operator*/
HealthPoints& HealthPoints::operator-=(int healthPointsSubtraction){
    if(m_healthPoints - healthPointsSubtraction>= m_maxHealthPoints){
        m_healthPoints = m_maxHealthPoints;
    }

    else if(m_healthPoints - healthPointsSubtraction<=MIN_HEALTH_POINTS){
        m_healthPoints = MIN_HEALTH_POINTS;
    }

    else{
        m_healthPoints =m_healthPoints-healthPointsSubtraction;
    }

    return *this;
}

/*Subtraction operator*/
HealthPoints& HealthPoints::operator-(int healthPointsSubtraction){
    return HealthPoints(*this) -= healthPointsSubtraction;
}

/*comparison operators- checks whether the two HPs are equal or not.*/
bool HealthPoints::operator==(const HealthPoints& otherHealthPoints) const{
    return (this->m_healthPoints == otherHealthPoints.m_healthPoints);
}

bool operator==(const HealthPoints& currentHealthPoints, const int otherHealthPoints){
    return (currentHealthPoints.m_healthPoints == otherHealthPoints);
}

bool operator==(const int currentHealthPoints,const HealthPoints& otherHealthPoints){
    return (otherHealthPoints.m_healthPoints == currentHealthPoints);
}   

bool HealthPoints::operator!=(const HealthPoints& otherHealthPoints) const{
    return !(*this == otherHealthPoints);
}

/*bigger or equale operator - checks whether one HP is equale or bigger than the other.*/
bool HealthPoints::operator>=(const HealthPoints& otherHealthPoints) const{
    return (this->m_healthPoints >= otherHealthPoints.m_healthPoints);
}

/*smaller or equale operator - checks whether one HP is equale or smaller than the other.*/
bool HealthPoints::operator<=(const HealthPoints& otherHealthPoints) const{
    return (this->m_healthPoints <= otherHealthPoints.m_healthPoints);
}

/*bigger operator - checks whether one HP is equale or smaller than the other.*/
bool HealthPoints::operator>(const HealthPoints& otherHealthPoints) const{
    return (this->m_healthPoints > otherHealthPoints.m_healthPoints);
}

/*smaller operator - checks whether one HP is smaller than the other.*/
bool HealthPoints::operator<(const HealthPoints& otherHealthPoints) const{
    return (this->m_healthPoints < otherHealthPoints.m_healthPoints);
}

/*print operator.*/
std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints){
    os << healthPoints.m_healthPoints << "(" << healthPoints.m_maxHealthPoints << ")";
    return os;
}

std::ostream& HealthPoints::operator<<(std::ostream& os) const{
    os << this->m_healthPoints << "(" << this->m_maxHealthPoints << ")";
    return os;
}