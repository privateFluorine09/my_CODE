#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<vector>
#include<string>
#include<cstdlib>

#include"print.h"

using namespace std;

int main()
{
    multimap<string, string> authors={{"A", "B"},{"A", "C"},{"A", "D"},{"E", "F"},{"E", "G"}};

    auto b_itr=authors.lower_bound("A");
    auto e_itr=authors.upper_bound("A");

    const pair<string, string> need_delete("A", "C");

    while(b_itr!=e_itr)
    {
        if((b_itr->second)==need_delete.second)
        authors.erase(b_itr);

        b_itr++;

    }

    for(const pair<string, string> &pr : authors)
    print(pr),
    cout <<endl;

    system("pause");

    return 0;
}
