#include<iostream>
#include<vector>
#include<utility>

#include"ADT.h"

using namespace std;



int main()
{

    ADT_max_heap<int> heap({1,2,3,4,5,6,7,8,9});

    cout << heap;
    //tree.level_order(print);

    return 0;
}



