#include "FinancialCalculator.H"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{

  auto globalStartTime = high_resolution_clock::now();

  FinancialCalculator fp(2552.26);

  // fp.addPartition("Rent",           "1601 Boul Angrignon, Apt 902 (Aldo Construction)",        1420.00,         1);
  // fp.addPartition("Metro",          "Monthly public transportation costs (STM)",                 83.00,         1);
  // fp.addPartition("Internet",       "Monthly internet fees (Videotron)",                         71.23,         4);
  // fp.addPartition("Bank",           "Monthly bank fees (RBC)",                                   10.95,         4);
  // fp.addPartition("Phones",         "Me and Azin's phone bill (Virgin Mobile)",                 150.18,        14);
  // fp.addPartition("Insurance",      "Tenant insurance. (Aviva - RBC)",                           15.54,        15);
  // fp.addPartition("Utilitiies",     "Electricity bill (Hydro QC)",                               60.00,        21);
  // fp.addPartition("Groceries",      "Monthly grocery costs",                                    400.00           );
  // fp.addPartition("Entertainment",  "Eating out/movies/bar/etc",                                 90.00           );
  // fp.addPartition("Debt",           "Paying off credit cards and student loans",                131.36           );
  // fp.addPartition("Clothing",       "Money put away for new clothes",                            20.00           );
  // fp.addPartition("Household",      "Money put away to buy stuff for apartment",                 50.00           );
  // fp.addPartition("Emergency",      "Money put away for unexpected costs",                       50.00           );

  fp.loadPartitions();

  fp.addExpense("2017-08-01", "Rent",           "Paid rent for August",                                   1420.00);
  fp.addExpense("2017-08-02", "Metro",          "Got monthly opus pass",                                    83.00);
  fp.addExpense("2017-08-02", "Entertainment",  "Went to Subway",                                           12.74);
  fp.addExpense("2017-08-03", "Groceries",      "Went to Costco to get meat",                              140.95);
  fp.addExpense("2017-08-03", "Emergency",      "Paid Phil for bach. party",                                23.00);
  fp.addExpense("2017-08-04", "Bank",           "Paid monthly bank fees at RBC",                            10.95);
  fp.addExpense("2017-08-04", "Emergency",      "Paid Simon for bach. party",                               10.00);
  fp.addExpense("2017-08-05", "Entertainment",  "Bought icecream with Azin",                                 5.00);
  fp.addExpense("2017-08-06", "Entertainment",  "Bought lunch for me and Azin at mall",                     29.54);
  fp.addExpense("2017-08-06", "Groceries",      "Bought fruit, milk, dishwasher detergent at Walmart",      46.91);
  fp.addExpense("2017-08-08", "Clothing",       "Bought collar stays for dress shirts",                     20.95);
  fp.addExpense("2017-08-08", "Internet",       "Paid internet bill for August",                            71.23);

  fp.showPartitions();
  fp.showExpenses();
  fp.showRemaining();

  auto globalEndTime = high_resolution_clock::now();
  auto program_duration = duration_cast<microseconds>(globalEndTime - globalStartTime).count();

  cout << "Total Program Duration = " << program_duration << " microseconds" << endl;
}
