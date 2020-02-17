int get_lcm(int,int);

void calc_lcm()
{
  get_lcm(2,4);
  get_lcm(4,6);
  get_lcm(6,8);
}


int get_lcm(int num1, int num2)
{

  cout << "For " << num1 << " and " << num2 << ", ";

   int maxValue = (num1 > num2) ? num1 : num2;

   while(1)
   {
      //condition of LCM
      if((maxValue % num1 == 0) && (maxValue % num2 == 0))
      {
         cout << "the LCM is " << maxValue << endl;
         break;
      }
      ++maxValue;
   }
   return maxValue;

}

