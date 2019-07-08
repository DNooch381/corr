void rnghist44()
{

  TFile* HistFile = new TFile("FileFour.root","read");
  TProfile* histogram = (TProfile*)HistFile->Get("hmult_recursion_0_2");

  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle("c_{2}{4}");
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print("Figures/histogram44_20.png");

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();
  c1->Print("Figures/histogram44_500.png");

  c1->SetLogy(1);
  histogram->Draw();
  c1->Print("Figures/histogram44_500logy.png");

  c1->SetLogx(1);
  histogram->Draw();
  c1->Print("Figures/histogram44_500logylogx.png");

  // --- correct combinatoric function
  //TF1* fun = new TF1("fun","[0]/((x-1)*(x-2)*(x-3))",3.9, 500);
  TF1* fun = new TF1("fun","[0]/pow(x-1,[1])",3.9, 500);

  // --- redraw the same histograms above but with the fit

  histogram->Fit(fun,"R");
  c1->Print("Figures/histogram44_fit_500logylogx.png");

  c1->SetLogx(0);
  histogram->Draw();
  c1->Print("Figures/histogram44_fit_500logy.png");

  c1->SetLogy(0);
  histogram->Draw();
  c1->Print("Figures/histogram44_fit_500.png");

  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print("Figures/histogram44_fit_20.png");

} //end of rnghist2
