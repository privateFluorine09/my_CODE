#include<iostream>
#include<map>
#include<utility>
#include<cctype>

using namespace std;

int main()
{
    string input,input_lower;
    map<string, int> word_count;

    while(cin >> input)
    {
        for(char &c : input)
        if( isalpha(c) )
        input_lower.push_back(c);

        for(char &c : input_lower)
        tolower(c);

        ++word_count[input_lower];

        input_lower=string("");
    }


    for(const pair<string, int> &pr : word_count)
    cout << pr.first << " " << pr.second <<endl;

    return 0;
}
