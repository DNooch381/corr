void test()
{

  for ( int i = 1; i < 5; ++i )
    {
      cout << "I'm doing this one time for each i, i = " << i << endl;
    }

  cout << endl << endl;

  for ( int j = 0; j < 2; ++j )
    {
      for ( int i = 1; i < 5; ++i )
        {
          cout << "I'm doing this multiple times for each i, i = " << i << endl;
        }
    }

  cout << endl << endl;

  for ( int i = 1; i < 5; ++i )
    {
      for ( int j = 0; j < 2; ++j )
        {
          cout << "I'm doing this multiple times for each i, i = " << i << endl;
        }
    }

}
