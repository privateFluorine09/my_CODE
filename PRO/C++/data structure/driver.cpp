#include<iostream>
#include<vector>
#include<utility>

#include"ADT.h"

using namespace std;

int main()
{
    //auto f=[](ADT_binary_tree_node<pair<int, int>> *ptr)->void{ cout << (ptr->elm).first << " "; };

    ADT_HBLT<int> the_tree({2,3,4,21,2,4,5,5,3,1,2,22,23,3,4,5});

    while(!the_tree.empty())
    {
       cout << the_tree.top() << " ";
       the_tree.pop();
    }

    //the_tree.level_order(f);

    return 0;
}



