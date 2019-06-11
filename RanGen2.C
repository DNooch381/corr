double get_corr(int);



void RanGen2()
{
  double x = get_corr (9); //number of correlations for the phi1 we want to return
  cout <<endl;
  cout <<endl;
  double y = get_corr (9); //number of correlations for the phi2 we want to return
}

double get_corr(int npairs)
{
  TRandom3 angle(0);

  //Dylan TComplex based on shared code

  static const int maxCorrelator = 12;
  static const int maxHarmonic = 10;
  static const int maxPower = 9;
  TComplex Qvector[maxHarmonic][maxPower];

  // initialize the Q-vectors to zero
  for(int h=0;h<maxHarmonic;h++)
    {
      for(int w=0;w<maxPower;w++)
        {
          Qvector[h][w] = TComplex(0.,0.);
        }
    }

  // Receiving some error messages (see below), but think this may be a bracketing issue?
  // errors being found:
  //  In file included from input_line_10:1:
  //  /Users/home_dylanantonacci/Corr/RanGen2.C:36:36: error: use of undeclared identifier 'p'
  //   Qvector[h][w] += TComplex(cos(h*p.phi()),sin(h*p.phi()));
  // ^ ---- AH HA!
  //   /Users/home_dylanantonacci/Corr/RanGen2.C:36:51: error: use of undeclared identifier 'p'
  //  Qvector[h][w] += TComplex(cos(h*p.phi()),sin(h*p.phi()));

  //vector < double > ang; //inserting the pairs into a single object
  vector <double> ang; //inserting the pairs into a single object

  // Below is our "for" loop
  // int = integer, i is the variable that can always be at 0,
  // i < 100 means go up to 100 events, ++i checks if it's less
  // than 100 and adds 1 -- if more than 100, than the program stops
  for ( int i = 0; i < npairs; ++i )
    {
      //double means an exact number, phi1 is the name of the double for particle 1.
      double phi1 = angle.Uniform(-3.1415926535,3.1415926535);
      double phi2 = 0; //same as above, but for particle 2
      if ( phi1 > 0 ) phi2 = phi1 - 3.1415926535;
      if ( phi1 < 0 ) phi2 = phi1 + 3.1415926535;
      cout << phi1 << " " << phi2 << endl;
      cout << i << " " << endl;

      ang.push_back(phi1); //push_back means to stack numbers
      ang.push_back(phi2);

    }
  for ( int i = 0; i < ang.size(); ++i )
    {
      cout << ang[i] << " " ;
      for(int h=0;h<maxHarmonic;h++)
        {
          double phi = ang[i];
          // do the summation for the Q-vectors
          for(int w=0;w<maxPower;w++)
            {
              //Qvector[h][w] += TComplex(cos(h*p.phi()),sin(h*p.phi()));
              Qvector[h][w] += TComplex(cos(h*phi),sin(h*phi));
            } // end of loop over powers
        } // end of loop over harmonics
    } // end of loop over ang vector
  cout <<endl;
  return 0.0;
}
