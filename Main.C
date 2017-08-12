#include "FinancialCalculator.H"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{

  auto globalStartTime = high_resolution_clock::now();

  FinancialCalculator fp(2552.26);

  fp.showPartitions();
  fp.showExpenses();
  fp.showRemaining();

  auto globalEndTime = high_resolution_clock::now();
  auto program_duration = duration_cast<microseconds>(globalEndTime - globalStartTime).count();

  cout << "Total Program Duration = " << program_duration << " microseconds" << endl;
}
