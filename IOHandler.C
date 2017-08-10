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

void IOHandler::savePartitions(unordered_map<string, Partition> partitions)
{
  ofstream outputStream;
  outputStream.open ("partitions");

  size_t index = 0;
  for (auto p: partitions)
  {
    outputStream << p.first << endl;
    outputStream << p.second.getDescription() << endl;
    outputStream << p.second.getDueDate() << endl;
    outputStream << p.second.getAmount() << endl;
    outputStream << endl;
  }

  outputStream.close();
}
