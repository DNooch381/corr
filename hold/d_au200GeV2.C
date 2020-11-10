#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main ();

void d_au200GeV2 ()
{
  string line;

  // --- Open file
  
  fstream textfile ("v22.dat");
  
  // --- Show file contents if opened successfully
  
  if (textfile.is_open())
    {

      while (getline (textfile,line))
	{
	  cout << line << '\n';
	}

      // --- Close input file
      
      textfile.close();
      
    }

  // --- Error if unable to open/read
  
  else cout << "Unable to open file";

  return 0;
}
