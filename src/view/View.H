#include "../model/FinancialPlanner.H"

#include <boost/format.hpp>

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
