#include "Recursion.C"
#include <utility>
#include <sys/time.h>

const double pi = 3.14159265358979;

// --- correlation function (generates particles, calls recursion)
void get_corr(int,int,double); // primary
void get_corr(int,int); // calls primary with a default

// --- recursion function (uses vector of angles to do calculations)
void do_correlation(vector<pair<double,double>>&);

// --- gets system time, executes get_corr inside of over sequences/events
void execute(int,int,int,double); // primary
void execute(int,int,int); // calls primary with a default

void RanGen2B()
{
  int howmany = 1;
  double space = 0.1; // default space between correlated ntuples...
  execute(howmany,100,2,pi);
  execute(howmany,100,4,pi/2);
  execute(howmany,100,6,pi/3);
  execute(howmany,100,8,pi/4);

}

void execute(int sequences, int nparticles, int ntuple)
{
  execute(sequences,nparticles,ntuple,0.1);
}

void execute(int sequences, int nparticles, int ntuple, double space)
{

  int stop = nparticles/ntuple;

  struct timeval Time;

  gettimeofday(&Time,0);
  int begintime = Time.tv_sec;
  //cout<<"begintime is "<<begintime<<endl;

  Init(); // initialize histograms

  // --- generate the correlations
  for ( int j = 0; j < sequences; ++j )
    {
      if ( j % 10 == 0 ) cout << "Executing sequence j = " << j << endl;
      for ( int i = 1; i < stop; ++i )
	{
	  get_corr(i,ntuple,space);
	}
    }

  // --- Use a time struct to get the current date and time to append to the output file names
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);

  char timestamp[100];
  char daypart[100];
  char timepart[100];

  printf("now: %02d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  sprintf(timepart,"%02d%02d", tm.tm_hour, tm.tm_min);
  sprintf(daypart,"%02d%02d%02d",tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
  sprintf(timestamp,"%s-%s",daypart,timepart);
  cout<<"time stamp is "<<timestamp<<endl;

  //--- make an output file to write the histograms
  TFile* HistFile = new TFile(Form("OutputFiles/OutFile_BinaryC_%s_k%d.root",timestamp,ntuple),"recreate");
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

  Delete(); // delete histograms

  gettimeofday(&Time,0);
  int endtime = Time.tv_sec;
  //cout<<"endtime is "<<endtime<<endl;

  int tdiff = endtime-begintime;

  cout<<"End of program."<<endl;
  cout<<"Execution time: "<<tdiff<<" seconds"<<endl;

} //end of void RanGen2()



void get_corr(int nparticles, int ntuple)
{
  get_corr(nparticles,ntuple,0.1);
}

void get_corr(int nparticles, int ntuple, double space)
{

  //vector <double> ang; // inserting pairs into single object
  vector<pair<double,double>> object;

  // int = integer, i can always be at 0,
  // i < 100 means go up to 100 events, ++i checks if it's less
  // than 100 and adds 1 -- if more than 100, than the program stops

  int stop = nparticles/ntuple;

  for ( int i = 0; i < stop; ++i )
    {
      for ( int j = 0; j < ntuple; ++j )
        {
          object.push_back(make_pair(i,j));
        } // member of group (individual particle)
    } // group (correlated ntuple)

  //cout << "size1 " << object.size() << endl;

  do_correlation(object);

  return;

} //end of get_corr



void do_correlation(vector<pair<double,double>>& object)
{

  int mult = object.size();
  // cout << "size2 " << object.size() << endl;
  // cout << "size3 " << mult << endl;

  double two = 0;
  double two_norm = 0;
  double four = 0;
  double four_norm = 0;
  double six = 0;
  double six_norm = 0;
  double eight = 0;
  double eight_norm = 0;

  for ( int i = 0; i < mult; ++i )
    {
      double group_number_p1 = object[i].first;
      double parti_number_p1 = object[i].second;
      for ( int j = i+1; j < mult; ++j )
        {
          double group_number_p2 = object[j].first;
          double parti_number_p2 = object[j].second;
          if ( group_number_p1 == group_number_p2 ) ++two;
          ++two_norm;
          for ( int k = j+1; k < mult; ++k )
            {
              double group_number_p3 = object[k].first;
              double parti_number_p3 = object[k].second;
              for ( int l = k+1; l < mult; ++l )
                {
                  double group_number_p4 = object[l].first;
                  double parti_number_p4 = object[l].second;
                  if ( group_number_p1 == group_number_p2 &&
                       group_number_p1 == group_number_p3 &&
                       group_number_p1 == group_number_p4 ) ++four;
                  ++four_norm;
                  //cout << "hello" << endl;
                }
            }
        }
    }
  two /= two_norm;
  four /= four_norm;



  // --- from generic formulas ----------------------------------------------------------------------------
  //  2-p correlations
  hmult_recursion[0][0]->Fill(mult,two);
  hmult_recursion[1][0]->Fill(mult,two);
  //  4-p correlations
  hmult_recursion[0][2]->Fill(mult,four);
  hmult_recursion[1][2]->Fill(mult,four);
  //  6-p correlations:
  hmult_recursion[0][4]->Fill(mult,six);
  hmult_recursion[1][4]->Fill(mult,six);
  //  8-p correlations
  hmult_recursion[0][6]->Fill(mult,eight);
  hmult_recursion[1][6]->Fill(mult,eight);

  // --- print statements for diagnostic purposes
  //cout << twoRecursion.Re() << endl;
  //cout << fourRecursion.Re() << endl;
  //cout << sixRecursion.Re() << endl;
  //cout << eightRecursion.Re() << endl;

} // end do_recursion functions
