#include<iostream>
#include<utility>
#include<map>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
    map<string, vector<string>> family;
    string input1, input2;
    ostream_iterator<string> output(cout, " ");
    // adding new families
    while(cin >> input1)
    {
        family[input1];

        while(cin >> input2)
        family[input1].push_back(input2);

    }
    for(const pair<string, vector<string>> &pr : family)
        cout << pr.first <<endl,
        copy(pr.second.begin(), pr.second.end(), output);


    return 0;
}
