#include<iostream>
#include<iterator>
#include<vector>
#include<string>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ostream_iterator;

bool is_larger(const string &s)
{
    return s.size()>= 5;
}
int main()
{
    vector<string> vec;
    string input_line;
    ostream_iterator<string> output(cout, " ");

    while(getline(cin, input_line))
        if(!input_line.empty())
        vec.push_back(input_line);

    auto true_end = partition(vec.begin(), vec.end(), is_larger);

    copy(vec.begin(), true_end, output);

    return 0;
}
