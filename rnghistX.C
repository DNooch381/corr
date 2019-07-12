void plotfit(TProfile*,TF1*,const char*);

void rnghistX()
{

  TFile* HistFile2 = new TFile("OutputFiles/OutFile_k2.root","read");
  TProfile* histogram2 = (TProfile*)HistFile2->Get("hmult_recursion_0_0");
  TF1* fun2 = new TF1("fun2","[0]/(x-1)",1.9, 500);
  char handle2[20] = "2";
  plotfit(histogram2,fun2,handle2);

  TFile* HistFile4 = new TFile("OutputFiles/OutFile_k4.root","read");
  TProfile* histogram4 = (TProfile*)HistFile4->Get("hmult_recursion_0_0");
  char handle4[40] = "4";
  plotfit(histogram4,fun2,handle4);

  // TProfile* histogram44 = (TProfile*)HistFile4->Get("hmult_recursion_0_2");
  // TF1* fun4 = new TF1("fun4","[0]/((x-1)*(x-2)*(x-3))",3.9, 500);
  // char handle44[40] = "44";
  // plotfit(histogram44,fun4,handle44);

  TFile* HistFile6 = new TFile("OutputFiles/OutFile_k6.root","read");
  TProfile* histogram6 = (TProfile*)HistFile6->Get("hmult_recursion_0_0");
  char handle6[60] = "6";
  plotfit(histogram6,fun2,handle6);

  TFile* HistFile8 = new TFile("OutputFiles/OutFile_k8.root","read");
  TProfile* histogram8 = (TProfile*)HistFile8->Get("hmult_recursion_0_0");
  char handle8[80] = "8";
  plotfit(histogram8,fun2,handle8);

}

void plotfit(TProfile* histogram, TF1* fun, const char* handle)
{

  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle("c_{2}{2}");
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print(Form("Figures/histogram%s_20.png",handle));

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();
  c1->Print(Form("Figures/histogram%s_500.png",handle));

  c1->SetLogy(1);
  histogram->Draw();
  c1->Print(Form("Figures/histogram%s_500logy.png",handle));

  c1->SetLogx(1);
  histogram->Draw();
  c1->Print(Form("Figures/histogram%s_500logylogx.png",handle));

  // --- redraw the same histograms above but with the fit

  histogram->Fit(fun,"R");
  c1->Print(Form("Figures/histogram%s_fit_500logylogx.png",handle));

  c1->SetLogx(0);
  histogram->Draw();
  c1->Print(Form("Figures/histogram%s_fit_500logy.png",handle));

  c1->SetLogy(0);
  histogram->Draw();
  c1->Print(Form("Figures/histogram%s_fit_500.png",handle));

  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  c1->Print(Form("Figures/histogram%s_fit_20.png",handle));

  delete c1;

} //end of rnghist2
