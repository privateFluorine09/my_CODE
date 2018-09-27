#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
#include<iterator>
using std::vector;
using std::array;
using std::cout;
using std::ostream_iterator;

int main()
{
    vector<int> empty_vec;
    array<int,4> opt;
    ostream_iterator<int> output(cout, " ");

    opt.at(0)=empty_vec[0];
    opt.at(1)=empty_vec.at(0);
    opt.at(2)=*(empty_vec.begin());
    opt.at(3)=*(empty_vec.front());

    copy(opt.begin(), opt.end(), output);

    return 0;
}
