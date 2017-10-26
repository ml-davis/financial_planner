#pragma once

#include <financialPlanner/FinancialPlanner.h>

#include <boost/format.hpp>

class MessageFormatter
{
  public:
    std::string formatExpenseTypes(const FinancialPlanner& financialPlanner);
    std::string formatExpenses(const FinancialPlanner& financialPlanner);
    std::string formatRemaining(const FinancialPlanner& financialPlanner);
};
