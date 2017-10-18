#include <financialPlanner/Partition.h>
#include <sstream>

using namespace std;

Partition::Partition(string description,
                     int dueDate,
                     double amountReserved)
  : _description(description),
    _dueDate(dueDate),
    _amountReserved(amountReserved),
    _amountRemaining(amountReserved)
{
}

const string Partition::dueDateString()
{
  if (_dueDate == 0)
  {
    return "";
  }

  stringstream ss;

  if (_dueDate < 10)
  {
    ss << " ";
  }

  ss << _dueDate;

  switch(_dueDate % 10)
  {
    case (1): ss << "st";
              break;
    case (2): ss << "nd";
              break;
    case (3): ss << "rd";
              break;
    default: ss << "th";
             break;
  }
  
  return ss.str();
}

void Partition::reduceAmountRemaining(double deduction)
{
  _amountRemaining -= deduction;
}

