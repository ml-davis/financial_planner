#include "IOHandler.H"

using namespace std;
using namespace boost::gregorian;

void IOHandler::savePartitions(const unordered_map<string, Partition>& partitions)
{
  ofstream outputStream;
  outputStream.open(_partitionsFile);

  for (auto p: partitions)
  {
    outputStream << "-" << endl;
    outputStream << p.first << endl;
    outputStream << p.second.getDescription() << endl;
    outputStream << p.second.getDueDate() << endl;
    outputStream << p.second.getAmountReserved() << endl;
  }

  outputStream.close();
}

void IOHandler::saveExpenses(const vector<Expense>& expenses)
{
  ofstream outputStream;
  outputStream.open (_expensesFile);

  for (auto e: expenses)
  {
    outputStream << "-" << endl;
    outputStream << e.getDateString() << endl;
    outputStream << e.getCategory() << endl;
    outputStream << e.getDescription() << endl;
    outputStream << e.getCost() << endl;
  }

  outputStream.close();
}

void IOHandler::loadPartitions(FinancialPlanner& fp)
{
  string line;
  ifstream inputStream(_partitionsFile);
  if (inputStream.is_open())
  {
    while(getline(inputStream, line))
    {
      if (line == "-")
      {
        getline(inputStream, line);
        string category {Validator::validateNewCategory(line, fp.hasPartition(line))};

        getline(inputStream, line);
        string description {line};

        getline(inputStream, line);
        int dueDate {Validator::validateDueDate(line)};

        getline(inputStream, line);
        double amountReserved {Validator::validateDollarAmount(line)};

        fp.addPartition(category, description, amountReserved, dueDate);
      }
      else
      {
        cout << "Invalid formatting in partitions file" << endl;
        exit(1);
      }
    }

    inputStream.close();
  }
 }

void IOHandler::loadExpenses(FinancialPlanner& fp)
{
  string line;
  ifstream inputStream(_expensesFile);
  if (inputStream.is_open())
  {
    while(getline(inputStream, line))
    {
      if (line == "-")
      {
        getline(inputStream, line);
        date date {Validator::validateDate(line)};

        getline(inputStream, line);
        string category {Validator::validateCategory(line, fp.hasPartition(line))};

        getline(inputStream, line);
        string description{line};

        getline(inputStream, line);
        double cost {Validator::validateDollarAmount(line)};

        fp.addExpense(date, category, description, cost);
      }
      else
      {
        cout << "Invalid formatting of expenses file" << endl;
        exit(1);
      }
    }
    inputStream.close();
  }
 }
