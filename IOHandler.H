#pragma once

#include "Partition.H"
//#include <boost/lexical_cast.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

class IOHandler
{
  public:
    void savePartitionsToJSON(std::unordered_map<std::string, Partition> partitions);

    void savePartitions(std::unordered_map<std::string, Partition> partitions);

    std::unordered_map<std::string, Partition> loadPartitions();

  private:
    std::string _partitionsFile = "partitions";
};
