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

  static const int maxCorrelator = 12;
  static const int maxHarmonic = 10;
  static const int maxPower = 9;
  TComplex Qvector[maxHarmonic][maxPower];

  for(int h=0;h<maxHarmonic;h++)
    {
      for(int w=0;w<maxPower;w++)
        {
          Qvector[h][w] = TComplex(0.,0.); // initialize Q-vector to zero                                                
        } // end of loop over Qvector                                                                                    
    } // end of loop over maxHarmonic

  vector <double> ang;

  for (int i = 0; i < npairs; ++i)
    {
      double phi1 = angle.Uniform(-3.1415926535,3.1415926535);
      double phi2 = 0;
      double phi3 = 0;
      double phi4 = 0;
      // --- since phi3 is fixed to phi1, we don't need to call this
      // --- and it saves CPU time to skip it
      // double phi3 = angle.Uniform(-3.1415926535,3.1415926535);
      // double phi4 = 0;

      if ( phi1 > 0 ) phi2 = phi1 - 3.1415926535;
      if ( phi1 < 0 ) phi2 = phi1 + 3.1415926535;
      if ( phi1 > 0 ) phi3 = phi1 - 0.1;
      if ( phi1 < 0 ) phi3 = phi1 + 0.1;
      // --- we want phi4 to be anchored to phi3 and offset by pi
      if ( phi3 > 0 ) phi4 = phi3 - 3.1415926535;
      if ( phi3 < 0 ) phi4 = phi3 + 3.1415926535;

      cout << phi1 << " " << phi2 << endl;
      cout << phi3 << " " << phi4 << endl;
      cout << i << " " << endl;

      ang.push_back (phi1);
      ang.push_back (phi2);
      cout << " " << endl;

      ang.push_back (phi3);
      ang.push_back (phi4);
      cout << " " << endl;
    }

  for (int i = 0; i < ang.size (); ++i)
    {
      cout << ang[i] << " " ;
      for(int h=0;h<maxHarmonic;h++)
        {
          double phi = ang[i];
          // do the summation for the Q-vectors                                                                          
          for(int w=0;w<maxPower;w++)
            {
              Qvector[h][w] += TComplex(cos(h*phi),sin(h*phi));
            } // end of loop over powers                                                                                 
        } // end of loop over harmonics  
    }

  cout << endl;
  return 0.0;
}
