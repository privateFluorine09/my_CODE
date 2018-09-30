#include<iostream>
#include<vector>
#include<utility>

#include"ADT.h"

using namespace std;

int main()
{

    ADT_max_heap<int> heap({98,12, 31, 31,44,12,45,78});


    cout << heap;
    //tree.level_order(print);

    return 0;
}



