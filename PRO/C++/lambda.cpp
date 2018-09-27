#include<iostream>

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    auto f=[a](int b)->int { return a+b;};

    cout <<f(b);
    return 0;
}
