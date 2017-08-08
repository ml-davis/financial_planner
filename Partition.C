#include "Partition.H" 

using namespace std;
using namespace boost;

Partition::Partition(string description,
                     string dueDate,
                     double amount)
  : _description(description),
    _amount(amount),
    _dueDate(dueDate)
{
}

const string Partition::asString() const
{
  format fmt("%-60sDue:%5d%14.2f");
  return str(format(fmt) % _description % _dueDate % _amount);
}

void Partition::reduceAmount(double deduction)
{
  _amount -= deduction;
}

const string& Partition::getDescription() const
{
  return _description;
}

const double Partition::getAmount() const
{
  return _amount;
}

const std::string& Partition::getDueDate() const
{
  return _dueDate;
}
