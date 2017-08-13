#include "FinancialCalculator.H"

using namespace boost;
using namespace boost::gregorian;
using namespace std;

// round to nearest hundred
double round(double x)
{
  x /= 100;
  return floor(x + 0.5) * 100;
}

FinancialCalculator::FinancialCalculator(double monthlyIncome)
  : _monthlyIncome(monthlyIncome),
    _unpartitionedIncome(monthlyIncome)
{
  // load partitions and expenses from disk
  load(); 

  // round needed to get rid of floating point rounding errors (really small numbers)
  if (round(_unpartitionedIncome) != 0.00)
  {
    cerr << "You have unpartitioned income: $" << _unpartitionedIncome << endl;
    exit(1);
  }
}

void FinancialCalculator::addPartition(const string& name,
                                       const string& description,
                                       const double amount,
                                       const unsigned short dueDate)
{
  if ((_unpartitionedIncome - amount) >= 0)
  {
    Partition partition(description, dueDate, amount);
    _partitions.insert(pair<string, Partition>(name, partition));
    _unpartitionedIncome -= amount;
  }
  else
  {
    cerr << "Insufficient Funds: " << endl;
    exit(1);
  }
}

void FinancialCalculator::addExpense(const string& theDate,
                                     const string& category,
                                     const string& comment,
                                     const double amount)
{
  // TODO: verify if valid date string or not
  Expense expense(from_simple_string(theDate), category, comment, amount);
  _partitions.at(category).reduceRemaining(amount);
  _expenses.push_back(expense);
}

void printLine()
{
  for (int i = 0; i < 126; i++)
  {
    cout << "-";
  }
  cout << endl;
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

void FinancialCalculator::showExpenses()
{
  format fmt("%-16s%-20s%-82s%8.2f");
  cout << format(fmt) % "Date" % "Category" % "Comment" % "Amount" << endl;
  
  printLine();
  for (auto expense : _expenses)
  {
    format fmt("%-16s%-20s%-82s%8.2f");
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
  double percentRemaining{};

  format fmt("%-20s%-68s%4s%11s%11s%11s");
  cout << format(fmt) % "Name" % "Description" % "Due" % "Amount" % "Remain"
    % "Pct" << endl;
  printLine();

  for (auto p : _partitions)
  {
    percentRemaining = 100 * (p.second.getRemaining() / p.second.getAmount());

    format fmt("%-20s%-94s%10.1f%%");
    cout << format(fmt) % p.first % p.second.asString() % percentRemaining << endl;
  }

  printLine();
  cout << endl;
}
