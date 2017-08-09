#include "Partition.H" 

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

const string Partition::asString() const
{
  string suffix{};
  switch(_dueDate % 10)
  {
    case (1): suffix = "st";
              break;
    case (2): suffix = "nd";
              break;
    case (3): suffix = "rd";
              break;
    default: suffix = "th";
             break;
  }

  if (_dueDate > 0)
  {
    format fmt("%-65sDue:%3d%2s%14.2f");
    return str(format(fmt) % _description % _dueDate % suffix % _amount);
  }
  else
  {
    format fmt("%-74s%14.2f");
    return str(format(fmt) % _description % _amount);
  }
}

void Partition::reduceAmount(double deduction)
{
  _amount -= deduction;
}

