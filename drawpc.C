void drawpc()
{

  TFile* f8 = TFile::Open("OutputFiles/OutFile_BinaryC_20191011-1603_k8.root");
  TProfile* tp1f_8 = (TProfile*)f8->Get("hmult_recursion_0_6");

  TCanvas* c1 = new TCanvas("c1","");

  tp1f_8->SetMarkerStyle(kFullCircle);
  tp1f_8->SetMarkerColor(kBlack);
  tp1f_8->Draw("ex0p");
  tp1f_8->GetXaxis()->SetRangeUser(0,100);

  c1->SetLogy();
  //c1->SetLogx();
  c1->Print("Figures/pure_comb_8.png");

  TF1* fun1 = new TF1("fun1","[0]/pow(x,7)",7.0,99.9);
  fun1->SetParameter(0,5040); // asymptotic behavior from combinatorics (7!)
  fun1->SetParameter(0,7000); // that makes it work a little better
  TF1* fun2 = new TF1("fun2","[0]/((x-1)*(x-2)*(x-3)*(x-4)*(x-5)*(x-6)*(x-7))",7.0,99.9);
  fun2->SetParameter(0,5040); // combinatorics suggests 7!
  fun2->SetLineColor(kBlue);

  fun1->Draw("same");
  fun2->Draw("same");

  c1->Print("Figures/pure_comb_8_fits.png");

}
