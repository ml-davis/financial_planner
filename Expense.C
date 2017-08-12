#include "Expense.H"

using namespace std;
using namespace boost::gregorian;

Expense::Expense(date date,
                 string category,
                 string comment,
                 double amount)
  : _date(date),
    _category(category),
    _comment(comment),
    _amount(amount)
{
}

const string Expense::getDateString()
{
  return to_simple_string(_date);
}
