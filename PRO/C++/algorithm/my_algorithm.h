#ifndef MY_ALGORITHM_H_INCLUDED
#define MY_ALGORITHM_H_INCLUDED
#include"print.h"

template<typename T>
void alg_insert_sort(T &obj)
{
    int i;
    auto itr=obj.begin()+1;
    while(itr!=obj.end())
    {
        i=(itr-obj.begin())-1;
        auto key=*itr;

        while( *(obj.begin()+i)>key && i>=0)
        {
            *(obj.begin()+i+1)=*(obj.begin()+i);
            i--;
        }

        *(obj.begin()+i+1)=key;
        itr++;
    }
}

//

//
template<typename T>
void alg_insert_sort(T &obj, unsigned p, unsigned q)
{
    if(q>p)
    {
        insert_sort(obj, p, q-1);
        unsigned key=obj.at(q);
        unsigned i;

        for(i=q-1; i>=0 && obj.at(i)>key; i--)
        obj.at(i+1)=obj.at(i);

        obj.at(i+1)=key;
    }
}

template<typename T>
void alg_merge(T &obj, int bp, int m, int ep)//bp:begin postion ep:end postion
{
     T arr1, arr2;
     int i=bp, j;
     int lth1=m-bp+1, lth2=ep-m; //lth:length of array

     while(i!=m+1)
     arr1.push_back(obj.at(i++));

     while(i!=ep+1)
     arr2.push_back(obj.at(i++));

     int cur=bp;
     i=0, j=0;

     while(i!=lth1 && j!=lth2 )
     {
         if(arr1.at(i)<arr2.at(j))
            obj.at(cur)=arr1.at(i), i++;
         else
            obj.at(cur)=arr2.at(j), j++;
         cur++;
     }

     while(i!=lth1)
     obj.at(cur)=arr1.at(i), i++, cur++;

     while(j!=lth2)
     obj.at(cur)=arr2.at(j), j++, cur++;

}

template<typename T>
void alg_merge_sort(T &obj, int p, int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        alg_merge_sort(obj, p, q);
        alg_merge_sort(obj, q+1, r);
        alg_merge(obj, p, q, r);
    }

}

template<typename T>
void alg_bubble_sort(T &obj)
{

    auto itr1=obj.begin();
    for(; itr1!=obj.end(); itr1++)
    {
        auto itr2=obj.end()-1;
        for(;itr2!=itr1; itr2--)
        {
            if(*(itr2)< *(itr2-1) )
            {
                auto key= *(itr2);
                *(itr2)=*(itr2-1);
                *(itr2-1)=key;
            }
        }
    }
}

template<typename T>
void alg_insert_rsort(T &obj)//rsort reverse sort
{
    int i;
    auto itr=obj.begin()+1;
    while(itr!=obj.end())
    {
        i=(itr-obj.begin())-1;
        auto key=*itr;

        while( *(obj.begin()+i)<key && i>=0)
        {
            *(obj.begin()+i+1)=*(obj.begin()+i);
            i--;
        }

        *(obj.begin()+i+1)=key;
        itr++;
    }
}

template<typename T, typename value_T>
unsigned alg_linear_search(T &obj, value_T key)
{
    auto itr=obj.begin();

    while(itr!=obj.end() && *(itr++)!=key)
    continue;

    return itr-obj.begin(); //its location
}

template<typename T, typename value_T>
unsigned alg_binary_search(T &obj, unsigned lower,
                           unsigned upper, value_T key)
{
    unsigned mid, p, q;
    p=lower;
    q=upper;
    mid=(p+q)/2;

    while(p<=q)
    {
        if(key > obj.at(mid))
        {
            p=mid;
            mid=(p+q)/2;
        }
        else
        {
            q=mid;
            mid=(p+q)/2;
        }
    }

    if(obj.at(mid) != key)
        return upper;
    else
        return mid;
}

#endif // MY_ALGORITHM_H_INCLUDED
