#include <boost/format.hpp>

#include "Expense.H"
#include "Partition.H"

#include <iostream>
#include <unordered_map>
#include <vector>

class View
{
  public:
    void printExpenses(const std::vector<Expense>& expenses);

    void printRemaining(const std::unordered_map<std::string, Partition>& partitions);

};
