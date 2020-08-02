#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  
  // --- Input file

  //std::vector<int> numbers;
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

      // --- Close file

      inputFile.close();

      // --- Display the numbers if no errors

      cout << "The numbers are: ";
      for (int count = 0; count < numbers.size(); count++)
	{
	  cout << numbers[count] << " ";
	}
      cout << endl;
    }
  
  // --- Error message if issue reading file

  else
    {
      cout << "Error!";
      _exit(0);
    }
  
  return 0;
}
