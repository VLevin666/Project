#include "ShipmentManager.hpp"

void ShipmentManager::addDriver(const Driver &newDriver)
{
    driversDb.add(newDriver);
}
void ShipmentManager::addOrder(const Order &newOrder)
{
    ordersDb.add(newOrder);
}

void ShipmentManager::removeDriver(const Driver &toRemove)
{
    std::list<Assignment>::iterator iter = assignments.begin();
     for (;iter != assignments.end(); iter++)
     {
         if (iter->driver == &toRemove) 
         {
             Order* toUpdate = iter->order;
             if(toUpdate->getStatus() == Order::Status::InProgress 
                {
                 toUpdate->setStatus(Order::Status::ToDo);
             }
                iter=assignments.erase(iter);
                break;
                }
          }
    driversDb.remove(toRemove);
}
void ShipmentManager::removeOrder(const Order &toRemove)

    driversDb.remove(toRemove);
}
void ShipmentManager::removeOrder(const Order &toRemove)
{
    ordersDb.remove(toRemove);
}

unsigned int ShipmentManager::getDriversCount() const
{
    return driversDb.getSize();
}

unsigned int ShipmentManager::getOrdersCount() const
{
    return ordersDb.getSize();
}

Driver &ShipmentManager::getDriverByIndex(unsigned int index)
{
    return driversDb[index];
}

Order &ShipmentManager::getOrderByIndex(unsigned int index)
{
    return ordersDb[index];
}

int ShipmentManager::calculateLeftHours(Driver &driver, Order &order, unsigned int passedDays)
{
    //  leftHoursForDelivery is int here bc it could go under 0
    int leftHoursForDelivery = order.getHourseForDelivery();
    unsigned int futureDay = currentDay;
    while (passedDays-- > 0)
    {
        leftHoursForDelivery -= driver.getHoursForDay((futureDay++) % daysPersWeek);
    }
    return leftHoursForDelivery;
}

bool ShipmentManager::assign(Driver &driver, Order &order)
{
    unsigned int daysLeft = order.getDaysLeft();
    if (order.getWeight() > driver.getMaxWeight())
    {
        // too heavy order for this driver
        return false;
    }
    if (calculateLeftHours(driver, order, daysLeft) > 0)
    {
        // this driver does not have a chance to deliver this order
        return false;
    }
    order.setStatus(Order::Status::InProgress);
    assignments.push_back(Assignment{&order, &driver});
    return true;
}
unsigned int ShipmentManager::getAssignmentTableSize() const
{
    return assignments.size();
}

ShipmentManager::Assignment &ShipmentManager::getAssignmentAtIndex(unsigned int index)
{
    if (index >= assignments.size())
        throw "wrong index for assignment table!";

    std::list<Assignment>::iterator iter = assignments.begin();
    for (; iter != assignments.end(); iter++)
    {
        if (index == 0)
            break;
        --index;
    }
    return *iter;
}

void ShipmentManager::update(unsigned int passedDays)
{
    for (unsigned int index = 0; index < getOrdersCount(); ++index)
    {
        Order &order = getOrderByIndex(index);
        if (!checkAssignmentAndUpdate(order, passedDays))
        {
            // there is no assignment, just substruct left days and update status if needed
            if (passedDays >= order.getDaysLeft())
            {
                order.setStatus(Order::Status::Failed);
                order.setDaysLeft(0);
            }
            else
            {
                order.setDaysLeft(order.getDaysLeft() - passedDays);
            }
        }
    }

    currentDay += passedDays;
}

bool ShipmentManager::checkAssignmentAndUpdate(Order &orderToCheck, unsigned int passedDays)
{
    std::list<Assignment>::iterator iter = assignments.begin();
    for (; iter != assignments.end(); iter++)
    {

        if (*(iter->order) != orderToCheck)
            continue;

        unsigned int leftDays = iter->order->getDaysLeft();
        int leftHours = calculateLeftHours(*(iter->driver), *(iter->order),
                                           std::min(leftDays, passedDays));
        if (leftHours <= 0)
        {
            iter->order->setStatus(Order::Status::Completed);
            iter->order->setDaysLeft(0);
            iter->order->setHoursForDelivery(0);
        }
        else if (leftHours > 0 && passedDays < leftDays)
        {
            // still in progress
            iter->order->setDaysLeft(leftDays - passedDays);
            iter->order->setHoursForDelivery(leftHours);
        }
        else if (leftHours > 0 && passedDays >= leftDays)
        {
            iter->order->setStatus(Order::Status::Failed);
        }
        return true;
    }
    return false;
}
