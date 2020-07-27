void au_collis()
{

  // --- "Get" file(s)
  
  //TFile* f2 = TFile::Open("OutputFiles/RootFiles/histos_12432.root");
  TFile* f2 = TFile::Open("OutputFiles/RootFiles/histos_13799.root");

  // --- "Get" histogram(s) from file(s)
  
  TProfile* tp1f_2 = (TProfile*)f2->Get("nfvtxt_recursion_0_0");

  // --- Axis, Plots, Scaling, and Formatting Code  
  
  TCanvas* c1 = new TCanvas("c1","");

  tp1f_2->SetMarkerStyle(kFullCircle);
  tp1f_2->SetMarkerColor(kBlack);
  tp1f_2->Draw("ex0p");

  // Note: suggest to start with looking at low "SetRangeUser numbers

  tp1f_2->GetXaxis()->SetRangeUser(0,100);
  tp1f_2->GetXaxis()->SetTitle("Pending");
  tp1f_2->GetYaxis()->SetTitle("Pending");

  c1->SetLogy();
  c1->SetLogx();

  //c1->Print("Figures/au_collis.png");

  // --- Power low
  
  TF1* fun1 = new TF1("fun1","[0]/pow(x,[1])",1.0,99.9);
  fun1->SetParameter(0,1e-2); // asymptotic behavior from combinatorics (0!)
  fun1->SetParameter(1,1.0); // asymptotic behavior from combinatorics (0!)

  tp1f_2->Fit(fun1,"","",4,20);
  
  TF1* fun2 = new TF1("fun2","[0]/((x-1))",1.0,99.9);
  fun2->SetParameter(0,1e-2); // combinatorics suggests 0!
  fun2->SetLineColor(kBlue);

  fun1->Draw("same");
  fun2->Draw("same");

  // Legend

  TLegend* leg = new TLegend(0.2,0.2,0.46,0.4);
  leg->AddEntry(fun2,"combinatoric function","l");
  leg->AddEntry(fun1,"power law function","l");
  leg->Draw();

  c1->Print("Figures/au_collis_100logxlogy.png");
  c1->SetLogx(0);

  TLegend* leg2 = new TLegend(0.48,0.68,0.84,0.88);
  leg2->AddEntry(fun2,"combinatoric function","l");
  leg2->AddEntry(fun1,"power law function","l");
  leg2->Draw();

  delete leg;
  c1->Print("Figures/au_collis_100logy.png");

  delete c1;

}
