#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::ostream_iterator;

int main()
{
    vector<int> vec;
    int input;
    ostream_iterator<int> output(cout, " ");

    while(cin >> input)
        vec.push_back(input);

    fill_n(vec.begin(), vec.size(), 0);

    copy(vec.begin(), vec.end(), output);

    return 0;
}
