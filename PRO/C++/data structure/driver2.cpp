#include<iostream>
#include<initializer_list>
#include<vector>
#include"ADT.h"


using namespace std;

int main()
{
    ADT_RB_tree<int> the_tree;

    auto func=[](ADT_RBtree_node<int> *ptr)->void
    {
        cout << ptr->elm << " ";
    };

    the_tree.pre_order(func);
    cout << endl;

    the_tree.in_order(func);
    cout << endl;

    the_tree.post_order(func);
    cout << endl;
ADT
    //maybe something else test

    return 0;
}
