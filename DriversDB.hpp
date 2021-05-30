#pragma once

#include "Driver.hpp"
#include <list>

class DriversDB
{
private:
    std::list<Driver> drivers;

public:
    void add(const Driver &driver);
    void remove(const Driver &driver);
    Driver &operator[](unsigned int i);
    unsigned int getSize() const;
};
