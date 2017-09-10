#pragma once

#include "Expense.H"
#include "Partition.H"
#include "SqlFetcher.H"

#include <boost/date_time/gregorian/gregorian.hpp>

#include <iostream>
#include <unordered_map>
#include <vector>

class FinancialPlanner
{
  public:
    FinancialPlanner();

    FinancialPlanner(const double monthlyIncome, const std::string& date);

    void addPartition(const std::string& name,
                      const std::string& description,
                      const double amount,
                      const int dueDate);

    void addExpense(const boost::gregorian::date& date,
                    const std::string& category,
                    const std::string& description,
                    const double amount);

    void load(const std::string& dateString);

    const bool hasPartition(std::string name);

    const inline double getMonthlyIncome() const
    {
      return _monthlyIncome;
    }

    const inline std::unordered_map<std::string, Partition>& getPartitions() const
    {
      return _partitions;
    }

    const inline std::vector<Expense>& getExpenses() const
    {
      return _expenses;
    }

  private:
    double                                      _monthlyIncome;
    std::unordered_map<std::string, Partition>  _partitions;
    std::vector<Expense>                        _expenses;

    void verifyPartitions();
    void reset();
};
