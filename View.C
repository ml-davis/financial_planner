#include "View.H"

using namespace std;
using namespace boost;

void printLine()
{
  for (int i = 0; i < 126; i++)
  {
    cout << "-";
  }
  cout << endl;
}

void View::printExpenses(const vector<Expense>& expenses)
{
  format fmt("%-16s%-20s%-82s%8s");
  cout << format(fmt) % "Date" % "Category" % "Description" % "Cost" << endl;
  
  printLine();
  for (auto expense : expenses)
  {
    format fmt("%-16s%-20s%-82s%8.2f");
    cout << format(fmt) % 
      expense.getDateString() % 
      expense.getCategory() % 
      expense.getDescription() % 
      expense.getCost() << endl;
  }
  printLine();
  cout << endl;
}

void View::printRemaining(const unordered_map<string, Partition>& partitions)
{
  double percentRemaining{};

  format fmt("%-20s%-68s%4s%11s%11s%11s");
  cout << format(fmt) % "Name" % "Description" % "Due" % "Rsv" % "Rmn"
    % "Pct" << endl;
  printLine();

  for (auto p : partitions)
  {
    percentRemaining = 100 * 
      (p.second.getAmountRemaining() / p.second.getAmountReserved());

    format fmt("%-20s%-68s%4s%11.2f%11.2f%11.1f%%");
    cout << format(fmt) %
      p.first %
      p.second.getDescription() %
      p.second.dueDateString() %
      p.second.getAmountReserved() %
      p.second.getAmountRemaining() %
      percentRemaining << endl;
  }

  printLine();
  cout << endl;
}

