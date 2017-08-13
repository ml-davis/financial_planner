#include "FinancialCalculator.H"

using namespace boost;
using namespace boost::gregorian;
using namespace std;

FinancialCalculator::FinancialCalculator(double monthlyIncome)
  : _monthlyIncome(monthlyIncome)
{
  // load partitions and expenses from disk
  load(); 
  verifyPartitions();
}

void FinancialCalculator::addPartition(const string& name,
                                       const string& description,
                                       const double amount,
                                       const unsigned short dueDate)
{
  Partition partition(description, dueDate, amount);
  _partitions.insert(pair<string, Partition>(name, partition));
}

void FinancialCalculator::addExpense(const string& theDate,
                                     const string& category,
                                     const string& description,
                                     const double amount)
{
  // TODO: verify if valid date string or not
  Expense expense(from_simple_string(theDate), category, description, amount);
  _partitions.at(category).reduceAmountRemaining(amount);
  _expenses.push_back(expense);
}

void FinancialCalculator::save()
{
  IOHandler io;
  io.savePartitions(_partitions);
  io.saveExpenses(_expenses);
}

void FinancialCalculator::load()
{
  IOHandler io;
  io.loadPartitions(*this);
  io.loadExpenses(*this); // expenses must be loaded after partitions
}

void FinancialCalculator::viewExpenses()
{
  View v;
  v.printExpenses(_expenses);
}

void FinancialCalculator::viewRemaining()
{
  View v;
  v.printRemaining(_partitions, _monthlyIncome);
}

void FinancialCalculator::verifyPartitions()
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
