#pragma once

#include "Driver.hpp"
#include <list>

class DriversDB
{
private:
    std::list<Driver> drivers;

public:
    
    /**
* @brief void add(const Driver &driver)
*
* Adding the driver to the database
*
* @param const Driver &driver-variable for adding the driver to the database
*/
    void add(const Driver &driver);
    
    /**
* @brief void remove(const Driver &driver)
*
* Removing the order to the database
*
* @param const Driver &driver-variable for removing the driver to the database
*/
    void remove(const Driver &driver);
    
    /**
* @brief Driver &operator[](unsigned int i)
*
* Getting the link to the i-th driver in drivers database
*
* @return a link to the i-th driver
*/
    Driver &operator[](unsigned int i);
    /**
* @brief unsigned int getSize() const
*
* Getting number of the driver in drivers database
*
* @return Size-variable for getting the driver in drivers database
*/
   
    unsigned int getSize() const;
};
