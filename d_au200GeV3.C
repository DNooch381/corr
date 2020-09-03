#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int nbins = 45;

int main ();

void d_au200GeV3()
{
  //string line;

  TCanvas* c1 = new TCanvas("c1","");

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
  tge_v22->GetXaxis()->SetTitle("N_{tracks}^{FVTX}");
  tge_v22->GetYaxis()->SetTitle("v_{2}{2}");
  tge_v22->Draw("ap");
  tge_v22->GetXaxis()->SetLimits(0.0,50.0);
  tge_v22->SetMinimum(0.0);
  tge_v22->SetMaximum(0.13);


  TF1* fun2 = new TF1("fun2","[0]/pow(x,[1])",1.0, 500);
  fun2->SetParameter(0,1.0);
  fun2->SetParameter(1,1.0);
  fun2->SetLineColor(kBlack);
  fun2->SetLineWidth(2);

  tge_v22->Fit(fun2,"","",2,20);
  fun2->Draw("same");

  TF1* fun3 = (TF1*)fun2->Clone("fun3");
  tge_v22->Fit(fun3,"","",20,50);
  fun3->Draw("same");


  c1->Print("dAu200_combfits.png");


  return 0;

}
