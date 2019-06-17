#include "Recursion.C"
#include <sys/time.h>

//6.17.19 Run Time for J = 1000:  14m 16s
//6.17.19 Run Time for J = 10,000: 2hr 21m 16s  

void get_corr(int);

void do_recursion(vector<double>&); // start of recursion function
   
void RanGen2()  
{  

  struct timeval Time;

  gettimeofday(&Time,0);
  int begintime = Time.tv_sec;
  //cout<<"begintime is "<<begintime<<endl;

  Init(); // initialize histograms

  for ( int j = 0; j < 30; ++j )
    {
      if ( j % 10 == 0 ) cout << "Executing sequence j = " << j << endl;
      for ( int i = 1; i < 350; ++i )
	{
	  get_corr(i);
	}
    }

  TFile* HistFile = new TFile("FileOne.root","recreate");
  HistFile->cd();
  // --- write recursion histo
  for ( int cs = 0; cs < 2; ++cs )
    {
      for(int c = 0; c < maxCorrelator; ++c )
        {
	  hmult_recursion[cs][c]->Write();
        }
    }
  HistFile->Write();
  delete HistFile;

  gettimeofday(&Time,0);
  int endtime = Time.tv_sec;
  //cout<<"endtime is "<<endtime<<endl;

  int tdiff = endtime-begintime;

  cout<<"End of program."<<endl;
  cout<<"Execution time: "<<tdiff<<" seconds"<<endl;

} //end of void RanGen2()

void get_corr(int npairs)
{

  TRandom3 angle(0);

  vector <double> ang; // inserting pairs into single object

  // int = integer, i can always be at 0,
  // i < 100 means go up to 100 events, ++i checks if it's less
  // than 100 and adds 1 -- if more than 100, than the program stops

  for ( int i = 0; i < npairs; ++i )
    {
      //double means an exact number, phi1 is the name of the double for particle 1.
      double phi1 = angle.Uniform(-3.1415926535,3.1415926535);
      double phi2 = 0; //same as above, but for particle 2
      if ( phi1 > 0 ) phi2 = phi1 - 3.1415926535;
      if ( phi1 < 0 ) phi2 = phi1 + 3.1415926535;
      //cout << phi1 << " " << phi2 << endl;
      //cout << i << " " << endl;

      ang.push_back(phi1); //push_back to stack numbers on return
      ang.push_back(phi2);

    } // end of npairs for loop

  do_recursion(ang);

  return;

} //end of get_corr

void do_recursion(vector<double>& ang)
{

  for(int h=0;h<maxHarmonic;h++)
    {
      for(int w=0;w<maxPower;w++)
        {
          Qvector[h][w] = TComplex(0.,0.); // initialize Q-vector to zero
        } // end of loop over Qvector
    } // end of loop over maxHarmonic

  int mult = ang.size();

  for ( int i = 0; i < mult; ++i )
    {
      //cout << ang[i] << " " ;
      for(int h=0;h<maxHarmonic;h++)
        {
          double phi = ang[i];
          // do the summation for the Q-vectors
          for(int w=0;w<maxPower;w++)
            {
              Qvector[h][w] += TComplex(cos(h*phi),sin(h*phi));
            } // end of loop over powers
        } // end of loop over harmonics
    } // end of loop over ang vector

  // --- from generic formulas ----------------------------------------------------------------------------
  //  2-p correlations
  int harmonics_Two_Num[2] = {2,-2}; // 2, -2
  int harmonics_Two_Den[2] = {0,0}; // recursion gives the right combinatorics
  TComplex twoRecursion = Recursion(2,harmonics_Two_Num)/Recursion(2,harmonics_Two_Den).Re();
  double spwTwoRecursion = Recursion(2,harmonics_Two_Den).Re();
  double wTwoRecursion = 1.0;
  hmult_recursion[0][0]->Fill(mult,twoRecursion.Re(),wTwoRecursion);
  hmult_recursion[1][0]->Fill(mult,twoRecursion.Im(),wTwoRecursion);
  //  4-p correlations
  int harmonics_Four_Num[4] = {2,2,-2,-2};
  int harmonics_Four_Den[4] = {0,0,0,0};
  TComplex fourRecursion = Recursion(4,harmonics_Four_Num)/Recursion(4,harmonics_Four_Den).Re();
  double spwFourRecursion = Recursion(4,harmonics_Four_Den).Re();
  double wFourRecursion = 1.0;
  hmult_recursion[0][2]->Fill(mult,fourRecursion.Re(),wFourRecursion);
  hmult_recursion[1][2]->Fill(mult,fourRecursion.Im(),wFourRecursion);
  //  6-p correlations:
  int harmonics_Six_Num[6] = {2,2,2,-2,-2,-2};
  int harmonics_Six_Den[6] = {0,0,0,0,0,0};
  TComplex sixRecursion = Recursion(6,harmonics_Six_Num)/Recursion(6,harmonics_Six_Den).Re();
  double spwSixRecursion = Recursion(6,harmonics_Six_Den).Re();
  double wSixRecursion = 1.0;
  hmult_recursion[0][4]->Fill(mult,sixRecursion.Re(),wSixRecursion);
  hmult_recursion[1][4]->Fill(mult,sixRecursion.Im(),wSixRecursion);
  //  8-p correlations
  int harmonics_Eight_Num[8] = {2,2,2,2,-2,-2,-2,-2};
  int harmonics_Eight_Den[8] = {0,0,0,0,0,0,0,0};
  TComplex eightRecursion = Recursion(8,harmonics_Eight_Num)/Recursion(8,harmonics_Eight_Den).Re();
  double spwEightRecursion = Recursion(8,harmonics_Eight_Den).Re();
  double wEightRecursion = 1.0;
  hmult_recursion[0][6]->Fill(mult,eightRecursion.Re(),wEightRecursion);
  hmult_recursion[1][6]->Fill(mult,eightRecursion.Im(),wEightRecursion);

  // --- print statements for diagnostic purposes
  //cout << twoRecursion.Re() << endl;
  //cout << fourRecursion.Re() << endl;
  //cout << sixRecursion.Re() << endl;
  //cout << eightRecursion.Re() << endl;

} // end do_recursion functions
