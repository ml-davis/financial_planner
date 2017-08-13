#pragma once

#include "Expense.H"
#include "Partition.H"
#include "IOHandler.H"
#include "View.H"

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
                      const double amount,
                      const unsigned short dueDate);

    void addExpense(const std::string& date,
                    const std::string& category,
                    const std::string& description,
                    const double amount);

    void save();

    void load();

    void viewExpenses();

    void viewRemaining();

  private:
    double                                      _monthlyIncome;
    std::unordered_map<std::string, Partition>  _partitions;
    std::vector<Expense>                        _expenses;

    void verifyPartitions();
};
