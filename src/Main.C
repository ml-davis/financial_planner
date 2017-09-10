#include "view/View.H"

#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
  View gui;

  gui.printRemaining();

  gui.changeDate("2017-Sep-01");

  gui.printRemaining();

  gui.changeDate("2017-Aug-01");

  gui.printRemaining();
}
