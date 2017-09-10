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

void FinancialPlanner::addExpense(const date& theDate,
                                  const string& category,
                                  const string& description,
                                  const double amount)
{
  Expense expense(theDate, category, description, amount);
  _partitions.at(category).reduceAmountRemaining(amount);
  _expenses.push_back(expense);
}

void FinancialPlanner::load()
{
  SqlFetcher fetcher;
  fetcher.load(*this);
}

const bool FinancialPlanner::hasPartition(string name)
{
  return _partitions.find(name) != _partitions.end();
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
