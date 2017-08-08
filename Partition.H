#pragma once

#include <boost/format.hpp>
#include <sstream>
#include <string>

class Partition
{
  public:
    Partition(std::string description, 
              std::string dueDate,
              double amount);

    const std::string asString() const;

    void reduceAmount(double deduction);

    inline const std::string& getDescription() const { return _description; }

    inline const std::string& getDueDate() const { return _dueDate; }
    
    inline const double getAmount() const { return _amount; }

  private:
    std::string      _description;
    std::string      _dueDate;
    double           _amount;
};
