#pragma once

#include "Partition.H"
#include <fstream>
#include <unordered_map>

class IOHandler
{
  public:
    void savePartitionsToJSON(std::unordered_map<std::string, Partition> partitions);

    void savePartitions(std::unordered_map<std::string, Partition> partitions);

    std::unordered_map<std::string, Partition> loadPartitions();
};
