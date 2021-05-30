#include "OrdersDB.hpp"

void OrdersDB::add(const Order &order) {
    orders.push_back(order);
}
void OrdersDB::remove(const Order &order) {
    orders.remove(order);
}
Order &OrdersDB::operator[](unsigned int i) {
    if (i >= orders.size())
        throw "Error: not valid index for orders!";

    std::list<Order>::iterator iter = orders.begin();
    for (; iter != orders.end(); iter++) {
        if (i == 0)
            break;
        --i;
    }
    return *iter;
}
unsigned int OrdersDB::getSize() const {
    return orders.size();
}
