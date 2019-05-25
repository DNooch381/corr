#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int TRandom_Test()
{
  srand(time(0));
  for(int x = 1; x<25;x++){
    cout << 1+(rand()%6) << endl;
  }
} 
