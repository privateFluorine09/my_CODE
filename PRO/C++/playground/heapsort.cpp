#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

//preparation:

class Heap_sort_pack
{
    ~Heap_sort_pack()=delete;

    template<typename Itr, typename F>
    friend void heap_sort(const Itr&, const Itr&, const F&);

    static inline size_t parent(const size_t &index)
    {
        return (index-1)/2;
    }

    static inline size_t left(const size_t &index)
    {
        return 2*index+1;
    }

    static inline size_t right(const size_t &index)
    {
        return 2*index+2;
    }

    template<typename T>
    static inline void swap(T &a, T &b)
    {
        T store=a;
        a=b;
        b=store;
    }

    template<typename Itr, typename F>
    static void max_heapify(const Itr &_begin, const Itr &_end, const size_t &index, const F &cmp)
    {
        size_t the_size=_end-_begin;

        if(index>=the_size)
        {
            return;
        }

        size_t largest=index;

        if(left(index)<the_size && cmp(*(_begin+left(index)),*(_begin+index)) )
            largest=left(index);

        if(right(index)<the_size && cmp(*(_begin+right(index)),*(_begin+largest)) )
            largest=right(index);

        if(largest!=index)
        {
            swap(*(_begin+largest), *(_begin+index));
            max_heapify(_begin, _end, largest, cmp);
        }
    }
};

//defination:
using pack=Heap_sort_pack;

template<typename Itr, typename F>
void heap_sort(const Itr &_begin, const Itr &_end, const F &cmp)
{
    size_t the_size=_end-_begin;

    for(size_t i=the_size/2-1; i!=0; i--)
    {
        pack::max_heapify(_begin, _end, i, cmp);
    }

    pack::max_heapify(_begin, _end, 0, cmp);

    auto itr=_end;
    --itr;

    while(itr!=_begin)
    {
        pack::swap(*(_begin), *itr);
        pack::max_heapify(_begin, itr, 0, cmp);
        itr--;
    }
}


int main()
{
    std::vector<int> vec= {7,4,2,2,3,5,6,24,4,3,3,2};

    auto fun=[](const int &a, const int &b)->bool
    {
        return a>b;
    };

    heap_sort(vec.begin(), vec.end(), fun);

    for(const auto &a: vec)
        std::cout << a << " ";

    return 0;
}
