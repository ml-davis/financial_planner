#pragma once

#include "Expense.H"
#include "Partition.H"
#include "IOHandler.H"
#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <unordered_map>
#include <vector>

class FinancialCalculator
{
  public:
    FinancialCalculator(double monthlyIncome);
    
    void addPartition(const std::string& name,
                      const std::string& description,
                      const double amount);

    void addPartition(const std::string& name,
                      const std::string& description,
                      const double amount,
                      const unsigned short dueDate);

    void addExpense(const std::string& date,
                    const std::string& category,
                    const std::string& comment,
                    const double amount);

    void savePartitions();

    void saveExpenses();

    void loadPartitions();

    void loadExpenses();

    void showPartitions();

    void showExpenses();

    void showRemaining();

  private:
    double                                      _monthlyIncome;
    std::unordered_map<std::string, Partition>  _partitions;
    std::vector<Expense>                        _expenses;
};
