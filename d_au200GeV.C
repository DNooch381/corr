#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int d_au200GeV()
{
  
  // --- Input file

  std::vector<int> numbers;
  ifstream inputFile("v22.dat");

  // --- Open the file

  if (inputFile.good())
    {
      
      // --- Push items into a vector 

      int current_number = 0;
      while (inputFile >> current_number)
	{
	  numbers.push_back(current_number);
	}

      // --- Display the numbers if no errors

      cout << "The numbers are: ";
      for (int count = 0; count < numbers.size(); count++)
	{
	  cout << numbers[count] << " ";
	}
      cout << endl;

      // --- Close input file

      inputFile.close();

    }

  
  // --- Error message if issue reading file

  else
    {
      cout << "Error!";
      _exit(0);
    }
  
  return 0;
}
