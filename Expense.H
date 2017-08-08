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

    inline const boost::gregorian::date& getDate() const { return _date; }

    inline const std::string& getCategory() const { return _category; }

    inline const std::string& getComment() const { return _comment; }

    inline const double getAmount() const { return _amount; }

  private:
    boost::gregorian::date _date;
    std::string _category;
    std::string _comment;
    double _amount;
};
