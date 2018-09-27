#include<iostream>
#include<functional>
using namespace std;
using namespace placeholders;

int fun_ction(int, int, int);

int main()
{
    auto dis_tance=bind(fun_ction, _1, _2, 5);
    cout << dis_tance(3, 4) << endl;
    return 0;
}

int fun_ction(int x, int y, int z)
{
    return (x*x+y*y+z*z);
}
