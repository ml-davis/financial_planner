#include "model/Communicator.H"

using namespace std;

int main()
{
  Communicator communicator;

  communicator.changeDate("2017-Aug-01");
  cout << communicator.getRemaining() << endl;

  communicator.changeDate("2017-Sep-01");
  cout << communicator.getRemaining() << endl;
}
