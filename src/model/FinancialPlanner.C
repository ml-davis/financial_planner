#include "FinancialPlanner.H"

using namespace std;
using namespace boost;
using namespace boost::gregorian;

FinancialPlanner::FinancialPlanner()
{
}

FinancialPlanner::FinancialPlanner(double monthlyIncome)
  : _monthlyIncome(monthlyIncome)
{
  // load partitions and expenses from disk
  load(); 
  verifyPartitions();
}

void FinancialPlanner::addPartition(const string& name,
                                    const string& description,
                                    const double amount,
                                    const int dueDate)
{
  Partition partition(description, dueDate, amount);
  _partitions.insert(pair<string, Partition>(name, partition));
}

void FinancialPlanner::addExpense(const string& theDate,
                                  const string& category,
                                  const string& description,
                                  const double amount)
{
  // TODO: verify if valid date string or not
  Expense expense(from_simple_string(theDate), category, description, amount);
  _partitions.at(category).reduceAmountRemaining(amount);
  _expenses.push_back(expense);
}

void FinancialPlanner::save()
{
  IOHandler io;
  io.savePartitions(_partitions);
  io.saveExpenses(_expenses);
}

void FinancialPlanner::load()
{
  IOHandler io;
  io.loadPartitions(*this);
  io.loadExpenses(*this); // expenses must be loaded after partitions
}

void FinancialPlanner::verifyPartitions()
{
  double sum = 0;
  for (auto p: _partitions)
  {
    sum += p.second.getAmountReserved();
  }

  if (sum != _monthlyIncome)
  {
    cerr << "Partitioned income does not equal monthly income!\n"
      << sum << " != " << _monthlyIncome << endl;
    exit(1);
  }
}
