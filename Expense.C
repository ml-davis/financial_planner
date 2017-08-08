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

const date& Expense::getDate() const
{
  return _date;
}

const string& Expense::getCategory() const
{
  return _category;
}

const string& Expense::getComment() const
{
  return _comment;
}

const double Expense::getAmount() const
{
  return _amount;
}
