#include<iostream>
#include<vector>
#include<utility>

#include"ADT.h"

using namespace std;

int main()
{
    //auto f=[](ADT_binary_tree_node<pair<int, int>> *ptr)->void{ cout << (ptr->elm).first << " "; };

    ADT_BS_tree<int, int> dic;

    int input=12;

    while(input<102)
    {
       dic.insert(make_pair(input, input));
       input+=7;
    }

    //the_tree.level_order(f);

    return 0;
}



