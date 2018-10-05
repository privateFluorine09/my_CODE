#include<iostream>
#include<initializer_list>
#include<vector>
#include"ADT.h"


using namespace std;

int main()
{
    auto f=[](ADT_binary_tree_node<pair<int, int>> *ptr)->void{ cout << (ptr->elm).first << " "; };

    ADT_HBLT<int> the_tree(new ADT_binary_tree_node<pair<int, int>>(make_pair(9, 1)));

    int input;

    while(cin>>input)
    {
        the_tree.push(input);
        the_tree.level_order(f);
        cout << endl;
        cout << the_tree.size() <<endl;
    }

    return 0;
}
