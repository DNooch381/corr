void rnghist2()
{

  TFile* HistFile = new TFile("FileTwo.root","read");
  TProfile* histogram = (TProfile*)HistFile->Get("hmult_recursion_0_0");

  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle("c_{2}{2}");
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print("histogram_20_10.png");

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();
  c1->Print("histogram_500_10.png");

  c1->SetLogy(0);
  histogram->Draw();
  c1->Print("histogram_500logy_10.png");

  c1->SetLogx(0);
  histogram->Draw();
  c1->Print("histogram_500logylogx_10.png");

  // --- correct combinatoric function
  TF1* fun = new TF1("fun","[0]/(x-1)",1.9, 500);

  histogram->Fit(fun,"R");
  c1->Print("histogram_fit_500logylogx_10.png");

} //end of rnghist2
