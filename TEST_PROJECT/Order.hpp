#pragma once

class Order {
public:
    enum class Status {
        ToDo,
        InProgress,
        Completed,
        Failed
    };
    
private:
    double weight;
    unsigned int daysLeft;
    unsigned int hoursForDelivery;
    Status status;
    
public:
    void setWeight(double newWeight);
    void setDaysLeft(unsigned int newDaysLeft);
    void setHoursForDelivery(unsigned int newHoursForDelivery);
    void setStatus(Status newStatus);

    double getWeight() const;
    unsigned int getDaysLeft() const;
    unsigned int getHourseForDelivery() const;
    Status getStatus() const;

    bool operator==(const Order &rhs) const;
    bool operator!=(const Order &rhs) const;
};
