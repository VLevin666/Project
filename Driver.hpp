#pragma once

const unsigned int daysPersWeek = 7;
const unsigned int hoursInDay = 24;

class Driver
{
private:
    double maxWeight;
    unsigned int hoursPerDay[daysPersWeek];

public:
    void setMaxWeight(double newMaxWeight);
    void setHoursPerDay(unsigned int newHoursPerDay[]);
    double getMaxWeight() const;
    unsigned int getHoursForDay(unsigned int day) const;

    bool operator==(const Driver &rhs) const;
};
