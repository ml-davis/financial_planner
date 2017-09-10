#include "view/View.H"

#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
  View gui;

  gui.printExpenses();
  gui.printRemaining();
}
