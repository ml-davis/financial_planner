#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>
#include <string>

class Expense
{
  public:
    Expense(boost::gregorian::date date,
            std::string category,
            std::string comment,
            double amount);

    const std::string getDateString();

    const inline boost::gregorian::date& getDate() const { return _date; }

    const inline std::string& getCategory() const { return _category; }

    const inline std::string& getComment() const { return _comment; }

    const inline double getAmount() const { return _amount; }

  private:
    boost::gregorian::date _date;
    std::string _category;
    std::string _comment;
    double _amount;
};
