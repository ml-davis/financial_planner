#pragma once

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/lexical_cast.hpp>

#include <iostream>
#include <stdexcept>
#include <string>

class Validator
{
  public:
    const static int validateDueDate(const std::string& dueDateString);

    const static double validateDollarAmount(const std::string& dollarAmountString);

    const static boost::gregorian::date validateDate(const std::string& dateString);

    const static std::string validateCategory(const std::string& categoryString,
                                         const bool isCategory);
};

