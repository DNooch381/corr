void rnghist2()
{

  TFile* HistFile = new TFile("FileTwo.root","read");
  TProfile* histogram = (TProfile*)HistFile->Get("hmult_recursion_0_0");
<<<<<<< HEAD
  TCanvas* c1 = new TCanvas("c1","",800,600);
  TF1* fun = new TF1("fun","[0]/(x-1)",1.9, 500); //includes combinatoric function for 2 particle correlations
=======
>>>>>>> 3c60bb78ecfe34db4b8ce978dd32872b2cf08cb6

  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle("c_{2}{2}");
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print("histogram_20.png");

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();
  c1->Print("histogram_500.png");

  c1->SetLogy();
  histogram->Draw();
  c1->Print("histogram_500logy.png");

  c1->SetLogx();
  histogram->Draw();
  c1->Print("histogram_500logylogx.png");

  // --- correct combinatoric function
  TF1* fun = new TF1("fun","[0]/(x-1)",1.9, 500);

  histogram->Fit(fun,"R");
  c1->Print("histogram_fit_500logylogx.png");

} //end of rnghist2

