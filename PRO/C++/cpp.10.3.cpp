#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<iterator>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::istream_iterator;
using std::ostream_iterator;

typedef vector<string>::iterator iter;

bool is_shorter(const string &s1, const string &s2 )
{
    return s1.size() < s2.size();
}
int main()
{
    vector<string> words;
    string line_input;
    ostream_iterator<string> output(cout, " ");

    while(getline(cin, line_input))
    if(!line_input.empty())
    words.push_back(line_input);

    sort(words.begin(), words.end());

    copy(words.begin(), words.end(), output);
    cout << endl;

    auto end_unq=unique(words.begin(), words.end());

    copy(words.begin(), words.end(), output);
    cout << endl;

    words.erase(end_unq, words.end());

    copy(words.begin(), words.end(), output);
    cout << endl;

    stable_sort(words.begin(), words.end(), is_shorter);

    copy(words.begin(), words.end(), output);
    cout << endl;

    return 0;
}
