#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str1("Good boy");
    auto result=find(str1.begin(), str1.end(), 'd');

    cout << &(*result) << endl;


    return 0;
}
