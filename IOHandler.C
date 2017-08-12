#include "IOHandler.H"

using namespace std;

void IOHandler::savePartitionsToJSON(unordered_map<string, Partition> partitions)
{
  ofstream outputStream;
  outputStream.open ("partitions.json");

  outputStream << "{\n";
  size_t index = 0;
  for (auto p: partitions)
  {
    outputStream << "\t\"" << p.first << "\": {\n";
    outputStream << "\t\t\"description\": \"" << p.second.getDescription() << "\",\n";
    outputStream << "\t\t\"dueDate\": " << p.second.getDueDate() << ",\n";
    outputStream << "\t\t\"amount\": " << p.second.getAmount() << "\n";

    if (++index < partitions.size())
    {
      outputStream << "\t},\n";
    }
    else
    {
      outputStream << "\t}\n";
    }
  }
  outputStream << "}";

  outputStream.close();
}

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
    outputStream << p.second.getAmount() << endl;
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
    outputStream << e.getComment() << endl;
    outputStream << e.getAmount() << endl;
  }

  outputStream.close();
}

unordered_map<string, Partition> IOHandler::loadPartitions()
{
  // TODO: verify types

  unordered_map<string, Partition> map;

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
        double amount = stod(line);

        Partition partition(description, dueDate, amount);
        map.insert(pair<string, Partition>(name, partition));
      }
    }
    inputStream.close();
  }
  // TODO: else -> throw error

  return map;
 }
