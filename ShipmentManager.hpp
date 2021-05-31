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
    void addDriver(const Driver &newDriver);
    void addOrder(const Order &newOrder);

    void removeDriver(const Driver &toRemove);
    void removeOrder(const Order &toRemove);

    unsigned int getDriversCount() const;
    unsigned int getOrdersCount() const;

    Driver &getDriverByIndex(unsigned int index);
    Order &getOrderByIndex(unsigned int index);

    bool assign(Driver &driver, Order &order);

    unsigned int getAssignmentTableSize() const;
    Assignment &getAssignmentAtIndex(unsigned int index);

    void update(unsigned int passedDays);
};
