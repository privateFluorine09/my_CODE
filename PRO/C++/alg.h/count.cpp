#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str("mam");
    auto result=count(str.begin(), str.end(), 'm');
    cout << result ;
    return 0;
}
