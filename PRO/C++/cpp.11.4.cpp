#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include"print.h"

using namespace std;

int main()
{
    string input1;
    int input2;
    vector<pair<string, int>> vec;
    pair<string, int> input;

    while(1)
    {
        input={"", 0};

        if(!(cin >> input1))
            break;
        else
            input.first=input1;

        if(!(cin >> input2))
            break;
        else
            input.second=input2;

        vec.push_back(input);
    }

    vector<pair<string, int>>::iterator itr=vec.begin();

    while(itr!=vec.end())
    print(*itr),
    cout << endl,
    itr++;



    return 0;
}


