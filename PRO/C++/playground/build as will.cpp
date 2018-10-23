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

    void pop();
    void push(const T&);

    inline const T &top()const
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

//constructor:

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



int main()
{
    return 0;
}
