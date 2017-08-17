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

View::View()
{
  _financialPlanner = FinancialPlanner(2552.26);
}

void View::printExpenses()
{
  double sum{0};

  format fmt("%-16s%-20s%-82s%8s");
  cout << format(fmt) % "Date" % "Category" % "Description" % "Cost" << endl;
  printLine();

  for (auto expense : _financialPlanner.getExpenses())
  {
    fmt = format("%-16s%-20s%-82s%8.2f");
    cout << format(fmt) % 
      expense.getDateString() % 
      expense.getCategory() % 
      expense.getDescription() % 
      expense.getCost() << endl;

    sum += expense.getCost();
  }
  printLine();

  fmt = format("%-118s%8.2f");
  cout << format(fmt) % "Total" % sum << endl;
  printLine();

  cout << endl;
}

void View::printRemaining()
{
  double totalRemaining{};
  double percentRemaining{};

  format fmt("%-20s%-68s%4s%11s%11s%11s");
  cout << format(fmt) % "Name" % "Description" % "Due" % "Rsv" % "Rmn"
    % "Pct" << endl;
  printLine();

  for (auto p : _financialPlanner.getPartitions())
  {
    percentRemaining = 100 * 
      (p.second.getAmountRemaining() / p.second.getAmountReserved());

    totalRemaining += p.second.getAmountRemaining();

    fmt = format("%-20s%-68s%4s%11.2f%11.2f%11.1f%%");
    cout << format(fmt) %
      p.first %
      p.second.getDescription() %
      p.second.dueDateString() %
      p.second.getAmountReserved() %
      p.second.getAmountRemaining() %
      percentRemaining << endl;
  }
  printLine();

  fmt = format("%-92s%11.2f%11.2f%11.1f%%");
  double monthlyIncome{_financialPlanner.getMonthlyIncome()};
  cout << format(fmt) % "Total" % monthlyIncome % totalRemaining % 
    (100 * (totalRemaining / monthlyIncome)) << endl;
  printLine();

  cout << endl;
}

