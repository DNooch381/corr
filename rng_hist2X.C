void plotfit(TProfile*,TF1*,const char*);

void rng_hist2X()
{

  TFile* HistFile2 = new TFile("OutputFiles/OutFile2X_k2.root","read");
  TProfile* histogram2 = (TProfile*)HistFile2->Get("hmult_recursion_0_0");
  //TF1* fun2 = new TF1("fun2","[0]/(x-1)",1.9, 500);
  TF1* fun2 = new TF1("fun2","[0]/x",2, 500);
  fun2->FixParameter(0,1.0);
  char handle2[20] = "2X_2";
  plotfit(histogram2,fun2,handle2);

  TFile* HistFile4 = new TFile("OutputFiles/OutFile2X_k4.root","read");
  TProfile* histogram4 = (TProfile*)HistFile4->Get("hmult_recursion_0_2");
  char handle4[40] = "2X_4";
  // TF1* fun4 = new TF1("fun4","[0]/((x-1)*(x-2)*(x-3))",3.9, 500);
  TF1* fun4 = new TF1("fun4","[0]/(pow(x,[1]))",4, 500);
  fun4->FixParameter(0,17.0);
  fun4->FixParameter(1,2.0);
  plotfit(histogram4,fun4,handle4);

  //  return;

  TFile* HistFile6 = new TFile("OutputFiles/OutFile2X_k6.root","read");
  TProfile* histogram6 = (TProfile*)HistFile6->Get("hmult_recursion_0_4");
  char handle6[60] = "2X_6";
  TF1* fun6 = new TF1("fun6","[0]/(pow(x,[1]))",6, 500);
  fun6->FixParameter(0,675.0);
  fun6->FixParameter(1,3.0);
  plotfit(histogram6,fun6,handle6);

  //  return;

  TFile* HistFile8 = new TFile("OutputFiles/OutFile2X_k8.root","read");
  TProfile* histogram8 = (TProfile*)HistFile8->Get("hmult_recursion_0_6");
  char handle8[80] = "2X_8";
  TF1* fun8 = new TF1("fun8","[0]/(pow(x,[1]))",8, 500);
  fun8->FixParameter(0,43000.0);
  fun8->FixParameter(1,4.0);
  plotfit(histogram8,fun8,handle8);

}

void plotfit(TProfile* histogram, TF1* fun, const char* handle)
{

  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle("c_{2}{2}");
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
  //tex->DrawLatex(xtex,ytex,"20");
  c1->Print(Form("Figures/histogram%s_20.png",handle));

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();
  //tex->DrawLatex(xtex,ytex,"500");
  c1->Print(Form("Figures/histogram%s_500.png",handle));

  c1->SetLogy(1);
  histogram->Draw();
  //tex->DrawLatex(xtex,ytex,"500logy");
  c1->Print(Form("Figures/histogram%s_500logy.png",handle));

  c1->SetLogx(1);
  histogram->Draw();
  //tex->DrawLatex(xtex,ytex,"500logx/y");
  c1->Print(Form("Figures/histogram%s_500logylogx.png",handle));

  // --- redraw the same histograms above but with the fit

  histogram->Fit(fun,"R");
  double par = fun->GetParameter(0);
  double epar = fun->GetParError(0);
  double chi2 = fun->GetChisquare();
  int ndf = fun->GetNDF();
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_500logylogx.png",handle));

  c1->SetLogx(0);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_500logy.png",handle));

  c1->SetLogy(0);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));  c1->Print(Form("Figures/histogram%s_fit_500.png",handle));

  histogram->GetXaxis()->SetRangeUser(0,20);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.73;
  tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_20.png",handle));

  delete c1;

} //end of rnghist2
