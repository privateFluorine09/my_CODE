#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::ostream_iterator;

int main()
{
    vector<char> vec;
    vector<int> cap,siz;
    ostream_iterator<int> output(cout, " ");

    char input;
    while(cin >> input)
    {
        vec.push_back(input);
        cap.push_back(vec.capacity());
        siz.push_back(vec.size());
    }

    copy(cap.begin(), cap.end(), output);
    cout << endl;
    copy(siz.begin(), siz.end(), output);
    cout << endl;

    vec.resize(10,'t');

    output=vec.capacity();
    output=vec.size();

    return 0;
}
