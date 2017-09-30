#include "Communicator.H"

using namespace std;

Communicator::Communicator()
  : _financialPlanner{ FinancialPlanner() },
    _formatter{ MessageFormatter() }
{}

string Communicator::getExpenses()
{
  return _formatter.formatExpenses(_financialPlanner);
}

string Communicator::getRemaining()
{
  return _formatter.formatRemaining(_financialPlanner);
}

void Communicator::changeDate(const string& date)
{
  _financialPlanner.load(date);
}
