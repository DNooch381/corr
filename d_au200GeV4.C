#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int nbins = 45;
const int nbins4 = 20;

//int main ();

void take_fun(TF1*);
void take_fun(TF1*,TF1*,int);

void d_au200GeV4()
{

  TF1* trialfun5 = new TF1 ("trialfun5","[0]/sqrt(x-1) + [1]",2,50);
  trialfun5->SetParameter(0,0.1);
  trialfun5->SetParameter(1,0.05);
  take_fun(trialfun5);

  TF1* trialfun2 = new TF1 ("trialfun5","[0]",0,50);
  take_fun(trialfun5,trialfun2,2);

  //return;

  TF1* trialfun51 = new TF1 ("trialfun51","[0]/sqrt(x-1) + pol1(1)",2,50);
  trialfun51->SetParameter(0,0.1);
  trialfun51->SetParameter(1,0.05);
  trialfun51->SetParameter(2,0.0);
  take_fun(trialfun51);

  TF1* trialfun21 = new TF1 ("trialfun21","pol1",0,50);
  take_fun(trialfun51,trialfun21,3);

  //sqrt(x)
  
  TF1* trialfun51sq = new TF1 ("trialfun51sq","[0]/sqrt(x-1) + pol1(1) + [3] * sqrt(x)",2,50);
  trialfun51sq->SetParameter(0,0.1);
  trialfun51sq->SetParameter(1,0.05);
  trialfun51sq->SetParameter(2,0.0);
  take_fun(trialfun51sq);

  TF1* trialfun21sq = new TF1 ("trialfun21sq","pol1(0) + [2] * sqrt(x)",0,50);
  take_fun(trialfun51sq,trialfun21sq,4);

  //sqrt(10x)
  
  TF1* trialfun51sqx = new TF1 ("trialfun51sqx","[0]/sqrt(x-1) + pol1(1) + [3] * sqrt(10 * x)",2,50);
  trialfun51sqx->SetParameter(0,0.1);
  trialfun51sqx->SetParameter(1,0.05);
  trialfun51sqx->SetParameter(2,0.0);
  take_fun(trialfun51sqx);

  TF1* trialfun21sqx = new TF1 ("trialfun21sqx","pol1(0) + [2] * sqrt(10 * x)",0,50);
  take_fun(trialfun51sqx,trialfun21sqx,4);

  //sqrt(0.1x)
  
  TF1* trialfun51sqxs = new TF1 ("trialfun51sqxs","[0]/sqrt(x-1) + pol1(1) + [3] * sqrt(0.1 * x)",2,50);
  trialfun51sqxs->SetParameter(0,0.1);
  trialfun51sqxs->SetParameter(1,0.05);
  trialfun51sqxs->SetParameter(2,0.0);
  take_fun(trialfun51sqxs);

  TF1* trialfun21sqxs = new TF1 ("trialfun21sqxs","pol1(0) + [2] * sqrt(0.1 * x)",0,50);
  take_fun(trialfun51sqxs,trialfun21sqxs,4);

  //log(x)
  
  TF1* trialfun51ln = new TF1 ("trialfun51ln","[0]/sqrt(x-1) + pol1(1) + [3] * log(x)",2,50);
  trialfun51ln->SetParameter(0,0.1);
  trialfun51ln->SetParameter(1,0.05);
  trialfun51ln->SetParameter(2,0.0);
  take_fun(trialfun51ln);

  TF1* trialfun21ln = new TF1 ("trialfun21ln","pol1(0) + [2] * log(x)",0,50);
  take_fun(trialfun51ln,trialfun21ln,4);

  //log(10x)
  
  TF1* trialfun5lnx = new TF1 ("trialfun5lnx","[0]/sqrt(x-1) + pol0(1) + [2] * log(10 * x)",2,50);
  trialfun5lnx->SetParameter(0,0.1);
  trialfun5lnx->SetParameter(1,0.05);
  trialfun5lnx->SetParameter(2,0.0);
  take_fun(trialfun5lnx);

  TF1* trialfun2lnx = new TF1 ("trialfun2lnx","pol0(0) + [1] * log(x)",0,50);
  take_fun(trialfun5lnx,trialfun2lnx,3);
  
  //log(0.1x)
 
  TF1* trialfun5lnxs = new TF1 ("trialfun5lnxs","[0]/sqrt(x-1) + pol0(1) + [2] * log(0.1 * x)",2,50);
  trialfun5lnxs->SetParameter(0,0.1);
  trialfun5lnxs->SetParameter(1,0.05);
  trialfun5lnxs->SetParameter(2,0.0);
  take_fun(trialfun5lnxs);

  TF1* trialfun2lnxs = new TF1 ("trialfun2lnxs","pol0(0) + [1] * log(0.1 * x)",0,50);
  take_fun(trialfun5lnxs,trialfun2lnxs,3);
   
}

