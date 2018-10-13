#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr1(6,6);
    vector<int> arr2=arr1;

    arr2.push_back(7);

    auto result= equal(arr1.begin(), arr1.end(), arr2.begin());

    cout << result ;


    return 0;
}
