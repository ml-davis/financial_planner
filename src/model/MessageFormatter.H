#pragma once

#include <boost/format.hpp>

class MessageFormatter
{
  public:
    std::string formatExpenses(const FinancialPlanner& financialPlanner);
    std::string formatRemaining(const FinancialPlanner& financialPlanner);
};
