#include<iostream>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

int main()
{
    vector<string> words;
    string input;
    int num=3;

    while(getline(cin, input))
    words.push_back(input);



    auto fun_ction=[&num](string s)->bool {return s.size()>num;};

    int times=count_if(words.begin(), words.end(), fun_ction);

    cout << times;

    return 0;
}
