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

    const std::string& getDescription() const;

    const double getAmount() const;

    const std::string& getDueDate() const;

  private:
    std::string      _description;
    std::string      _dueDate;
    double           _amount;
};
