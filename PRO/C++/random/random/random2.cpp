#include<iostream>
#include<random>
#include<ctime>

using namespace std;

extern double average(uniform_int_distribution<int> distribution,
                      default_random_engine engine ,
                      const unsigned n)
{
     double aver=0;
     double sum=0;
     unsigned count_num=0;

     while(count_num != n)
     {
         sum+=distribution(engine);
         count_num++;
     }

     aver=sum/count_num;

     return aver;

}
