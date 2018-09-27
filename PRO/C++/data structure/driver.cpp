#include<iostream>
#include<vector>
#include<utility>

#include"ADT.h"

using namespace std;



int main()
{

    vector<int> vec={0,1,2,3,4,5,6,7,8,9,11};
    vector<int> vec2={0,1,2,3,4,5,6,7,8,9,11};

    ADT_binary_tree<int> tree(vec);

    ADT_binary_tree<int> a_tree(vec2);

    tree.level_order(print);

    return 0;
}



