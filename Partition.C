#include "Partition.H" 
#include <sstream>

using namespace std;
using namespace boost;

Partition::Partition(string description,
                     unsigned short dueDate,
                     double amount)
  : _description(description),
    _amount(amount),
    _dueDate(dueDate)
{
}

const string dueDateString(const unsigned short dueDate)
{
  if (dueDate == 0)
  {
    return "";
  }

  stringstream ss;

  ss << "Due: ";

  if (dueDate < 10)
  {
    ss << " ";
  }

  ss << dueDate;

  switch(dueDate % 10)
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

const string Partition::asString() const
{
  format fmt("%-65s%9s%14.2f");
  return str(format(fmt) % _description % dueDateString(_dueDate) % _amount);
}

void Partition::reduceAmount(double deduction)
{
  _amount -= deduction;
}

