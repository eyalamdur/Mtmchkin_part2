#ifndef EX3_HEALTH_POINTS
#define EX3_HEALTH_POINTS

const int DEFAULT_HEALTH_POINTS = 100;
const int MIN_HEALTH_POINTS = 0;

#include <iostream>

class HealthPoints {
    public:
        class InvalidArgument{};
        /* C'tor of HealthPoints class - 1 param.
         * @param maxHealthPoints - how many max health points.
         * @return a new instance of HealthPoints. */
        HealthPoints(int maxValue = DEFAULT_HEALTH_POINTS);

        /* D'tor of HealthPoints class. */
        ~HealthPoints()=default;

        /* Copy of HealthPoints class.
         * @param HealthPoints& - reference to another HealthPoints object.
         * @return a new instance of HealthPoints with copied values as the given HealthPoint. */
        HealthPoints(const HealthPoints&) = default;

        /* Assigning operator of HealthPoints class.
         * @param HealthPoints& - reference to another HealthPoints object.
         * @return reference to the current HealthPoints with copied values as the other HealthPoint. */
        HealthPoints& operator=(const HealthPoints& other) = default;

        /* Addition operator of HealthPoints class.
         * @param healthPointsAddition - int that represent hp to add.
         * @return reference to the new HealthPoints with added hp values. */
        HealthPoints& operator+(int healthPointsAddition);
        friend HealthPoints& operator+(int healthPointsAddition, HealthPoints& currentHealthPoints);
        
        /* Addition and assignment operator of HealthPoints class.
         * @param healthPointsAddition - int that represent hp to add.
         * @return reference to the current HealthPoints with added hp values. */
        HealthPoints& operator+=(int healthPointsAddition);

        /* Subtraction operator of HealthPoints class.
         * @param healthPointsAddition - int that represent hp to remove.
         * @return reference to the new HealthPoints with removed hp values. */
        HealthPoints& operator-(int healthPointsSubtraction);

        /* Subtraction and assignment operator of HealthPoints class.
         * @param healthPointsSubtraction - int that represent hp to remove.
         * @return reference to the current HealthPoints with removed hp values. */
        HealthPoints& operator-=(int healthPointsSubtraction);

        /* Comparison operator of HealthPoints class.
         * @param otherHealthPoints - reference to another HealthPoints object.
         * @return true whether the two HPs are equal and false if not. */
        bool operator==(const HealthPoints& otherHealthPoints) const;
        friend bool operator==(const HealthPoints& currentHealthPoints, const int otherHealthPoints);
        friend bool operator==(const int currentHealthPoints,const HealthPoints& otherHealthPoints);

        /* Non-comparison operator of HealthPoints class.
         * @param otherHealthPoints - reference to another HealthPoints object.
         * @return false whether the two HPs are equal and true if not. */
        bool operator!=(const HealthPoints& otherHealthPoints) const;

        /*bigger or equale operator - checks whether one HP is equale or bigger than the other.*/
        bool operator>=(const HealthPoints& otherHealthPoints) const;

        /*smaller or equale operator - checks whether one HP is equale or smaller than the other.*/
        bool operator<=(const HealthPoints& otherHealthPoints) const;

        /*bigger operator - checks whether one HP is equale or smaller than the other.*/
        bool operator>(const HealthPoints& otherHealthPoints) const;

        /*smaller operator - checks whether one HP is smaller than the other.*/
        bool operator<(const HealthPoints& otherHealthPoints) const;

        /* << Operator of HealthPoints class.
         * @return std::ostream object. */
        std::ostream& operator<<(std::ostream& os) const;
        friend std::ostream& operator<<(std::ostream& os, const HealthPoints& healthPoints);

    private:
        int m_maxHealthPoints;
        int m_healthPoints;
};

#endif //EX3_HEALTH_POINTS