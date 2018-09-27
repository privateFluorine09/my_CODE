#include<iostream>
#include<random>
#include<ctime>
#include<cstdlib>

using namespace std;

extern double average(uniform_int_distribution<int> ,
                      default_random_engine ,
                      const unsigned );

int main()
{
    uniform_int_distribution<int> d(1,6);
    default_random_engine e(time(0));

    unsigned num=0;

    cin >> num;

    double a=average(d, e, num);

    cout <<a <<endl;

    system("pause");


    return 0;
}
