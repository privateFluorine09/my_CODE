#include<iostream>
#include<sstream>
#include<string>

using namespace std;

//下面我们用一个简单的程序示例来演示怎么输出Hello World

template<typename T>
class Printer
{
public:

   ostringstream &operator() (ostringstream &os, T bi, T ei)const
   {
      T itr=bi;

      while(itr!=ei)
      {
         os << *itr;
      }

      return os;
   }
};

Printer<string::iterator> the_printer;

int main(int argc, char** argv)
{
   ostringstream output;

   string str1="Hello";

   the_printer(output, str1.begin(), str1.end());

   output << ",World";

   cout << output.str() <<endl;

   return 0;
}
