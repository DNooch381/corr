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
  double x[nbins]; // number of tracks in the PHENIX FVTX
  double y[nbins]; // v2{2} (two-particle cumulant v2)
  double ey[nbins]; // statistical uncertainty
  double eysys[nbins]; // systematic uncertainty

  ifstream textfile("v22.dat");
  for ( int i = 0; i < nbins; ++i )
    {
      textfile >> x[i] >> y[i] >> ey[i] >> eysys[i];
      cout << x[i] << " " << y[i] << " " << ey[i] << endl;
    }

  TGraphErrors* tge_v22 = new TGraphErrors(nbins,x,y,0,ey);
  
  tge_v22->SetMarkerStyle(kFullSquare);
  tge_v22->SetMarkerColor(kRed);
  tge_v22->SetLineColor(kBlack);
  
  tge_v22->Draw("ap");

  // To be added: best fit line, print graph to TFile, adjust graph axis, add graph key, add axis class names
  
  return 0;

}
