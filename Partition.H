#pragma once

#include <boost/format.hpp>
#include <sstream>
#include <string>

class Partition
{
  public:
    Partition(std::string description, 
              unsigned short dueDate,
              double amount);

    const std::string asString() const;

    void reduceAmount(double deduction);

    const inline std::string& getDescription() const { return _description; }

    const inline unsigned short getDueDate() const { return _dueDate; }
    
    const inline double getAmount() const { return _amount; }

  private:
    std::string      _description;
    unsigned short   _dueDate;
    double           _amount;
};
