#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>



using namespace std;

int main()
{
   ifstream is("example.txt");

   string output;

   getline(is, output);

   cout << output;

   return 0;
}
