#include "Order.hpp"

void Order::setWeight(double newWeight) {
    weight = newWeight;
}
void Order::setDaysLeft(unsigned int newDaysLeft) {
    daysLeft = newDaysLeft;
}
void Order::setHoursForDelivery(unsigned int newHoursForDelivery) {
    hoursForDelivery = newHoursForDelivery;
}
void Order::setStatus(Status newStatus) {
    status = newStatus;
}

double Order::getWeight() const {
    return weight;
}
unsigned int Order::getDaysLeft() const {
    return daysLeft;
}
unsigned int Order::getHourseForDelivery() const {
    return hoursForDelivery;
}
Order::Status Order::getStatus() const {
    return status;
}

bool Order::operator==(const Order &rhs) const {
    return this == &rhs;
}
bool Order::operator!=(const Order &rhs) const {
    return !(*this == rhs);
}
