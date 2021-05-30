#include "Driver.hpp"

void Driver::setMaxWeight(double newMaxWeight)
{
    maxWeight = newMaxWeight;
}
void Driver::setHoursPerDay(unsigned int newHoursPerDay[])
{
    for (unsigned int i = 0; i < daysPersWeek; ++i)
    {
        if (newHoursPerDay[i] >= hoursInDay)
            throw "trudogolik detected!";
        hoursPerDay[i] = newHoursPerDay[i];
    }
}
double Driver::getMaxWeight() const
{
    return maxWeight;
}
unsigned int Driver::getHoursForDay(unsigned int day) const
{
    if (day >= daysPersWeek)
        throw "Wrong day!";
    return hoursPerDay[day];
}

bool Driver::operator==(const Driver &rhs) const
{
    return this == &rhs;
}
