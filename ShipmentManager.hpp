#pragma once

#include "DriversDB.hpp"
#include "OrdersDB.hpp"

#include <list>

class ShipmentManager
{
public:
    struct Assignment
    {
        Order *order;
        Driver *driver;
    };

private:
    OrdersDB ordersDb;
    DriversDB driversDb;
    std::list<Assignment> assignments;

    unsigned int currentDay{0};

    int calculateLeftHours(Driver &driver, Order &order, unsigned int passedDays);
    bool checkAssignmentAndUpdate(Order &orderToCheck, unsigned int passedDays);

public:
    
    /**
* @brief void addDriver(const Driver &newDriver);
*
* Adding the driver to the database
*
* @param const Driver &newDriver-variable for adding the driver to the database
*/
    void addDriver(const Driver &newDriver);
    
    /**
* @brief void add(const Order &order)
*
* Adding the order to the database
*
* @param const Order &order-variable for adding the order to the database
*/
    void addOrder(const Order &newOrder);
    
    /**
* @brief void removeDriver(const Driver &toRemove)
*
* Removing the order to the database
*
* @param const Driver &toRemove-variable for removing the driver to the database
*/
    
    void removeDriver(const Driver &toRemove);
    
    /**
* @brief void removeOrder(const Order &toRemove)
*
* Removing the order to the database
*
* @param const Order &toRemove-variable for removing the order to the database
*/
    void removeOrder(const Order &toRemove);
    
    /**
* @brief unsigned int getDriversCount() const
*
* Getting count of the driver in drivers database
*
* @return DriversCount-variable for getting count of driver
*/
    unsigned int getDriversCount() const;
    
    /**
* @brief unsigned int getOrdersCount() const
*
* Getting count of the order in orders database
*
* @return OrdersCount-variable for getting count of order
*/
    unsigned int getOrdersCount() const;
    
    Driver &getDriverByIndex(unsigned int index);
    Order &getOrderByIndex(unsigned int index);
    bool assign(Driver &driver, Order &order);
    
    /**
* @brief unsigned int getAssignmentTableSize() const
*
* Getting assignment table size
*
* @return AssignmentTableSize-variable for getting assignment table size
*/

    unsigned int getAssignmentTableSize() const;
    
    /**
* @brief Assignment &getAssignmentAtIndex(unsigned int index)
*
* Getting the link to the index-th
*
* @return a link to the index-th
*/
    Assignment &getAssignmentAtIndex(unsigned int index);
    
    /**
* @brief void update(unsigned int passedDays)
*
* Setting for the number of days passed
*
* @param passedDays-variable is responsible for the number of days passed
*/
    void update(unsigned int passedDays);
};
