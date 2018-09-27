#include<iostream>
#include<list>
#include<deque>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    list<int> lst;
    deque<int> odd,even;
    int input;

    ostream_iterator<int> output(cout," ");

    while(cin >> input)
        lst.push_back(input);

    list<int>::iterator itr=lst.begin();

    while(itr!=lst.end())
    {
        if((*itr)%2)
            odd.push_back(*itr);

        else
            even.push_back(*itr);

        itr++;
    }
    copy(odd.begin(), odd.end(), output);
    cout << endl;

    copy(even.begin(), even.end(), output);
    cout << endl;

    return 0;
}
