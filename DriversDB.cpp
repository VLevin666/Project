#include "DriversDB.hpp"

void DriversDB::add(const Driver &driver)
{
    drivers.push_back(driver);
}
void DriversDB::remove(const Driver &driver)
{
    drivers.remove(driver);
}
Driver &DriversDB::operator[](unsigned int i)
{
    if (i >= drivers.size())
        throw "not valid index for drivers!";

    std::list<Driver>::iterator iter = drivers.begin();
    for (; iter != drivers.end(); iter++)
    {
        if (i == 0)
            break;
        --i;
    }

    return *iter;
}

unsigned int DriversDB::getSize() const
{
    return drivers.size();
}
