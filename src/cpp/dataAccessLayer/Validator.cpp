#include <dataAccessLayer/Validator.h>

using namespace std;
using namespace boost;
using namespace boost::gregorian;

const int Validator::validateDueDate(const string& dueDateString)
{
  int dueDate{};

  try
  {
    dueDate = lexical_cast<int>(dueDateString);
    if (dueDate < 0 || dueDate > 31)
    {
      throw bad_lexical_cast();
    }
  }
  catch (bad_lexical_cast& e)
  {
    cout << "Error: Recieved an invalid due date" << endl;
    cout << "Due date must be an integer between 0 and 31" << endl;
    cout << "Due date received = " << dueDateString << endl;
    exit(1);
  }

  return dueDate;
}

const double Validator::validateDollarAmount(const string& dollarAmountString)
{
  double dollarAmount{};

  try
  {
    dollarAmount = lexical_cast<double>(dollarAmountString);
    if (dollarAmount <= 0)
    {
      throw bad_lexical_cast();
    }
  }
  catch (bad_lexical_cast& e)
  {
    cout << "Error: Received bad dollar amount" << endl;
    cout << "Dollar amount must be a double greater than 0" << endl;
    cout << "Dollar amount received = " << dollarAmountString << endl;
    exit(1);
  }

  return dollarAmount;
}

const date Validator::validateDate(const string& dateString)
{
  date date{};
  
  try
  {
    date = from_simple_string(dateString);
  }
  catch (boost::exception& e)
  {
    cout << "Error: Received invalid date string" << endl;
    cout << "Date must come in format: YYYY-MMM-dd (ex 2017-Aug-18)" << endl;
    cout << "Date received = " << dateString << endl;
    exit(1);
  }

  return date;
}

const string Validator::validateCategory(const string& categoryString,
                                         const bool isCategory)
{
  if (!isCategory)
  {
    cout << "Error: Received invalid category" << endl;
    cout << "Category for expense must exist inside partitions" << endl;
    cout << "Category received = " << categoryString << endl;
    exit(1);
  } 
  
  return categoryString;
}

const bool isEmpty(const std::string& str)
{
  for (char c: str)
  {
    if (c != ' ')
    {
      return false;
    }
  }

  return true;
}

const string Validator::validateNewCategory(const string& categoryString,
                                            const bool isCategory)
{
  if (isEmpty(categoryString))
  {
    cout << "Error: Category in partitions was left blank" << endl;
    cout << "You must create a name for your category" << endl;
    exit(1);
  }

  if (isCategory)
  {
    cout << "Error: Received a duplicate partition" << endl;
    cout << "Tried to create a partition with the same name more than once" << endl;
    cout << "Partition received = " << categoryString << endl;
    exit(1);
  }

  return categoryString;
}
