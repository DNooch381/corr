//references for nester for loops

void test()
{


  TCanvas* c1 = new TCanvas();
  TF1* fun = new TF1("fun","gaus",-1,1);
  fun->SetParameter(0,1.0);
  fun->SetParameter(1,0.0);
  fun->SetParameter(2,1.0);
  fun->Draw();

  TLatex* tex = new TLatex();
  tex->SetNDC();
  double xtex = 0.2;
  double ytex = 0.8;
  tex->DrawLatex(xtex,ytex,"this is text");
  xtex = 0.2;
  ytex = 0.9;
  tex->DrawLatex(xtex,ytex,"this is more text");

  // ---------------------------------------------------------------
  // now for the hard part
  double par = fun->GetParameter(0);
  double epar = fun->GetParError(0);
  double chi2 = fun->GetChisquare();
  int ndf = fun->GetNDF();
  xtex = 0.3;
  ytex = 0.4;
  tex->DrawLatex(xtex,ytex,Form("p_{0} = %.2f #pm %.2f",par,epar));
  xtex = 0.3;
  ytex = 0.3;
  tex->DrawLatex(xtex,ytex,Form("#chi^{2}/NDF = %.2f/%d",chi2,ndf));
  // ---------------------------------------------------------------

}
