#pragma once

#include <boost/date_time/gregorian/gregorian_types.hpp>
#include <string>

class Expense
{
  public:
    Expense(boost::gregorian::date date,
            std::string category,
            std::string comment,
            double amount);

    const boost::gregorian::date& getDate() const;

    const std::string& getCategory() const;

    const std::string& getComment() const;

    const double getAmount() const;

  private:
    boost::gregorian::date _date;
    std::string _category;
    std::string _comment;
    double _amount;
};
