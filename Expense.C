#include "Expense.H"

using namespace std;
using namespace boost::gregorian;

Expense::Expense(boost::gregorian::date date,
                 std::string category,
                 std::string comment,
                 double amount)
  : _date(date),
    _category(category),
    _comment(comment),
    _amount(amount)
{
}
