#include "Menu.hpp"

int main(int /*argc*/, char ** /*argv*/)
{
    ShipmentManager manager;
    Menu menu(manager);
    menu.work();

    return 0;
}
