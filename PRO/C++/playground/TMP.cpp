#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

template<unsigned n>
struct power
{
   enum
   {
      result=power<n-1>::result*2
   };
};

template<>
struct power<0>
{
   enum
   {
      result=1
   };
};

using namespace std;

int main()
{
   ios::sync_with_stdio(false);//faster output

   cout << power<4>::result << endl; //calculate 2^4

}
