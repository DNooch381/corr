#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int nbins = 45;

int main ();

void d_au200GeV3()
{
  //string line;

  // --- Open file

  double x[nbins];
  double y[nbins];
  double ey[nbins]; // stat uncert
  double eysys[nbins]; // sys uncert

  ifstream textfile("v22.dat");
  for ( int i = 0; i < nbins; ++i )
    {
      textfile >> x[i] >> y[i] >> ey[i] >> eysys[i];
      cout << x[i] << " " << y[i] << " " << ey[i] << endl;
    }

  TGraphErrors* tge_v22 = new TGraphErrors(nbins,x,y,0,ey);
  tge_v22->SetMarkerStyle(kFullSquare);
  tge_v22->SetMarkerColor(kRed);
  tge_v22->Draw("ap");

  return 0;
}
