void rnghist2()
{

  TFile* HistFile = new TFile("FileTwo.root","read");
  TProfile* histogram = (TProfile*)HistFile->Get("hmult_recursion_0_0");
  TCanvas* c1 = new TCanvas("c1","",800,600);
  TF1* fun = new TF1("fun","[0]/(x-1)",1.9, 500);

  histogram->Fit(fun,"R");
  c1->Print("histogram_fit_500logylogx.png");

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

} //end of rnghist2

