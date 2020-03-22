#include <iostream>
#include "RanGenX.C"

using namespace std;

int main()
{

  int howmany = 10;

  double space = 0.1; // default space between correlated ntuples...
  execute(howmany,700,2,space);
  execute(howmany,700,4,space);
  execute(howmany,700,6,space);
  execute(howmany,700,8,space);

  return 0;

}
