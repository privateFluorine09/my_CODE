#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

template<typename T>
class UpHeap;

template<typename T>
std::ostream &operator<< (std::ostream&, const UpHeap<T>&);

template<typename T>
class UpHeap
{
    friend std::ostream &operator<< <T>(std::ostream&, const UpHeap&);

public:
    //static mathods:
    static inline size_t parent(const size_t &index)
    {
        return (index-1)/2;
    }

    static inline size_t left(const size_t &index)//left child
    {
        return 2*index+1;
    }

    static inline size_t right(const size_t &index)
    {
        return 2*index+2;
    }

public:
    UpHeap()=default;
    UpHeap(const UpHeap&);
    UpHeap(const std::initializer_list<T>&);
    ~UpHeap()=default;

    inline bool empty()const
    {
        return !static_cast<bool>(the_size);
    }

    inline size_t size()const
    {
        return the_size;
    }

    inline bool full()const
    {
        return the_size==the_capacity;
    }

    void pop();

    void push(const T&);

    void increase_key(const size_t&, const T&);

    inline const T &front()const
    {
        return data_ptr[0];
    }

private:

    void max_heapify(const size_t &index);

    size_t the_size=0;
    size_t the_capacity=0;
    std::unique_ptr<T[]> data_ptr;
};

//operator:
template<typename T>
std::ostream &operator<< (std::ostream &os, const UpHeap<T> &the_heap)
{
    for(size_t i=0; i!=the_heap.size(); i++)
    {
        os<< the_heap.data_ptr[i] << " ";
    }
    return os;
}

//constructor:
template<typename T>
UpHeap<T>::UpHeap(const std::initializer_list<T> &the_list):
    the_size(the_list.size()), the_capacity(2*the_list.size()), data_ptr(new T[2*the_list.size()])
{
    auto itr=the_list.begin();
    size_t i=0;

    while(itr!=the_list.end())
    {
        data_ptr[i]=*itr;

        itr++;
        i++;
    }

    for(size_t j=the_size/2-1; j!=0; j--)
    {
        max_heapify(j);
    }

    max_heapify(0);
}

template<typename T>
UpHeap<T>::UpHeap(const UpHeap<T> &the_heap):
    the_size(the_heap.the_size), the_capacity(the_heap.the_capacity), data_ptr(new T[2*the_heap.the_size])
{
    for(size_t i=0; i!=the_size; i++)
    {
        data_ptr[i]=the_heap.data_ptr[i];
    }

}

//methods:
template<typename T>
void UpHeap<T>::max_heapify(const size_t &index)
{
    if(index>=the_size)
        return;

    size_t largest=index;
    size_t the_left=left(index), the_right=right(index);

    T &index_val=data_ptr[index];
    T &left_val=data_ptr[the_left];
    T &right_val=data_ptr[the_right];

    if(the_left<the_size && left_val>index_val)
        largest=the_left;

    if(the_right<the_size && right_val>data_ptr[largest])
        largest=the_right;

    if(largest!=index)
    {
        T store=index_val;
        index_val=data_ptr[largest];
        data_ptr[largest]=store;
        max_heapify(largest);
    }
}

template<typename T>
void UpHeap<T>::pop()
{
    if(empty())
        return;

    data_ptr[0]=data_ptr[--the_size];//(the_old_size-1) is the tail.By "--" I got the tail and have the_size decreased.

    max_heapify(0);
}

template<typename T>
void UpHeap<T>::increase_key(const size_t &index, const T &new_key)
{
    if(new_key<=data_ptr[index])
        return;

    data_ptr[index]=new_key;

    for(size_t i=index; i!=0 && data_ptr[i]>data_ptr[parent(i)]; i=parent(i))
    {
        T store=data_ptr[i];
        data_ptr[i]=data_ptr[parent(i)];
        data_ptr[parent(i)];
    }
}

template<typename T>
void UpHeap<T>::push(const T &new_key)
{
    if(full())
    {
        std::unique_ptr<T[]> new_ptr(new T[2*the_capacity]);
        the_capacity*=2;

        for(size_t i=0; i!=the_size; i++)
        {
            new_ptr[i]=data_ptr[i];
        }

        data_ptr.reset(new_ptr.release());
    }

    increase_key(the_size, new_key);

    the_size++;
}

template<typename T>
using heap=UpHeap<T>;

int main()
{

    heap<int> he({3,5,2,7,4,3,1,5,4,7,5,2,121,2});
    std::vector<int> vec;

    std::cout << he << std::endl;

    while(!he.empty())
    {
        vec.push_back(he.front());
        he.pop();
    }

    for(const auto &elm: vec)
    {
        std::cout << elm << " ";
    }

    return 0;
}
