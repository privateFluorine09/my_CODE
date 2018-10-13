#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<initializer_list>
#include<algorithm>
#include<iterator>

//

using namespace std;

class base
{
   int num1=2;
   int num2=2;
   int num3=4;
};

class derived1: public base
{
   int num4=2;

public:

   inline result()
   {
      return num1;
   }
};

class derived2: private base
{
   int num4=2;
};

int main()
{
   cout << sizeof(int) << " ";

   cout << sizeof(base) << " " << sizeof(derived1) << " " << sizeof(derived2) << endl;

   return 0;
}
