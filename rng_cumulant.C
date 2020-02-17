void plotfit(TH1D*,TF1*,const char*);

void clean_histo(TH1D*,int);

void rng_cumulant()
{
  // TF1* fun2 = new TF1("fun2","[0]/(x-1)",1.9, 500); // no need
  //TF1* fun4 = new TF1("fun4","[0]/((x-1)*(x-2)*(x-3))",3.9, 500);
  TF1* fun4 = new TF1("fun4","[0]/pow(x,[1])",3.9, 500);
  fun4->SetParameter(0,6.0);
  fun4->SetParameter(1,3.0);
  // TF1* fun6 = new TF1("fun6","[0]/((x-1)*(x-2)*(x-3)*(x-4)*(x-5))",3.9, 500);
  // TF1* fun8 = new TF1("fun8","[0]/((x-1)*(x-2)*(x-3)*(x-4)*(x-5)*(x-6)*(x-7))",3.9, 500);
  TF1* fun6 = new TF1("fun6","[0]/pow(x,[1])",3.9, 500);
  fun6->SetParameter(0,120.0);
  fun6->SetParameter(1,5.0);
  TF1* fun8 = new TF1("fun8","[0]/pow(x,[1])",3.9, 500);
  fun8->SetParameter(0,5040.0);
  fun8->SetParameter(1,7.0);
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
  clean_histo(cumulant4,4);
  plotfit(cumulant4,fun4,"_c4");

  //return;

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
  clean_histo(cumulant6,6);
  cumulant6->Scale(1.0/4.0); // c6 = 4v^6
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
  clean_histo(cumulant8,8);
  cumulant8->Scale(1.0/33.0); // c8 = 33v^8
  fun8->SetParameter(0,10);
  fun8->SetParameter(1,3);
  plotfit(cumulant8,fun8,"_c8");

}

void plotfit(TH1D* histogram, TF1* fun, const char* handle)
{

  TCanvas* c1 = new TCanvas("c1","",800,600);

  //histogram->GetYaxis()->SetTitle("c_{2}{2}"); // need to be smarter about this
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,50);
  histogram->SetMarkerStyle(kFullCircle);
  histogram->SetMarkerColor(kBlack);
  histogram->SetLineColor(kBlack);
  histogram->Draw();
  // --- insert LTatex code blocks here
  TLatex* tex = new TLatex();
  tex->SetNDC();
  TLatex* tex2 = new TLatex();
  tex2->SetNDC();
  TLatex* tex3 = new TLatex();
  tex3->SetNDC();
  double xtex = 0.2;
  double ytex = 0.8;
  //tex->DrawLatex(xtex,ytex,"50");
  //c1->Print(Form("Figures/histogram%s_50.png",handle));

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();
  //tex->DrawLatex(xtex,ytex,"500");
  //c1->Print(Form("Figures/histogram%s_500.png",handle));

  c1->SetLogy(1);
  histogram->Draw();
  //tex->DrawLatex(xtex,ytex,"500logy");
  //c1->Print(Form("Figures/histogram%s_500logy.png",handle));

  c1->SetLogx(1);
  histogram->Draw();
  //tex->DrawLatex(xtex,ytex,"500logx/y");
  //c1->Print(Form("Figures/histogram%s_500logylogx.png",handle));

  // --- redraw the same histograms above but with the fit

  histogram->Fit(fun,"R");
  double par = fun->GetParameter(0);
  double epar = fun->GetParError(0);
  double par1 = fun->GetParameter(1);
  double epar1 = fun->GetParError(1);
  double chi2 = fun->GetChisquare();
  int ndf = fun->GetNDF();
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.60;
  tex3->DrawLatex(xtex,ytex,Form("p_{1} = %.2f #pm %.2f",par1,epar1));
  xtex = 0.57;
  ytex = 0.73;
  tex2->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_500logylogx.png",handle));

  c1->SetLogx(0);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.60;
  tex3->DrawLatex(xtex,ytex,Form("p_{1} = %.2f #pm %.2f",par1,epar1));
  xtex = 0.57;
  ytex = 0.73;
  tex2->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_500logy.png",handle));

  c1->SetLogy(0);
  histogram->Draw();
  histogram->SetMinimum(0.0);
  histogram->SetMaximum(1.0);
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.60;
  tex3->DrawLatex(xtex,ytex,Form("p_{1} = %.2f #pm %.2f",par1,epar1));
  xtex = 0.57;
  ytex = 0.73;
  tex2->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));

  histogram->GetXaxis()->SetRangeUser(0,50);
  histogram->SetMinimum(0.0);
  histogram->SetMaximum(1.0);
  histogram->Draw();
  xtex = 0.57;
  ytex = 0.66;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.57;
  ytex = 0.60;
  tex3->DrawLatex(xtex,ytex,Form("p_{1} = %.2f #pm %.2f",par1,epar1));
  xtex = 0.57;
  ytex = 0.73;
  tex2->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  c1->Print(Form("Figures/histogram%s_fit_50.png",handle));

  delete c1;

} //end of rnghist2

void clean_histo(TH1D* h, int n)
{
  for ( int i = 0; i < h->GetNbinsX(); ++i )
    {
      int bin = i+1;
      int lcm = 0;
      if ( n == 2 ) lcm = 2;
      if ( n == 4 ) lcm = 4;
      if ( n == 6 ) lcm = 12;
      if ( n == 8 ) lcm = 24;
      if ( i%lcm != 0 )
        {
          h->SetBinContent(bin,-9999.9);
          h->SetBinError(bin,9999.9);
        }
    }
}
