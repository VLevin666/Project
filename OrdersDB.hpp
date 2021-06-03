#pragma once
#include "Order.hpp"
#include <list>

class OrdersDB {
private:
    std::list<Order> orders;

public:
    /**
* @brief void add(const Order &order)
*
* Adding the order to the database
*
* @param const Order &order-variable for adding the order to the database
*/
    void add(const Order &order);
    /**
* @brief void remove(const Order &order)
*
* Removing the order to the database
*
* @param const Order &order-variable for removing the order to the database
*/
    void remove(const Order &order);
    /**
* @brief Order &operator[](unsigned int i)
*
* Getting the link to the i-th order in orders database
*
* @return a link to the i-th order
*/
    Order &operator[](unsigned int i);
    /**
* @brief unsigned int getSize() const
*
* Getting number of the order in orders database
*
* @return Size-variable for getting the order in orders database
*/
    unsigned int getSize() const;
};
