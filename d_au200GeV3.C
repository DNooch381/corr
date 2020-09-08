#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int nbins = 45;
const int nbins4 = 20;

//int main ();

void d_au200GeV3()
{
  //string line;

  TCanvas* c1 = new TCanvas("c1","");

  double x[nbins]; // number of tracks in the PHENIX FVTX
  double y[nbins]; // v2{2} (two-particle cumulant v2)
  double ey[nbins]; // statistical uncertainty
  double eysys[nbins]; // systematic uncertainty

  // --- 2-2 Particle Data File

  // --- Open v22.dat file

  ifstream textfile_v22("v22.dat");
  for ( int i = 0; i < nbins; ++i )
    {
      textfile_v22 >> x[i] >> y[i] >> ey[i] >> eysys[i];
      cout << x[i] << " " << y[i] << " " << ey[i] << endl;
    }

  TGraphErrors* tge_v22 = new TGraphErrors(nbins,x,y,0,ey);

  tge_v22->SetMarkerStyle(kFullSquare);
  tge_v22->SetMarkerColor(kRed);
  tge_v22->SetLineColor(kBlack);
  tge_v22->GetXaxis()->SetTitle("N_{tracks}^{FVTX}"); // x-axis
  //tge_v22->GetYaxis()->SetTitle("v_{2}{2}"); // y-axis
  tge_v22->GetYaxis()->SetTitle("v_{2}"); // y-axis
  tge_v22->Draw("ap");
  tge_v22->GetXaxis()->SetLimits(0.0,50.0); // x-axis range
  tge_v22->SetMinimum(0.0); // lowest y-axis value
  tge_v22->SetMaximum(0.13); // max y-axis value

  //Best Fit Line

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

  // --- 2-4 Particle Data File

  // --- Open v24.dat File

  double x4[nbins4]; // number of tracks in the PHENIX FVTX
  double y4[nbins4]; // v2{2} (two-particle cumulant v2)
  double ey4[nbins4]; // statistical uncertainty
  double eysys4[nbins4]; // systematic uncertainty
  ifstream textfile24("v24.dat");
  for ( int i = 0; i < nbins4; ++i )
    {
      textfile24 >> x4[i] >> y4[i] >> ey4[i] >> eysys4[i];
      cout << x4[i] << " " << y4[i] << " " << ey4[i] << endl;
    }

  TGraphErrors* tge_v24 = new TGraphErrors(nbins4,x4,y4,0,ey4);

  tge_v24->SetMarkerStyle(kFullSquare);
  tge_v24->SetMarkerColor(kBlue);
  tge_v24->SetLineColor(kBlack);
  tge_v24->GetXaxis()->SetTitle("N_{tracks}^{FVTX}"); // x-axis title
  tge_v24->GetYaxis()->SetTitle("v_{2}{4}"); // y-axis title
  tge_v24->Draw("p");
  tge_v24->GetXaxis()->SetLimits(0.0,50.0); // x-axis range
  tge_v24->SetMinimum(0.0); // lowest y-axis value
  tge_v24->SetMaximum(0.14); // max y-axis value

  TF1* fun6 = new TF1("fun6","pol1",4,50);
  fun6->SetParameter(0,1.0);
  fun6->SetParameter(1,1.0);
  fun6->SetLineColor(kBlack);
  fun6->SetLineWidth(2);
  tge_v24->Fit(fun6,"","",10,50);

  TLegend* leg = new TLegend(0.68,0.68,0.88,0.88); // the numbers are the coordinates x1,y1,x2,y2
  leg->AddEntry(tge_v22,"v_{2}{2}","p"); //"p" for point
  leg->AddEntry(tge_v24,"v_{2}{4}","p"); //"p" for point
  leg->Draw();

  c1->Print("dAu200_combfits.png");

  tge_v22->Draw("ap");
  tge_v24->Draw("p");
  leg->Draw();

  //TF1* fun7 = new TF1 ("fun7","[0]+[1]/pow(x,[2])",2,50);
  TF1* fun7 = new TF1 ("fun7","[0]+[1]/pow(x-1,[2])",2,50);
  fun7->SetParameter(0,0.05);
  fun7->SetParameter(1,0.1);
  fun7->SetParameter(2,0.5);
  //fun7->FitParameter(2,0.5);
  fun7->SetLineColor(kBlack);
  fun7->SetLineWidth(2);
  tge_v22->Fit(fun7,"","",2,50);

  c1->Print("dAu200_sepfits.png");

  double residual[nbins];
  for ( int i = 0; i < nbins; ++i )
    {
      residual[i] = (fun7->Eval(x[i]) - y[i])/y[i];
    }

  TGraphErrors* tge_residual = new TGraphErrors(nbins,x,residual,0,ey);
  tge_residual->SetMarkerStyle(kFullSquare);
  tge_residual->SetMarkerColor(kRed);
  tge_residual->SetLineColor(kBlack);
  tge_residual->GetXaxis()->SetTitle("N_{tracks}^{FVTX}"); // x-axis
  tge_residual->GetYaxis()->SetTitle("Fit residual (fit - data)/data"); // y-axis
  tge_residual->Draw("ap");
  tge_residual->GetXaxis()->SetLimits(0.0,50.0); // x-axis range
  tge_residual->SetMinimum(-0.2); // lowest y-axis value
  tge_residual->SetMaximum(0.2); // max y-axis value

  TLine line(0.0,0.0,50.0,0.0);
  line.SetLineColor(kBlack);
  line.SetLineWidth(2);
  line.SetLineStyle(2);
  line.Draw();

  c1->Print("dAu200_residual.png");

  return;

}
