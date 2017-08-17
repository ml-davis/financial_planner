#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>

#include <string>

class Expense
{
  public:
    Expense(boost::gregorian::date date,
            std::string category,
            std::string description,
            double cost);

    const inline std::string getDateString() { return to_simple_string(_date); }

    const inline boost::gregorian::date& getDate() const { return _date; }

    const inline std::string& getCategory() const { return _category; }

    const inline std::string& getDescription() const { return _description; }

    const inline double getCost() const { return _cost; }

  private:
    boost::gregorian::date _date;
    std::string _category;
    std::string _description;
    double _cost;
};
