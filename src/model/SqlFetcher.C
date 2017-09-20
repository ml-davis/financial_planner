#include "SqlFetcher.H"

using namespace boost::gregorian;
using namespace mysqlpp;
using namespace std;

Connection establishConnection()
{
  Connection conn(false);

  // TODO: determine these values in program rather than using hard-coded values

  conn.connect("financial_planner", // database name (must be running)
               "localhost",         // hostname 
               "matthew",           // user 
               getenv("DB_PSWD"));  // environment variable 'DB_PSWD' must be set

  return conn;
}

string getEntry(const auto& entry)
{
    return string{entry.data(), entry.length()};
}

void loadMonthlyIncome(FinancialPlanner& fp, Query& query, const int year, const int month)
{
  query << "SELECT "
        <<   "SUM(amount) AS monthlyIncome "
        << "FROM "
        <<   "income "
        << "WHERE "
        <<   "YEAR(date) = " << year << " AND "
        <<   "MONTH(date) = " << month;

  StoreQueryResult result { query.store() };
  if (result[0]["monthlyIncome"].is_null())
  {
    cout << "No results returned from income table for "
         << year << "-" << month << endl;
    exit(1);
  }

  string entry { getEntry(result[0]["monthlyIncome"]) };
  double income { Validator::validateDollarAmount(entry) };
  fp.setMonthlyIncome(income);
}

void loadPartitions(FinancialPlanner& fp, Query& query, const int year, const int month)
{
  query << "SELECT "
        <<   "name, "
        <<   "description, "
        <<   "amount, "
        <<   "due_date "
        << "FROM "
        <<   "targets, "
        <<   "expense_types "
        << "WHERE "
        <<   "targets.type_id = expense_types.type_id AND "
        <<   "YEAR(date) = " << year << " AND "
        <<   "MONTH(date) = " << month;

  StoreQueryResult result { query.store() };
  if (result.num_rows() == 0)
  {
    cout << "No results returned from partitions table for "
         << year << "-" << month << endl;
    exit(1);
  }

  string entry {};
  for (size_t i = 0; i < result.num_rows(); i++)
  {
    entry = { getEntry(result[i]["name"]) };
    string category { Validator::validateNewCategory(entry, fp.hasPartition(entry)) };

    entry = { getEntry(result[i]["description"]) };
    string description { entry };

    entry = { getEntry(result[i]["amount"]) };
    double amountReserved { Validator::validateDollarAmount(entry) };

    entry = { getEntry(result[i]["due_date"]) };
    int dueDate { Validator::validateDueDate(entry) };

    fp.addPartition(category, description, amountReserved, dueDate);
  }
}

void loadExpenses(FinancialPlanner& fp, Query& query, const int year, const int month)
{
  query << "SELECT "
        <<   "date, "
        <<   "name, "
        <<   "expenses.description AS description, "
        <<   "cost "
        << "FROM "
        <<   "expenses, "
        <<   "expense_types "
        << "WHERE "
        <<   "expenses.type_id = expense_types.type_id AND "
        <<   "YEAR(expenses.date) = "  << year << " AND "
        <<   "MONTH(expenses.date) = " << month;

  StoreQueryResult result { query.store() };

  string entry {};
  for (size_t i = 0; i < result.num_rows(); i++)
  {
    entry = { getEntry(result[i]["date"]) };
    date date { Validator::validateDate(entry) };

    entry = { getEntry(result[i]["name"]) };
    string category { Validator::validateCategory(entry, fp.hasPartition(entry)) };

    entry = { getEntry(result[i]["description"]) };
    string description = { entry };

    entry = { getEntry(result[i]["cost"]) };
    double cost { Validator::validateDollarAmount(entry) };

    fp.addExpense(date, category, description, cost);
  }
}

void SqlFetcher::load(FinancialPlanner& fp, const int year, const int month)
{
  try
  {
    Connection conn { establishConnection() };
    Query query { conn.query() };

    loadMonthlyIncome(fp, query, year, month);
    loadPartitions(fp, query, year, month);
    loadExpenses(fp, query, year, month);
  }
  catch (BadQuery er) // handle any connection or
  {
    // query errors that may come up
    cerr << "Bad query error when loading database: " << er.what() << endl;
    exit(1);
  }
  catch (const BadConversion& er)
  {
    // Handle bad conversions
    cerr << "Bad conversion error when loading database: " << endl;
    cerr << "Conversion error: " << er.what() << endl
         << "\tretrieved data size: " << er.retrieved
         << ", actual size: " << er.actual_size << endl;
    exit(1);
  }
  catch (const Exception& er) 
  {
    // Catch-all for any other MySQL++ exceptions
    cerr << "Error loading database: " << er.what() << endl;
    exit(1);
  }
  catch (...)
  {
    cerr << "Error loading database" << endl;
    exit(1);
  }
}
