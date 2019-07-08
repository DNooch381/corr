void rnghist2()
{

  TFile* HistFile = new TFile("OutputFiles/OutFile_k2.root","read");
  TProfile* histogram = (TProfile*)HistFile->Get("hmult_recursion_0_0");

  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle("c_{2}{2}");
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print("Figures/histogram2_20.png");

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();
  c1->Print("Figures/histogram2_500.png");

  c1->SetLogy(1);
  histogram->Draw();
  c1->Print("Figures/histogram2_500logy.png");

  c1->SetLogx(1);
  histogram->Draw();
  c1->Print("Figures/histogram2_500logylogx.png");

  // --- correct combinatoric function
  TF1* fun = new TF1("fun","[0]/(x-1)",1.9, 500);

  // --- redraw the same histograms above but with the fit

  histogram->Fit(fun,"R");
  c1->Print("Figures/histogram2_fit_500logylogx.png");

  c1->SetLogx(0);
  histogram->Draw();
  c1->Print("Figures/histogram2_fit_500logy.png");

  c1->SetLogy(0);
  histogram->Draw();
  c1->Print("Figures/histogram2_fit_500.png");

  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print("Figures/histogram2_fit_20.png");

} //end of rnghist2
