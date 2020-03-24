void drawpc_2();
void drawpc_4();
void drawpc_6();
void drawpc_8();

void rng_binary()
{
  drawpc_2();
  drawpc_4();
  drawpc_6();
  drawpc_8();
}

void drawpc_2()
{

  TFile* f2 = TFile::Open("OutputFiles/OutFile_BinaryC_20191011-1551_k2.root");
  TProfile* tp1f_2 = (TProfile*)f2->Get("hmult_recursion_0_0");

  TCanvas* c1 = new TCanvas("c1","");

  tp1f_2->SetMarkerStyle(kFullCircle);
  tp1f_2->SetMarkerColor(kBlack);
  tp1f_2->Draw("ex0p");
  tp1f_2->GetXaxis()->SetRangeUser(0,100);
  tp1f_2->GetXaxis()->SetTitle("Number");
  tp1f_2->GetYaxis()->SetTitle("C_{2}");

  c1->SetLogy();
  c1->SetLogx();
  //c1->Print("Figures/pure_comb_2.png");

  TF1* fun1 = new TF1("fun1","[0]/pow(x,1)",1.0,99.9);
  fun1->SetParameter(0,1); // asymptotic behavior from combinatorics (0!)
  TF1* fun2 = new TF1("fun2","[0]/((x-1))",1.0,99.9);
  fun2->SetParameter(0,1); // combinatorics suggests 0!
  fun2->SetLineColor(kBlue);

  fun1->Draw("same");
  fun2->Draw("same");

  c1->Print("Figures/pure_comb_2_fits_100logxlogy.png");
  c1->SetLogx(0);
  c1->Print("Figures/pure_comb_2_fits_100logy.png");

}
void drawpc_4()
{

  TFile* f4 = TFile::Open("OutputFiles/OutFile_BinaryC_20191011-1551_k4.root");
  TProfile* tp1f_4 = (TProfile*)f4->Get("hmult_recursion_0_2");

  TCanvas* c1 = new TCanvas("c1","");

  tp1f_4->SetMarkerStyle(kFullCircle);
  tp1f_4->SetMarkerColor(kBlack);
  tp1f_4->Draw("ex0p");
  tp1f_4->GetXaxis()->SetRangeUser(0,100);
  tp1f_4->GetXaxis()->SetTitle("Number");
  tp1f_4->GetYaxis()->SetTitle("C_{4}");

  c1->SetLogy();
  c1->SetLogx();
  //c1->Print("Figures/pure_comb_4.png");

  TF1* fun1 = new TF1("fun1","[0]/pow(x,3)",3.0,99.9);
  fun1->SetParameter(0,6); // asymptotic behavior from combinatorics (7!)
  //fun1->SetParameter(0,7000); // that makes it work a little better
  TF1* fun2 = new TF1("fun2","[0]/((x-1)*(x-2)*(x-3))",3.0,99.9);
  fun2->SetParameter(0,6); // combinatorics suggests 7!
  fun2->SetLineColor(kBlue);

  fun1->Draw("same");
  fun2->Draw("same");

  c1->Print("Figures/pure_comb_4_fits_100logxlogy.png");
  c1->SetLogx(0);
  c1->Print("Figures/pure_comb_4_fits_100logy.png");

}
void drawpc_6()
{

  TFile* f6 = TFile::Open("OutputFiles/OutFile_BinaryC_20191011-1551_k6.root");
  TProfile* tp1f_6 = (TProfile*)f6->Get("hmult_recursion_0_4");

  TCanvas* c1 = new TCanvas("c1","");

  tp1f_6->SetMarkerStyle(kFullCircle);
  tp1f_6->SetMarkerColor(kBlack);
  tp1f_6->Draw("ex0p");
  tp1f_6->GetXaxis()->SetRangeUser(0,100);
  tp1f_6->GetXaxis()->SetTitle("Number");
  tp1f_6->GetYaxis()->SetTitle("C_{6}");

  c1->SetLogy();
  c1->SetLogx();
  //c1->Print("Figures/pure_comb_6.png");

  TF1* fun1 = new TF1("fun1","[0]/pow(x,5)",5.0,99.9);
  fun1->SetParameter(0,120); // asymptotic behavior from combinatorics (7!)
  //fun1->SetParameter(0,7000); // that makes it work a little better
  TF1* fun2 = new TF1("fun2","[0]/((x-1)*(x-2)*(x-3)*(x-4)*(x-5))",5.0,99.9);
  fun2->SetParameter(0,120); // combinatorics suggests 7!
  fun2->SetLineColor(kBlue);

  fun1->Draw("same");
  fun2->Draw("same");

  c1->Print("Figures/pure_comb_6_fits_100logxlogy.png");
  c1->SetLogx(0);
  c1->Print("Figures/pure_comb_6_fits_100logy.png");

}
void drawpc_8()
{

  TFile* f8 = TFile::Open("OutputFiles/OutFile_BinaryC_20191011-1603_k8.root");
  TProfile* tp1f_8 = (TProfile*)f8->Get("hmult_recursion_0_6");

  TCanvas* c1 = new TCanvas("c1","");

  tp1f_8->SetMarkerStyle(kFullCircle);
  tp1f_8->SetMarkerColor(kBlack);
  tp1f_8->Draw("ex0p");
  tp1f_8->GetXaxis()->SetRangeUser(0,100);
  tp1f_8->GetXaxis()->SetTitle("Number");
  tp1f_8->GetYaxis()->SetTitle("C_{8}");

  c1->SetLogy();
  c1->SetLogx();
  //c1->Print("Figures/pure_comb_8.png");

  TF1* fun1 = new TF1("fun1","[0]/pow(x,7)",7.0,99.9);
  fun1->SetParameter(0,5040); // asymptotic behavior from combinatorics (7!)
  //fun1->SetParameter(0,7000); // that makes it work a little better
  TF1* fun2 = new TF1("fun2","[0]/((x-1)*(x-2)*(x-3)*(x-4)*(x-5)*(x-6)*(x-7))",7.0,99.9);
  fun2->SetParameter(0,5040); // combinatorics suggests 7!
  fun2->SetLineColor(kBlue);

  fun1->Draw("same");
  fun2->Draw("same");

  c1->Print("Figures/pure_comb_8_fits_100logxlogy.png");
  c1->SetLogx(0);
  c1->Print("Figures/pure_comb_8_fits_100logy.png");

}
