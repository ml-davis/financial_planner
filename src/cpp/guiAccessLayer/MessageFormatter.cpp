#include <guiAccessLayer/MessageFormatter.h>

using namespace std;
using namespace boost;

string getLine()
{
  stringstream ss;
  for (int i = 0; i < 150; i++)
  {
    ss << "-";
  }
  ss << "\n";

  return ss.str();
}

string MessageFormatter::formatExpenses(const FinancialPlanner& financialPlanner)
{
  stringstream ss;
  ss << getLine();

  format fmt("%-16s%-20s%-106s%8s");
  ss << format(fmt) % "Date" % "Category" % "Description" % "Cost" << "\n";
  ss << getLine();

  for (auto expense : financialPlanner.getExpenses())
  {
    fmt = format("%-16s%-20s%-106s%8.2f");
    ss << format(fmt) % 
      expense.getDateString() % 
      expense.getCategory() % 
      expense.getDescription() % 
      expense.getCost() << "\n";
  }
  ss << getLine();

  return ss.str();
}

string MessageFormatter::formatRemaining(const FinancialPlanner& financialPlanner)
{
  stringstream ss;

  double spent{};
  double totalRemaining{};
  double percentRemaining{};

  ss << getLine();
  format fmt("%-20s%-81s%4s%11s%11s%11s%12s");
  ss << format(fmt) % "Name" % "Description" % "Due" % "Reserved" % 
    "Spent" % "Remaining" % "Percent" << "\n";
  ss << getLine();

  for (auto p : financialPlanner.getPartitions())
  {
    percentRemaining = 100 * 
      (p.second.getAmountRemaining() / p.second.getAmountReserved());

    totalRemaining += p.second.getAmountRemaining();
    
    spent += (p.second.getAmountReserved() - p.second.getAmountRemaining());

    fmt = format("%-20s%-81s%4s%11.2f%11.2f%11.2f%11.1f%%");
    ss << format(fmt) %
      p.first %
      p.second.getDescription() %
      p.second.dueDateString() %
      p.second.getAmountReserved() %
      (p.second.getAmountReserved() - p.second.getAmountRemaining()) %
      p.second.getAmountRemaining() %
      percentRemaining << "\n";
  }
  
  ss << getLine();

  fmt = format("%-105s%11.2f%11.2f%11.2f%11.1f%%");
  double monthlyIncome{financialPlanner.getMonthlyIncome()};
  ss << format(fmt) % "Total" % monthlyIncome % spent % totalRemaining % 
    (100 * (totalRemaining / monthlyIncome)) << "\n";
  ss << getLine();

  return ss.str();
}
