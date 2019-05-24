double get_corr4 (int);
void RanGen4()

{
  double x = get_corr4 (9);
  cout <<endl;
  double y = get_corr4 (9);
}

double get_corr4 (int npairs)
{
  TRandom3 angle (0);
  vector <double> ang;

  for (int i = 0; i < npairs; ++i)
    {
      double phi1 = angle.Uniform(-3.1415926535,3.1415926535);
      double phi2 = 0;
      double phi3 = angle.Uniform(-3.1415926535,3.1415926535);
      double phi4 = 0;

      if ( phi1 > 0 ) phi2 = phi1 - 3.1415926535;
      if ( phi1 < 0 ) phi2 = phi1 + 3.1415926535;
      if ( phi3 > 0 ) phi4 = phi1 - 3.1415926535;
      if ( phi3 < 0 ) phi4 = phi1 + 3.1415926535;

      cout << phi1 << " " << phi2 << endl;
      cout << phi3 << " " << phi4 << endl;
      cout << i << " " << endl;

      ang.push_back (phi1);
      ang.push_back (phi2);
      cout << " " << endl;

      ang.push_back (phi1);
      ang.push_back (phi2);
      cout << " " << endl;
    }

  for (int i = 0; i < ang.size (); ++i)
    {
      cout << ang[i] << " " ;
    }

  cout << endl;
  return 0.0;
}
