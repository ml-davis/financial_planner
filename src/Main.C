#include "view/View.H"

int main()
{
  View gui;

  gui.changeDate("2017-Aug-01");
  gui.printRemaining();

  gui.changeDate("2017-Sep-01");
  gui.printRemaining();
}
