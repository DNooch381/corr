void plotfit(TH1D*,TF1*,const char*);

void rng_cumulant()
{
  // TF1* fun2 = new TF1("fun2","[0]/(x-1)",1.9, 500);
  TF1* fun4 = new TF1("fun4","[0]/((x-1)*(x-2)*(x-3))",3.9, 500);
  TF1* fun6 = new TF1("fun6","[0]/((x-1)*(x-2)*(x-3)*(x-4)*(x-5))",3.9, 500);
  TF1* fun8 = new TF1("fun8","[0]/((x-1)*(x-2)*(x-3)*(x-4)*(x-5)*(x-6)*(x-7))",3.9, 500);
  TFile* HistFile2 = new TFile("OutputFiles/OutFile_k2.root","read");
  TProfile* histogram2 = (TProfile*)HistFile2->Get("hmult_recursion_0_0");
  // char handle2[20] = "2";

  TFile* HistFile4 = new TFile("OutputFiles/OutFile_k4.root","read");
  TProfile* histogram4 = (TProfile*)HistFile4->Get("hmult_recursion_0_2");
  char handle4[40] = "4";

  TFile* HistFile6 = new TFile("OutputFiles/OutFile_k6.root","read");
  TProfile* histogram6 = (TProfile*)HistFile6->Get("hmult_recursion_0_4");
  char handle6[60] = "6";

  TFile* HistFile8 = new TFile("OutputFiles/OutFile_k8.root","read");
  TProfile* histogram8 = (TProfile*)HistFile8->Get("hmult_recursion_0_6");
  char handle8[80] = "8";

  TH1D* cumulant4 = histogram4 -> ProjectionX("cumulant4");
  TH1D* cumulant2 = histogram2 -> ProjectionX("cumulant2");
  cumulant2 -> Multiply(cumulant2);
  cumulant2 -> Scale(2.0);
  cumulant4 -> Add(cumulant2,-1.0);
  plotfit(cumulant4,fun4,"_c4");

  TH1D* h_942 = histogram4 -> ProjectionX("h_942");
  TH1D* h_123 = histogram2 -> ProjectionX("h_123");
  TH1D* h_2 = histogram2 -> ProjectionX("h_2");
  h_942 -> Multiply(h_2);
  h_123 -> Multiply(h_2);
  h_123 -> Multiply(h_2);
  h_942 -> Scale(9.0);
  h_123 -> Scale(12.0);
  
  TH1D* cumulant6 = histogram6 -> ProjectionX("cumulant6");
  cumulant6 -> Add(h_942,-1.0);
  cumulant6 -> Add(h_123,1.0);
  plotfit(cumulant6,fun6,"_c6");

  TH1D* h_4 = histogram4 -> ProjectionX("h_4");
  TH1D* h_14 = histogram4 -> ProjectionX("h_14");
  TH1D* h_24 = histogram2 -> ProjectionX("h_24");
  TH1D* h_6 = histogram6 -> ProjectionX("h_6");
  h_6 -> Multiply(h_2);
  h_6 -> Scale(16.0);
  h_4 -> Multiply(h_4);
  h_4 -> Scale(18.0);
  h_14 -> Multiply(h_2);
  h_14 -> Multiply(h_2);
  h_14 -> Scale(144.0);
  h_24 -> Multiply(h_2);
  h_24 -> Multiply(h_2);
  h_24 -> Multiply(h_2);
  h_24 -> Scale(144.0);

  TH1D* cumulant8 = histogram8 -> ProjectionX("cumulant8");
  cumulant8 -> Add(h_6,-1.0);
  cumulant8 -> Add(h_4,-1.0);
  cumulant8 -> Add(h_14,1.0);
  cumulant8 -> Add(h_24,-1.0);
  plotfit(cumulant8,fun8,"_c8");
  
}

void plotfit(TH1D* histogram, TF1* fun, const char* handle)
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
