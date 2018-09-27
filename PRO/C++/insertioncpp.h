#ifndef INSERTIONCPP_H_INCLUDED
#define INSERTIONCPP_H_INCLUDED
#include<iostream>

//completed

template<typename T>
T algcpp_insert(T &arr1, const T &arr2)
{
    T result=arr1;
    decltype(arr1.begin()) itr1;
    decltype(arr2.begin()) itr2;

    for(itr2=arr2.begin(); itr2!=arr2.end(); itr2++)
    {
        result.insert(result.begin(), *itr2);

        for(itr1=result.begin(); (itr1+1)!=result.end() && *itr1 > *(itr1+1); itr1++)
        {
            auto restore=*(itr1+1);
            *(itr1+1)=*itr1;
            *itr1=restore;
        }
    }
    return result;
}



#endif // INSERTIONCPP_H_INCLUDED
