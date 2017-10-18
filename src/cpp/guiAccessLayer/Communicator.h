#pragma once

#include <financialPlanner/FinancialPlanner.h>
#include <guiAccessLayer/MessageFormatter.h>

class Communicator
{
  public:
    Communicator();

    std::string fetchData(const std::string& request);

    void changeDate(const std::string& date);

  private:
    FinancialPlanner _financialPlanner;
    MessageFormatter _formatter;

};
