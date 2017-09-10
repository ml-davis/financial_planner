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

void SqlFetcher::load(FinancialPlanner& fp, const int year, const int month)
{
  try
  {
    Connection conn { establishConnection() };
    Query query { conn.query() };

    // Load partitions
    query << "SELECT "
          <<   "category, "
          <<   "description, "
          <<   "amount_reserved, "
          <<   "due_date "
          << "FROM "
          <<   "partitions";

    StoreQueryResult result { query.store() };
    for (size_t i = 0; i < result.num_rows(); i++)
    {
      string entry{};

      entry = { getEntry(result[i]["category"]) };
      string category { Validator::validateNewCategory(entry, fp.hasPartition(entry)) };

      entry = { getEntry(result[i]["description"]) };
      string description { entry };

      entry = { getEntry(result[i]["amount_reserved"]) };
      double amountReserved { Validator::validateDollarAmount(entry) };

      entry = { getEntry(result[i]["due_date"]) };
      int dueDate { Validator::validateDueDate(entry) };

      fp.addPartition(category, description, amountReserved, dueDate);
    }

    // Load expenses
    query << "SELECT "
          <<   "date, "
          <<   "category, "
          <<   "expenses.description, "
          <<   "cost "
          << "FROM "
          <<   "partitions, "
          <<   "expenses "
          << "WHERE "
          <<   "partition_id = category_id AND "
          <<   "YEAR(date) = "  << year << " AND "
          <<   "MONTH(date) = " << month;

    result = { query.store() };
    for (size_t i = 0; i < result.num_rows(); i++)
    {
      string entry{};

      entry = { getEntry(result[i]["date"]) };
      date date { Validator::validateDate(entry) };
      
      entry = { getEntry(result[i]["category"]) };
      string category { Validator::validateCategory(entry, fp.hasPartition(entry)) };

      entry = { getEntry(result[i]["description"]) };
      string description = { entry };

      entry = { getEntry(result[i]["cost"]) };
      double cost { Validator::validateDollarAmount(entry) };
      
      fp.addExpense(date, category, description, cost);
    }
  }
  catch (BadQuery er) // handle any connection or
  {
    // query errors that may come up
    cerr << "Error: " << er.what() << endl;
    exit(1);
  }
  catch (const BadConversion& er)
  {
    // Handle bad conversions
    cerr << "Conversion error: " << er.what() << endl
         << "\tretrieved data size: " << er.retrieved
         << ", actual size: " << er.actual_size << endl;
    exit(1);
  }
  catch (const Exception& er) 
  {
    // Catch-all for any other MySQL++ exceptions
    cerr << "Error: " << er.what() << endl;
    exit(1);
  }
}
