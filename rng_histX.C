void plotfit(TProfile*,TF1*,const char*,int);

void callX(int);
void callXR(int);
void callNEW(int);

void rng_histX()
{
  //int maximum = 100;
  //callX(maximum);
  callXR(100);
  callXR(500);
}

void callXR(int maximum)
{

  TFile* HistFile2 = new TFile("CondorOutput/Trial0007/SumFile_k2.root","read");
  TProfile* histogram2 = (TProfile*)HistFile2->Get("hmult_recursion_0_0");
  TF1* fun2 = new TF1("fun2","[0]/x",2, maximum);
  fun2->FixParameter(0,1.0);
  char handle2[20] = "2";
  plotfit(histogram2,fun2,handle2,maximum);

  TFile* HistFile4 = new TFile("CondorOutput/Trial0007/SumFile_k4.root","read");
  TProfile* histogram4 = (TProfile*)HistFile4->Get("hmult_recursion_0_2");
  char handle4[40] = "4";
  TF1* fun4 = new TF1("fun4","[0]/(pow(x,[1]))",4, maximum);
  fun4->FixParameter(0,17.0);
  fun4->FixParameter(1,2.0); // 1/N^2 (k/2 power)
  plotfit(histogram4,fun4,handle4,maximum);

  TFile* HistFile6 = new TFile("CondorOutput/Trial0007/SumFile_k6.root","read");
  TProfile* histogram6 = (TProfile*)HistFile6->Get("hmult_recursion_0_4");
  char handle6[60] = "6";
  TF1* fun6 = new TF1("fun6","[0]/(pow(x,[1]))",6, maximum);
  fun6->FixParameter(0,675.0);
  fun6->FixParameter(1,3.0); // 1/N^3 (k/2 power)
  plotfit(histogram6,fun6,handle6,maximum);

  TFile* HistFile8 = new TFile("CondorOutput/Trial0007/SumFile_k8.root","read");
  TProfile* histogram8 = (TProfile*)HistFile8->Get("hmult_recursion_0_6");
  char handle8[80] = "8";
  TF1* fun8 = new TF1("fun8","[0]/(pow(x,[1]))",8, maximum);
  fun8->FixParameter(0,40000.0);
  fun8->FixParameter(1,4.0); // 1/N^4 (k/2 power)
  plotfit(histogram8,fun8,handle8,maximum);

}

void callX(int maximum)
{

  TFile* HistFile2 = new TFile("CondorOutput/Trial0007/SumFile_k2.root","read");
  TProfile* histogram2 = (TProfile*)HistFile2->Get("hmult_recursion_0_0");
  TF1* fun2 = new TF1("fun2","[0]/(x-1)",1.9, maximum);
  char handle2[20] = "2";
  plotfit(histogram2,fun2,handle2,maximum);

  TFile* HistFile4 = new TFile("CondorOutput/Trial0007/SumFile_k4.root","read");
  TProfile* histogram4 = (TProfile*)HistFile4->Get("hmult_recursion_0_0");
  char handle4[40] = "4";
  plotfit(histogram4,fun2,handle4,maximum);

  TFile* HistFile6 = new TFile("CondorOutput/Trial0007/SumFile_k6.root","read");
  TProfile* histogram6 = (TProfile*)HistFile6->Get("hmult_recursion_0_0");
  char handle6[60] = "6";
  plotfit(histogram6,fun2,handle6,maximum);

  TFile* HistFile8 = new TFile("CondorOutput/Trial0007/SumFile_k8.root","read");
  TProfile* histogram8 = (TProfile*)HistFile8->Get("hmult_recursion_0_0");
  char handle8[80] = "8";
  plotfit(histogram8,fun2,handle8,maximum);

}

void plotfit(TProfile* histogram, TF1* fun, const char* handle, int maximum)
{

  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle(Form("#LT%s#GT",handle)); // hackish
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->SetMarkerStyle(kFullCircle);
  histogram->SetMarkerColor(kBlack);
  histogram->SetLineColor(kBlack);
  histogram->Draw();
  // --- insert LTatex code blocks here
  TLatex* tex = new TLatex();
  tex->SetNDC();
  double xtex = 0.2;
  double ytex = 0.8;

  histogram->GetXaxis()->SetRangeUser(0,maximum);
  histogram->Draw();
  c1->SetLogy(1);
  c1->SetLogx(1);

  // --- redraw the same histograms above but with the fit

  histogram->Fit(fun,"R");
  double par = fun->GetParameter(0);
  double epar = fun->GetParError(0);
  double chi2 = fun->GetChisquare();
  int ndf = fun->GetNDF();
  xtex = 0.57;
  ytex = 0.66;
  //tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  //tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_%dlogylogx.png",handle,maximum));

  c1->SetLogx(0);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  //tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  //tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_%dlogy.png",handle,maximum));

  c1->SetLogy(0);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  //tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  //tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));  c1->Print(Form("Figures/histogram%s_fit_maximum.png",handle));

  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  //tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  //tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  //c1->Print(Form("Figures/histogram%s_fit_20.png",handle));

  delete c1;

}
