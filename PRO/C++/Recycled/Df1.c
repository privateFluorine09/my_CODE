#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    vector<int> arr;
    ostream_iterator<int> output(cout, " ");
    int input;

    while(cin >> input)
    arr.insert(arr.end(), 5, input);

    copy(arr.begin(), arr.end(), output);
    return 0;
}
