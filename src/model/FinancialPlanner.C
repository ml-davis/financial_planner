#include "FinancialPlanner.H"

using namespace std;
using namespace boost;
using namespace boost::gregorian;

FinancialPlanner::FinancialPlanner()
{
}

FinancialPlanner::FinancialPlanner(const string& date)
{
  // load partitions and expenses from disk
  load(date);
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

void FinancialPlanner::load(const string& dateString)
{
  // remove all current data from "this"
  reset();

  date date { from_simple_string(dateString) };

  // TODO: only reset if not current date

  int month { date.month() };
  int year { date.year() };

  SqlFetcher fetcher;
  fetcher.load(*this, year, month);
}

const bool FinancialPlanner::hasPartition(string name)
{
  return _partitions.find(name) != _partitions.end();
}

void FinancialPlanner::setMonthlyIncome(const double amount)
{
  _monthlyIncome = amount;
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

void FinancialPlanner::reset()
{
  _partitions.clear();
  _expenses.clear();
}
