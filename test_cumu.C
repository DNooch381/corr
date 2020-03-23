void test_cumu()
{

  TCanvas* c1 = new TCanvas("c1","");

  //TFile* file = TFile::Open("CondorOutput/SumFile_k2.root"); // doesn't work, maybe it shouldn't
  TFile* file = TFile::Open("CondorOutput/SumFile_k4.root"); // hmm

  TProfile* tp1f_two = (TProfile*)file->Get("hmult_recursion_0_0");
  TProfile* tp1f_four = (TProfile*)file->Get("hmult_recursion_0_2");

  tp1f_four->SetMarkerStyle(kFullCircle);
  tp1f_two->SetMarkerStyle(kOpenCircle);

  tp1f_four->Draw();
  tp1f_four->GetXaxis()->SetRangeUser(0,100);
  tp1f_two->Draw("same");

  c1->SetLogy();
  c1->Print("TestFigs/test_fig_4and2.png"); // looks fine

  TH1D* th1d_two = tp1f_two->ProjectionX("th1d_two");
  TH1D* th1d_four = tp1f_four->ProjectionX("th1d_four");

  th1d_two->Multiply(th1d_two);
  th1d_two->Scale(2);

  th1d_four->SetMarkerStyle(kFullCircle);
  th1d_two->SetMarkerStyle(kOpenCircle);

  th1d_four->Draw();
  th1d_four->GetXaxis()->SetRangeUser(0,100);
  th1d_two->Draw("same");

  c1->SetLogy();
  c1->Print("TestFigs/test_fig_222and4.png"); // looks fine

  th1d_two->Add(th1d_four,-1.0);
  th1d_two->Scale(-1);

  th1d_two->Draw();
  c1->SetLogy();
  c1->Print("TestFigs/test_fig_c4.png"); // looks like garbage

  TH1D* hc4 = (TH1D*)th1d_four->Clone("hc4");

  for ( int i = 0; i < tp1f_two->GetNbinsX(); ++i )
    {
      if ( i%4 != 0 ) continue;
      double two = tp1f_two->GetBinContent(i+1);
      double four = tp1f_four->GetBinContent(i+1);
      double twotwotwo = 2*two*two;
      double cumu4 = four - twotwotwo;
      if ( i < 100 ) cout << i << " " << two << " " << twotwotwo << " " << four << " " << cumu4 << endl;
      hc4->SetBinContent(i+1,0.0);
      cumu4 = fabs(cumu4); // fluctuations about zero should be on the order of the correct size...
      if ( cumu4 > 0 && i > 2 ) hc4->SetBinContent(i+1,cumu4);
    }

  hc4->Draw();
  hc4->GetXaxis()->SetRangeUser(0,500);
  c1->SetLogy();
  c1->Print("TestFigs/test_fig_cleaned_c4.png");

  TF1* fun = new TF1("fun","[0]/pow(x,[1])",0,500);
  fun->FixParameter(0,0.5);
  fun->FixParameter(1,2.0);
  hc4->Fit(fun,"","",4,500);
  c1->SetLogy();
  c1->Print("TestFigs/test_fig_fitcleaned_c4.png");

}
