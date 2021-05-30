#pragma once
#include "Order.hpp"
#include <list>

class OrdersDB {
private:
    std::list<Order> orders;

public:
    void add(const Order &order);
    void remove(const Order &order);
    Order &operator[](unsigned int i);
    unsigned int getSize() const;
};