void take_fun(TF1* fun7)
{
  take_fun(fun7,NULL,0);
}

void take_fun(TF1* fun7, TF1* fun2, int numpars)
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
      //cout << x[i] << " " << y[i] << " " << ey[i] << endl;
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
      //cout << x4[i] << " " << y4[i] << " " << ey4[i] << endl;
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

  TLegend* leg = new TLegend(0.68,0.72,0.88,0.92); // the numbers are the coordinates x1,y1,x2,y2
  leg->AddEntry(tge_v22,"v_{2}{2}","p"); //"p" for point
  leg->AddEntry(tge_v24,"v_{2}{4}","p"); //"p" for point
  leg->Draw();

  // c1->Print("Figures/dAu200_combfits.png");

  tge_v22->Draw("ap");
  tge_v24->Draw("p");
  leg->Draw();

  fun7->SetLineColor(kBlack);
  fun7->SetLineWidth(2);
  tge_v22->Fit(fun7,"","",2,50);

  c1->Print(Form("Figures/dAu200_sepfits_%s.png",fun7->GetName()));

  if ( fun2 != NULL )
    {
      // --- need to figure out how to set the fun2 parameters here
      double* pars = fun7->GetParameters();
      //double pars[] = fun7->GetParameters();
      //int numpars = sizeof(pars)/sizeof(pars[0]);
      //int other = *(&pars + 1) - pars;
      //cout << pars << " " << pars[0] << " " << numpars << " " << other << endl;
      for ( int i = 0; i < numpars-1; ++i )
        {
          cout << "Setting fun2 parameter " << i << " to " << pars[i+1] << endl;
          fun2->SetParameter(i,pars[i+1]);
        }
      fun2->Draw("same");
      c1->Print(Form("Figures/dAu200_sepfits2_%s.png",fun7->GetName()));
    }

  double residual[nbins];
  double subtracted[nbins];
  for ( int i = 0; i < nbins; ++i )
    {
      ey[i] /= y[i];
      residual[i] = (fun7->Eval(x[i]) - y[i])/y[i];
      //subtracted[i] = y[i] - (fun7->Eval(x[i]) - fun7->GetParameter(0));
      subtracted[i] = y[i] - (fun7->GetParameter(0)/sqrt(x[i]-1));
      ey[i] *= subtracted[i];
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

  c1->Print(Form("Figures/dAu200_residual_%s.png",fun7->GetName()));

  TGraphErrors* tge_subtracted = new TGraphErrors(nbins,x,subtracted,0,ey);
  tge_subtracted->SetMarkerStyle(kFullSquare);
  tge_subtracted->SetMarkerColor(kRed);
  tge_subtracted->SetLineColor(kBlack);
  tge_subtracted->GetXaxis()->SetTitle("N_{tracks}^{FVTX}"); // x-axis
  tge_subtracted->GetYaxis()->SetTitle("v_{2}"); // y-axis
  tge_subtracted->Draw("ap");
  tge_subtracted->GetXaxis()->SetLimits(0.0,50.0); // x-axis range
  tge_subtracted->SetMinimum(0); // lowest y-axis value
  tge_subtracted->SetMaximum(0.13); // max y-axis value

  leg = new TLegend(0.68,0.72,0.88,0.92); // the numbers are the coordinates x1,y1,x2,y2
  leg->AddEntry(tge_v22,"v_{2}{2}_{subtracted}","p"); //"p" for point
  leg->AddEntry(tge_v24,"v_{2}{4}","p"); //"p" for point
  leg->Draw();
  
  tge_v24->Draw("p");
  c1->Print(Form("Figures/dAu200_subtracted_%s.png",fun7->GetName()));

  if ( fun2 != NULL )
    {
      // --- need to figure out how to set the fun2 parameters here
      fun2->Draw("same");
      c1->Print(Form("Figures/dAu200_subtracted2_%s.png",fun7->GetName()));
    }

  delete c1;

}
