#include "FinancialCalculator.H"

using namespace boost;
using namespace boost::gregorian;
using namespace std;

FinancialCalculator::FinancialCalculator(double monthlyIncome)
  : _monthlyIncome(monthlyIncome)
{
}

void FinancialCalculator::addPartition(const string& name,
                                       const string& description,
                                       const double amount)
{
  Partition partition(description, 0, amount);
  _partitions.insert(pair<string, Partition>(name, partition));
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
                                     const string& comment,
                                     const double amount)
{
  // TODO: verify if valid date string or not
  Expense expense(from_simple_string(theDate), category, comment, amount);
  _expenses.push_back(expense);
}

void printLine()
{
  for (int i = 0; i < 103; i++)
  {
    cout << "-";
  }
  cout << endl;
}

void FinancialCalculator::showPartitions() 
{
  cout << "*** Partitions ***" << endl;
  printLine();
  for (auto p : _partitions)
  {
    format fmt("%-20s%-100s");
    cout << format(fmt) % p.first % p.second.asString() << endl;
  }
  printLine();
  format fmt("%-20s%83.2f");
  cout << format(fmt) % "Total" % _monthlyIncome << endl;
  printLine();
  cout << endl;
}

void FinancialCalculator::showExpenses()
{
  cout << "*** Expenses ***" << endl;
  printLine();
  for (auto expense : _expenses)
  {
    format fmt("%-20s%-20s%-55s%8.2f");
    cout << format(fmt) % 
      to_simple_string(expense.getDate()) % 
      expense.getCategory() % 
      expense.getComment() % 
      expense.getAmount() << endl;
  }
  printLine();
  cout << endl;
}

void FinancialCalculator::showRemaining()
{
  double total = _monthlyIncome;
  unordered_map<string, Partition> remaining = _partitions;
  for (auto expense : _expenses)
  {
    remaining.at(expense.getCategory()).reduceAmount(expense.getAmount());
    total -= expense.getAmount();
  }

  cout << "*** Remaining ***" << endl;
  printLine();
  for (auto p : remaining)
  {
    double percentRemaining = 100 * 
      (p.second.getAmount() / _partitions.at(p.first).getAmount());

    format fmt("%-20s%-83s%9.1f%%");
    cout << format(fmt) % p.first % p.second.asString() % percentRemaining << endl;
  }
  printLine();
  format fmt("%-20s%83.2f");
  cout << format(fmt) % "Total" % total << endl;
  printLine();
  cout << endl;
}
