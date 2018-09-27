#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    vector<int> seq, sq1, sq2, sq3, sq4;
    int input;
    ostream_iterator<int> output(cout, " ");

    while(cin >> input)
        seq.push_back(input);

    sq1=seq;
    sq2=seq;
    sq3=seq;
    sq4=seq;


    sq2.pop_back();
    sq3.erase(sq3.begin()+5);
    sq4.erase(sq4.begin(),sq4.begin()+5);


    copy(sq2.begin(), sq2.end(), output);
    cout << endl;
    copy(sq3.begin(), sq3.end(), output);
    cout << endl;
    copy(sq4.begin(), sq4.end(), output);
    cout << endl;

    return 0;
}
