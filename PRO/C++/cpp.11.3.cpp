#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iterator>

using namespace std;

int main()
{
    vector<string> word_count;

    string input;
    ostream_iterator<string> output(cout, " ");

    while(cin >> input)
    {
        if(find(word_count.begin(), word_count.end(), input)==word_count.end())
            word_count.push_back(input);

    }

    copy(word_count.begin(), word_count.end(), output);

    return 0;
}
