#include "Expense.H"

using namespace std;
using namespace boost::gregorian;

Expense::Expense(date date,
                 string category,
                 string description,
                 double cost)
  : _date(date),
    _category(category),
    _description(description),
    _cost(cost)
{
}

const string Expense::getDateString()
{
  return to_simple_string(_date);
}
