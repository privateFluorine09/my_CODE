#include<iostream>
#include<initializer_list>
#include<vector>
#include"ADT.h"


using namespace std;

int main()
{
    vector<int> vec= {3,2,5,4,33,55,123};

    auto itr=vec.begin();

    ADT_BS_tree<int, int> the_tree;

    while(itr!=vec.end())
    {
        pair<int, int> pr=make_pair(*itr, 1);
        the_tree.insert(pr);
        itr++;
    }

    auto visiter=[](ADT_binary_tree_node<pair<const int, int>> *ptr)
    {
        cout << ptr->elm.first << " ";
    };

    the_tree.level_order(visiter);

    cout << (the_tree.search(33)).second << endl;

    cout << (the_tree.max()).first;

    return 0;
}
