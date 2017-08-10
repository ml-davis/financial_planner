#pragma once

#include "Partition.H"
#include <fstream>
#include <unordered_map>

class IOHandler
{
  public:
    void savePartitions(std::unordered_map<std::string, Partition> partitions);
};
