#include "view/View.H"

#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
  auto globalStartTime = high_resolution_clock::now();

  View gui;

  auto globalEndTime = high_resolution_clock::now();
  auto program_duration = duration_cast<microseconds>(globalEndTime - globalStartTime).count();

  cout << "Program Setup = " << program_duration << " microseconds" << endl << endl;

  gui.printExpenses();
  gui.printRemaining();
}
