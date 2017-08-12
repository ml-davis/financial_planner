#pragma once

#include "Expense.H"
#include "Partition.H"

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

class IOHandler
{
  public:
    void savePartitionsToJSON(std::unordered_map<std::string, Partition> partitions);

    void savePartitions(const std::unordered_map<std::string, Partition>& partitions);

    void saveExpenses(const std::vector<Expense>& expenses);

    std::unordered_map<std::string, Partition> loadPartitions();

    std::vector<Expense> loadExpenses();

  private:
    std::string _partitionsFile = "partitions";
    std::string _expensesFile = "expenses";
};
