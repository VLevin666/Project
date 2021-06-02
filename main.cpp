#include <iostream>
#include "ShipmentManager.hpp"

void printMenu();
void handleInput(const char input, ShipmentManager &manager);

void printDriver(const Driver &driver);
void printOrder(const Order &order);
void printDrivers(ShipmentManager &manager);
void printOrders(ShipmentManager &manager);

int main(int /*argc*/, char ** /*argv*/)
{ // unused for now

    ShipmentManager manager;

    char input = 0;

    while (input != 'q')
    {
        printMenu();
        std::cin >> input;
        handleInput(input, manager);
    }

    return 0;
}

void printMenu()
{
    std::cout << "============= Menu! ============\n"
                 "1 - Add new driver\n"
                 "2 - Add new order\n"
                 "3 - Remove existing driver\n"
                 "4 - Remove existing order\n"
                 "5 - Print all drivers\n"
                 "6 - Print all orders\n"
                 "7 - Assign driver to order\n"
                 "8 - Print assigment table\n"
                 "9 - Update database by number of passed days\n"
                 "q - Exit(Quit)\n"
                 "Your input is:  ";
}
void handleInput(const char input, ShipmentManager &manager)
{
    switch (input)
    {
    case '1':
    {
        Driver newDriver;
        double weight;
        unsigned int hoursPerDay[daysPersWeek];
        std::cout << "Provide the maximum possible weight for driver`s vehicle and work hours for the whole week(" << daysPersWeek << " days) separated by spase\n";
        std::cin >> weight;
        for (unsigned int i = 0; i < daysPersWeek; ++i)
        {
            std::cin >> hoursPerDay[i];
        }
        newDriver.setMaxWeight(weight);
        newDriver.setHoursPerDay(hoursPerDay);
        manager.addDriver(newDriver);
    }
    break;
    case '2':
    {
        Order newOrder;
        std::cout << "Provide the weight of new Order, its hours for delivery and days before deadline separated by space :\n";
        double weight;
        unsigned int daysLeft, hoursForDelivery;
        std::cin >> weight >> hoursForDelivery >> daysLeft;
        newOrder.setWeight(weight);
        newOrder.setDaysLeft(daysLeft);
        newOrder.setHoursForDelivery(hoursForDelivery);
        newOrder.setStatus(Order::Status::ToDo);
        manager.addOrder(newOrder);
    }
    break;
    case '3':
    {
        std::cout << "Choose driver to remove:\n";
        printDrivers(manager);
        unsigned int indexToRemove;
        do
        {
            std::cout << "Choose between 1 and " << manager.getDriversCount() << std::endl;
            std::cin >> indexToRemove;
        } while (indexToRemove >= manager.getDriversCount());
        manager.removeDriver(manager.getDriverByIndex(indexToRemove - 1));
    }
    break;
    case '4':
    {
        std::cout << "Choose order to remove:\n";
        printOrders(manager);
        unsigned int indexToRemove;
        do
        {
            std::cout << "Choose between 1 and " << manager.getOrdersCount() << std::endl;
            std::cin >> indexToRemove;
        } while (indexToRemove >= manager.getOrdersCount());
        manager.removeOrder(manager.getOrderByIndex(indexToRemove - 1));
    }
    break;
    case '5':
    {
        printDrivers(manager);
    }
    break;
    case '6':
    {
        printOrders(manager);
    }
    break;
    case '7':
    {
        unsigned int driverIndex, orderIndex;
        do
        {
            std::cout << "Provide driver and order indexes for assigment separated by space:\n";
            std::cin >> driverIndex >> orderIndex;
        } while (driverIndex - 1 >= manager.getDriversCount() || orderIndex - 1 >= manager.getOrdersCount());

        if (!manager.assign(manager.getDriverByIndex(driverIndex - 1), manager.getOrderByIndex(orderIndex - 1)))
        {
            std::cout << "This driver has no chances to deliver this order!\n";
        }
    }
    break;
    case '8':
    {
        for (unsigned int index = 0; index < manager.getAssignmentTableSize(); ++index)
        {
            ShipmentManager::Assignment &assignment = manager.getAssignmentAtIndex(index);
            std::cout << "Assignment " << index + 1 << ":\n";
            printDriver(*(assignment.driver));
            std::cout << std::endl;
            std::cout << "Works on ";
            printOrder(*(assignment.order));
            std::cout << std::endl;
        }
    }
    break;
    case '9':
    {
        unsigned int passedDays;
        std::cout << "Provide number of passed days:\n";
        std::cin >> passedDays;
        manager.update(passedDays);
    }
    break;
    case 'q':
    {
        std::cout << "Exit!\n";
    }
    break;
    case 'd':
{ // for debug purposes!
{
Driver newDriver;
static double weight{10.f};
static unsigned int hoursPerDay[daysPersWeek];
weight += 1.5f;
for (unsigned int i = 0; i < daysPersWeek; ++i)
{
hoursPerDay[i] = (hoursPerDay[i] + i) % hoursInDay;
}
newDriver.setMaxWeight(weight);
newDriver.setHoursPerDay(hoursPerDay);
manager.addDriver(newDriver);
}
{
Order newOrder;
static double weight{1.f};
static unsigned int daysLeft{0}, hoursForDelivery{0};
weight += 1.f;
hoursForDelivery = (hoursForDelivery + 1) % hoursInDay;
daysLeft += 1;
newOrder.setWeight(weight);
newOrder.setDaysLeft(daysLeft);
newOrder.setHoursForDelivery(hoursForDelivery);
newOrder.setStatus(Order::Status::ToDo);
manager.addOrder(newOrder);
}
}
break;
default:
    {
        std::cout << "Enter the command between 1-9 or q for Exit!\n";
    }
    break;
    }
}

void printDriver(const Driver &driver)
{
    std::cout << "Driver with maximum weight: " << driver.getMaxWeight()
              << "\t with these working hours per day:";
    for (unsigned int day = 0; day < daysPersWeek; ++day)
    {
        std::cout << "\t" << driver.getHoursForDay(day);
    }
}
void printDrivers(ShipmentManager &manager)
{
    for (unsigned int i = 0; i < manager.getDriversCount(); ++i)
    {
        std::cout << i + 1 << ": ";
        printDriver(manager.getDriverByIndex(i));
        std::cout << std::endl;
    }
}

void printOrder(const Order &order)
{
    std::cout << "Order with weight: " << order.getWeight()
              << "\t with days left:\t" << order.getDaysLeft()
              << " and left hours for delivery:\t" << order.getHourseForDelivery()
              << ". Status is:\t";
    switch (order.getStatus())
    {
    case (Order::Status::ToDo):
        std::cout << "To Do";
        break;
    case (Order::Status::InProgress):
        std::cout << "In Progress";
        break;
    case (Order::Status::Failed):
        std::cout << "Failed";
        break;
    case (Order::Status::Completed):
        std::cout << "Completed";
        break;
    default:
        throw "not covered order status in output!";
        break;
    }
}
void printOrders(ShipmentManager &manager)
{
    for (unsigned int i = 0; i < manager.getOrdersCount(); ++i)
    {
        std::cout << i + 1 << ": ";
        printOrder(manager.getOrderByIndex(i));
        std::cout << std::endl;
    }
}
