#include<iostream>
#include"print.h"
#include<map>

using namespace std;

int main()
{
    multimap<string, string> family;
    pair<string, string> input;
    while(1)
    {
        if(!(cin >> input.first))
            break;

        if(!(cin >> input.second))
            break;

        family.insert(input);
    }

    for(const pair<string, string> &pr : family)
        print(pr),
        cout << endl;

    return 0;
}
