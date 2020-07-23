int get_lcm(int,int);

void plotfit(TH1D*,TF1*,const char*,const char*);

void clean_histo(TH1D*,int);

void AuAu_collis()
{
  TF1* fun2 = new TF1("fun2","[0]/pow(x,[1])",1.0, 500);
  fun2->SetParameter(0,1.0);
  fun2->SetParameter(1,1.0);

  TF1* fun4 = new TF1("fun4","[0]/pow(x,[1])",1.0, 500);
  fun4->SetParameter(0,6.0);
  fun4->SetParameter(1,3.0);

  // --- "Get" Files
  
  TFile* HistFile_AuAu1 = new TFile("OutputFiles/RootFiles/histos_12432.root","read");
  TFile* HistFile_AuAu2 = new TFile("OutputFiles/RootFiles/histos_13799.root","read");

  // --- "Get" Histograms from Each File
  
  TProfile* histogramAu_AuAu1 = (TProfile*)HistFile_AuAu1->Get("nfvtxt_recursion_0_0");
  TProfile* histogramAu_AuAu2 = (TProfile*)HistFile_AuAu2->Get("nfvtxt_recursion_0_0");

  // --- AuAu Cumulants Code Block

  TH1D* AuAu2 = histogramAu_AuAu2 -> ProjectionX("AuAu2");
  TH1D* AuAu1 = histogramAu_AuAu1 -> ProjectionX("AuAu1");
  
  plotfit(AuAu1,fun2,"_AuAu1","{AuAu1}");
  AuAu1 -> Multiply(AuAu1);
  AuAu1 -> Scale(2.0);
  AuAu2 -> Add(AuAu1,-1.0);
  clean_histo(AuAu2,4);
  
  plotfit(AuAu2,fun4,"_AuAu2","{AuAu2}");

  //return;

  TProfile* histogram_AuAu1 = histogramAu_AuAu1;
  TProfile* histogram_AuAu2 = histogramAu_AuAu2;

  TH1D* h_942 = histogram_AuAu2 -> ProjectionX("h_942");
  TH1D* h_123 = histogram_AuAu1 -> ProjectionX("h_123");
  TH1D* h_2 = histogram_AuAu1 -> ProjectionX("h_2");
  h_942 -> Multiply(h_2);
  h_123 -> Multiply(h_2);
  h_123 -> Multiply(h_2);
  h_942 -> Scale(9.0);
  h_123 -> Scale(12.0);
}

void plotfit(TH1D* histogram, TF1* fun, const char* handle, const char* yaxistitle)
{

  //Axis, Plots, Scaling, and Formatting Code
  
  TCanvas* c1 = new TCanvas("c1","",800,600);

  histogram->GetYaxis()->SetTitle(yaxistitle);
  histogram->GetXaxis()->SetTitle("Number of particles");
  histogram->GetXaxis()->SetRangeUser(0,50);
  histogram->SetMarkerStyle(kFullCircle);
  histogram->SetMarkerColor(kBlack);
  histogram->SetLineColor(kBlack);
  histogram->Draw();
  
  // --- LaTex Code Blocks
  
  TLatex* tex = new TLatex();
  tex->SetNDC();
  TLatex* tex2 = new TLatex();
  tex2->SetNDC();
  TLatex* tex3 = new TLatex();
  tex3->SetNDC();
  double xtex = 0.2;
  double ytex = 0.8;

  histogram->GetXaxis()->SetRangeUser(0,500);
  histogram->Draw();

  c1->SetLogy(1);
  histogram->Draw();

  c1->SetLogx(1);
  histogram->Draw();

  // --- Redraw Above Histogram w/ Best Fit
  
  histogram->Fit(fun,"","",100,500);
  
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
  fun->Draw("same");

  c1->Print(Form("Figures/histogram%s_fit_500logylogx.png",handle));
  c1->Print(Form("Figures/histogram%s_fit_500logylogx.pdf",handle));

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
  fun->Draw("same");

  c1->Print(Form("Figures/histogram%s_fit_500logy.png",handle));
  c1->Print(Form("Figures/histogram%s_fit_500logy.pdf",handle));

  histogram->GetXaxis()->SetRangeUser(0,100);

  // histogram->SetMinimum(0.0);
  // histogram->SetMaximum(1.0);

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
  fun->Draw("same");

  c1->Print(Form("Figures/histogram%s_fit_100logy.png",handle));
  c1->Print(Form("Figures/histogram%s_fit_100logy.pdf",handle));

  delete c1;
}

void clean_histo(TH1D* h, int n)
{
  for ( int i = 0; i < h->GetNbinsX(); ++i )
    {
      int bin = i+1;
      int lcm = get_lcm(n,2);
      if ( i%lcm != 0 )
        {
          h->SetBinContent(bin,-9999.9);
          h->SetBinError(bin,9999.9);
        }
    }
}

int get_lcm(int num1, int num2)
{
  int maxValue = (num1 > num2) ? num1 : num2;
  while ( ((maxValue % num1 == 0) && (maxValue % num2 == 0)) == false ) ++maxValue;
  return maxValue;
}
