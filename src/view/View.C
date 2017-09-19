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
  _financialPlanner = { FinancialPlanner() };
}

void View::printExpenses()
{
  printLine();
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
  }
  printLine();
}

void View::printRemaining()
{
  double spent{};
  double totalRemaining{};
  double percentRemaining{};

  printLine();
  format fmt("%-20s%-81s%4s%11s%11s%11s%12s");
  cout << format(fmt) % "Name" % "Description" % "Due" % "Reserved" % 
    "Spent" % "Remaining" % "Percent" << endl;
  printLine();

  for (auto p : _financialPlanner.getPartitions())
  {
    percentRemaining = 100 * 
      (p.second.getAmountRemaining() / p.second.getAmountReserved());

    totalRemaining += p.second.getAmountRemaining();
    
    spent += (p.second.getAmountReserved() - p.second.getAmountRemaining());

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

  fmt = format("%-105s%11.2f%11.2f%11.2f%11.1f%%");
  double monthlyIncome{_financialPlanner.getMonthlyIncome()};
  cout << format(fmt) % "Total" % monthlyIncome % spent % totalRemaining % 
    (100 * (totalRemaining / monthlyIncome)) << endl;
  printLine();
}

void View::changeDate(const string& date)
{
  _financialPlanner.load(date);
}
