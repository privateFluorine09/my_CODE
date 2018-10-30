#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<memory>

template<int x, size_t n>
struct power
{
    static constexpr int result=x*power<x, n-1>::result;
};

template<int x>
struct power<x, 0>
{
    static constexpr int result=1;
};

int main()
{
    constexpr int u=3;

    size_t i=0;

    while(i!=10000)
        std::cout <<power<u, 3>::result, i++;

    return 0;
}
