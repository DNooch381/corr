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
  vector < double > ang; //inserting the pairs into a single object                                                                                            

  //Below is our "for" loop                                                                                                                                    

  for ( int i = 0; i < npairs; ++i ) // int = integer, i is the variable that can always be at 0, i < 100 means go up to 100 events, ++i checks if it's less t\
han 100 and adds 1 -- if more than 100, than the program stops                                                                                                 
    {
      double phi1 = angle.Uniform(-3.1415926535,3.1415926535); //double means an exact number, phi1 is the name of the double for particle 1.                  
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
    }
  cout <<endl;
  return 0.0;
}
