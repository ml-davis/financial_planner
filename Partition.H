#pragma once

#include <sstream>
#include <string>

class Partition
{
  public:
    Partition(std::string description, 
              unsigned short dueDate,
              double amountReserved);

    void reduceAmountRemaining(double deduction);

    const inline std::string& getDescription() const { return _description; }

    const std::string dueDateString();

    const inline unsigned short getDueDate() const { return _dueDate; }
    
    const inline double getAmountReserved() const { return _amountReserved; }

    const inline double getAmountRemaining() const { return _amountRemaining; }

  private:
    std::string      _description;
    unsigned short   _dueDate;
    double           _amountReserved;
    double           _amountRemaining;
};
