#pragma once

#include "FinancialPlanner.H"
#include "Expense.H"
#include "Partition.H"

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

// forward declaration needed
class FinancialCalculator;

class IOHandler
{
  public:
    void savePartitions(const std::unordered_map<std::string, Partition>& partitions);

    void saveExpenses(const std::vector<Expense>& expenses);

    void loadPartitions(FinancialCalculator& fp);

    void loadExpenses(FinancialCalculator& fp);

  private:
    std::string _partitionsFile = "io/partitions";
    std::string _expensesFile = "io/expenses";
};
