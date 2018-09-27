#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>

using std::cin;
using std::cout;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;
using std::endl;

int main()
{
    vector<double> vec;
    istream_iterator<double> itr(cin),itr_end;
    ostream_iterator<double> op_itr(cout," ");

    while(itr!=itr_end)
        vec.push_back(*itr++);



    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

    return 0;
}
