#pragma once

#include "FinancialPlanner.H"
#include "Expense.H"
#include "Partition.H"
#include "Validator.H"

#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

// forward declaration needed due to circular dependency
class FinancialPlanner;

class IOHandler
{
  public:
    void savePartitions(const std::unordered_map<std::string, Partition>& partitions);

    void saveExpenses(const std::vector<Expense>& expenses);

    void loadPartitions(FinancialPlanner& fp);

    void loadExpenses(FinancialPlanner& fp);

  private:
    const std::string _partitionsFile{"io/partitions"};
    const std::string _expensesFile{"io/expenses"};
};
