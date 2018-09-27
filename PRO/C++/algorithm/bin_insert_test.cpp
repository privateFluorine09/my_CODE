#include<iostream>
#include<vector>
#include"print.h"

template<typename Itr>
void alg_insert_sort(Itr begin_itr, Itr end_itr);

using namespace std;

int main()
{
    vector<int> arr={9,8,7,6,5,4,3,2,1};
    alg_insert_sort(arr.begin(), arr.end());
    print(arr);
    return 0;
}

template<typename Itr>
void alg_insert_sort(Itr begin_itr, Itr end_itr)
{
    Itr current_itr=begin_itr+1;
    while(current_itr!=end_itr)
    {

        int i=current_itr-begin_itr, left, right, mid;
        auto key=*current_itr;

        for(left=0, right=i-1; left <= right ; mid=(left+right)/2)
        {
            if( *(begin_itr+mid) < key)
                left=mid;
            else
                right=mid;
        }

        int j=i-1;

        while(j!=left)
        *(begin_itr+j+1)=*(begin_itr+j);

        *(begin_itr+j+1)=key;

        current_itr++;
    }

}
