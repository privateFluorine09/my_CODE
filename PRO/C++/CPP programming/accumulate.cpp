#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<string.h>
using namespace std;
int main()
{
    char *str="GOODBOY";
    vector<int> arr(6,9);
    auto result1=accumulate(str, str+strlen(str), string(""));
    auto result2=accumulate(arr.begin(), arr.end(), 0);
    cout <<result1 <<endl
         <<result2 <<endl;
    return 0;
}
