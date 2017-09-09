#include "View.H"

using namespace std;
using namespace boost;

void printLine()
{
  for (int i = 0; i < 150; i++)
  {
    cout << "-";
  }
  cout << endl;
}

View::View()
{
  _financialPlanner = FinancialPlanner(2852.26);
}

void View::printExpenses()
{
  double sum{0};

  format fmt("%-16s%-20s%-106s%8s");
  cout << format(fmt) % "Date" % "Category" % "Description" % "Cost" << endl;
  printLine();

  for (auto expense : _financialPlanner.getExpenses())
  {
    fmt = format("%-16s%-20s%-106s%8.2f");
    cout << format(fmt) % 
      expense.getDateString() % 
      expense.getCategory() % 
      expense.getDescription() % 
      expense.getCost() << endl;

    sum += expense.getCost();
  }
  printLine();

  fmt = format("%-142s%8.2f");
  cout << format(fmt) % "Total" % sum << endl;
  printLine();

  cout << endl;
}

void View::printRemaining()
{
  double totalRemaining{};
  double percentRemaining{};

  format fmt("%-20s%-81s%4s%11s%11s%11s%12s");
  cout << format(fmt) % "Name" % "Description" % "Due" % "Reserved" % 
    "Spent" % "Remaining" % "Percent" << endl;
  printLine();

  for (auto p : _financialPlanner.getPartitions())
  {
    percentRemaining = 100 * 
      (p.second.getAmountRemaining() / p.second.getAmountReserved());

    totalRemaining += p.second.getAmountRemaining();

    fmt = format("%-20s%-81s%4s%11.2f%11.2f%11.2f%11.1f%%");
    cout << format(fmt) %
      p.first %
      p.second.getDescription() %
      p.second.dueDateString() %
      p.second.getAmountReserved() %
      (p.second.getAmountReserved() - p.second.getAmountRemaining()) %
      p.second.getAmountRemaining() %
      percentRemaining << endl;
  }
  printLine();

  fmt = format("%-116s%11.2f%11.2f%11.1f%%");
  double monthlyIncome{_financialPlanner.getMonthlyIncome()};
  cout << format(fmt) % "Total" % monthlyIncome % totalRemaining % 
    (100 * (totalRemaining / monthlyIncome)) << endl;
  printLine();

  cout << endl;
}

