#include "IOHandler.H"

using namespace std;

void IOHandler::savePartitions(unordered_map<string, Partition> partitions)
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

