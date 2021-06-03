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
/** 
	* @brief void setWeight(double newWeight)
	*
	* Setting the weight for the order
	* 
	* @param newWeight Variable for setting the weight
	*/    
    void setWeight(double newWeight);
    
 /** 
	* @brief void setDaysLeft(unsigned int newDaysLeft);
	*
	* Setting the left days for the order
	* 
	* @param newDaysLeft Variable for setting the days left
	*/  
    void setDaysLeft(unsigned int newDaysLeft);
    
 /** 
	* @brief void setHoursForDelivery(unsigned int newHoursForDelivery);
	*
	* Setting the hours for delivery for the order
	* 
	* @param newHoursForDelivery Variable for setting the hours for delivery 
	*/    
    void setHoursForDelivery(unsigned int newHoursForDelivery);
 
 /** 
	* @brief void setStatus(Status newStatus)
	*
	* Setting status of the order
	*
	* @param newStatus Variable for setting the status
	*/   
    void setStatus(Status newStatus);

 /** 
	* @brief double getWeight() const
	*
	* Getting the weight for the order
	* 
	* @return Weight-variable weight of the order
	*/   
    double getWeight() const;
 
 /** 
	* @brief  unsigned int getDaysLeft() const
	*
	* Getting the left days for the order
	* 
	* @return DaysLeft-variable left day of the order
	*/     
    unsigned int getDaysLeft() const;

/** 
	* @brief  unsigned int getHourseForDelivery() const
	*
	* Getting the hours for delivery for the order
	* 
	* @return HoursForDelivery-variable hours for delivery of the order
	*/      
    unsigned int getHourseForDelivery() const;

/** 
	* @brief Status getStatus() const
	*
	* Getting status of the order
	*
	* @return Status-variable status of the order
	*/     
    Status getStatus() const;

    bool operator==(const Order &rhs) const;
    bool operator!=(const Order &rhs) const;
};
