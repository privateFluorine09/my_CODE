#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include<iostream>
#include<utility>
#include<iterator>

using namespace std;

template<typename T>
void print(const T &obj)
{
    auto itr1=obj.begin();

    while(itr1!=obj.end())
    {
        cout << *itr1 <<" ";
        itr1++;
    }
}

template<typename Itr>
void print(Itr b, Itr e)
{
    Itr itr1=b;
    while(itr1!=e)
    {
        cout << *itr1 <<" ";
        itr1++;
    }

}

template<typename T1, typename T2>
void print(const pair<T1, T2> &obj)
{
    cout << obj.first <<" " << obj.second ;

}






#endif // PRINT_H_INCLUDED
