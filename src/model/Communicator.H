#pragma once

#include "FinancialPlanner.H"
#include "MessageFormatter.H"

class Communicator
{
  public:
    Communicator();

    std::string getExpenses();

    std::string getRemaining();

    void changeDate(const std::string& date);

  private:
    FinancialPlanner _financialPlanner;
    MessageFormatter _formatter;

};
