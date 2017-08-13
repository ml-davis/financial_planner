#include "IOHandler.H"

using namespace std;
using namespace boost::gregorian;

void IOHandler::savePartitions(const unordered_map<string, Partition>& partitions)
{
  ofstream outputStream;
  outputStream.open (_partitionsFile);

  size_t index = 0;
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

  size_t index = 0;
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

void IOHandler::loadPartitions(FinancialCalculator& fp)
{
  // TODO: verify types

  string line;
  ifstream inputStream(_partitionsFile);
  if (inputStream.is_open())
  {
    while(getline(inputStream, line))
    {
      if (line == "-")
      {
        getline(inputStream, line);
        string name{line};

        getline(inputStream, line);
        string description{line};

        getline(inputStream, line);
        unsigned short dueDate = stoi(line);

        getline(inputStream, line);
        double amountReserved{stod(line)};

        fp.addPartition(name, description, amountReserved, dueDate);
      }
    }
    inputStream.close();
  }
  
  // TODO: else -> throw error
 }

void IOHandler::loadExpenses(FinancialCalculator& fp)
{
  // TODO: verify types

  string line;
  ifstream inputStream(_expensesFile);
  if (inputStream.is_open())
  {
    while(getline(inputStream, line))
    {
      if (line == "-")
      {
        getline(inputStream, line);
        string date{line};

        getline(inputStream, line);
        string category{line};

        getline(inputStream, line);
        string description{line};

        getline(inputStream, line);
        double cost{stod(line)};

        fp.addExpense(date, category, description, cost);
      }
    }
    inputStream.close();
  }

  // TODO: else -> throw error
 }
