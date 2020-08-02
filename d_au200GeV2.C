#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ();

void d_au200GeV2 ()
{
  string line;
  fstream myfile ("v22.dat");
  if (myfile.is_open())
    {
      while (getline (myfile,line))
	{
	  cout << line << '\n';
	}
      myfile.close();
    }

  else cout << "Unable to open file";

  return 0;
}
