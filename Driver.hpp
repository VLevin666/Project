#pragma once

const unsigned int daysPersWeek = 7;
const unsigned int hoursInDay = 24;

class Driver
{
private:
    double maxWeight;
    unsigned int hoursPerDay[daysPersWeek];

public:
/** 
	* @brief void setMaxWeight(double newMaxWeight)
	*
	* Setting max weight for the driver
	*
	* @param newMaxWeight Variable for setting the max weight
	*/    
    void setMaxWeight(double newMaxWeight);
    
/** 
	* @brief void setHoursPerDay(unsigned int newHoursPerDay[]
	*
	* Setting hours per day for the driver
	*
	* @param newHoursPerDay Variable for setting the hours per day
	*/        
    void setHoursPerDay(unsigned int newHoursPerDay[]);
    
/** 
	* @brief double getMaxWeight() const
	*
	* Getting max weight for the driver
	* 
	* @return MaxWeight-variable load capacity of the driver
	*/        
    double getMaxWeight() const;
    
/** 
	* @brief unsigned int getHoursForDay(unsigned int day) const
	*
	* Getting hours for day for the order
	* 
	* @return HoursForDay-variable is responsible for the work schedule of the driver
	*/       
    unsigned int getHoursForDay(unsigned int day) const;

    bool operator==(const Driver &rhs) const;
};
