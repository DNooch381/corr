#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ();

void d_au200GeV2 ()
{
  string line;

  // --- Open file
  
  fstream myfile ("v22.dat");
  
  // --- Show file contents if opened successfully
  
  if (myfile.is_open())
    {
      while (getline (myfile,line))
	{
	  cout << line << '\n';
	}
      myfile.close();
    }

  // --- Error if unable to open/read
  
  else cout << "Unable to open file";

  return 0;
}
