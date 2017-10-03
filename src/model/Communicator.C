#include "Communicator.H"

using namespace std;

Communicator::Communicator()
  : _financialPlanner{ FinancialPlanner() },
    _formatter{ MessageFormatter() }
{}

string Communicator::fetchData(const string& request)
{
  if (request == "FETCH EXPENSES")
  {
    return _formatter.formatExpenses(_financialPlanner);
  }
  else if (request == "FETCH REMAINING")
  {
    return _formatter.formatRemaining(_financialPlanner);
  }
  else
  {
    cout << "Received invalid message from Client" << endl;
    exit(1);
  }
}

void Communicator::changeDate(const string& date)
{
  _financialPlanner.load(date);
}
