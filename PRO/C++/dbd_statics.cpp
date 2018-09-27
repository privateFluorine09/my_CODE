#include<iostream>
#include<cstdlib>
#include"match.h"

using namespace std;

int main()
{
    player new_player;
    match new_match;
    double s,e;

    while(cin >> e >> s )
    {
        new_match=match_write(e, s);
        new_player.add_match(new_match);
    }

    cout << new_player << endl;

    system("pause");

    return 0;
}
