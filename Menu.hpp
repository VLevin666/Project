#include <iostream>
#include "ShipmentManager.hpp"

class Menu
{
private:
    ShipmentManager &manager;

public:
    Menu(ShipmentManager &manager);

    void work();

    static void printMenu();
    static void handleInput(const char input, ShipmentManager &manager);
    static void printDriver(const Driver &driver);
    static void printDrivers(ShipmentManager &manager);
    static void printOrder(const Order &order);
    static void printOrders(ShipmentManager &manager);
};
