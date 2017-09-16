#include "../model/FinancialPlanner.H"

#include <boost/format.hpp>

#include <iostream>
#include <unordered_map>
#include <vector>

class View
{
  public:
    View();

    void printExpenses();

    void printRemaining();

    void changeDate(const std::string& date);

  private:
    FinancialPlanner _financialPlanner;

};
