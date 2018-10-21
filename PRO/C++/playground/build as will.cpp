#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

template<typename T>
class UpQueue;

template<typename T>
std::ostream &operator << (std::ostream &os, const UpQueue<T> &que);

template<typename T>
class UpQueue
{

    friend std::ostream &operator<< <T> (std::ostream &os, const UpQueue<T> &que);

public:
    UpQueue():que_ptr(new T[10]), queueSize(10) {};
    UpQueue(const std::initializer_list<T>&);
    UpQueue(const UpQueue&);
    ~UpQueue()=default;

    inline size_t size()const
    {
        return difference(theRear, theFront);
    }

    void push(const T&);
    void pop();

    inline const T &front()const
    {
        return que_ptr[theFront];
    }

    inline const T &back()const
    {
        return que_ptr[theRear];
    }

    inline bool empty()const
    {
        return theFront==theRear;
    }

private:
    size_t queueSize=0;

    size_t theFront=0;
    size_t theRear=0;
    std::unique_ptr<T[]> que_ptr;

    inline size_t step_forward(const size_t &location)const
    {
        return (location+1)%queueSize;
    }

    inline size_t step_forward(const size_t &location, const size_t &steps)const
    {
        return (location+steps)%queueSize;
    }

    inline size_t difference(const size_t &location1, const size_t &location2)const
    {
        return (location1+queueSize-location2)%queueSize;
    }
};

template<typename T>
std::ostream &operator << (std::ostream &os, const UpQueue<T> &que)
{
    size_t cur=que.theFront;
    while(cur!=que.theRear)
    {
        os << que.que_ptr[cur] << " ";
        cur=que.step_forward(cur);
    }

    return os;
}


template<typename T>
UpQueue<T>::UpQueue(const std::initializer_list<T> &the_list):
    queueSize(2*the_list.size()), theRear(the_list.size()), que_ptr(new T[2*the_list.size()])
{
    size_t i=0;
    auto itr=the_list.begin();
    for(; i!=the_list.size(); i++, itr++)
    {
        que_ptr[i]=*itr;
    }
}

template<typename T>
UpQueue<T>::UpQueue(const UpQueue<T> &que):
    queueSize(que.queueSize), theFront(que.theFront), theRear(que.theRear), que_ptr(new T[que.queueSize])
{
    size_t i=theFront;
    for(; i!=theRear; i=step_forward(i))
    {
        que_ptr[i]=que.que_ptr[i];
    }
}

template<typename T>
void UpQueue<T>::push(const T &theNew)
{
    if(theRear==theFront)
    {
        size_t current1, current2;

        std::unique_ptr<T[]> new_ptr(new T[2*queueSize]);

        for(current1=0, current2=theFront; current2!=theRear;
        current1++, current2=step_forward(current2))
        {
            new_ptr[current1]=que_ptr[current2];
        }

        que_ptr.reset(new_ptr.release());

        theFront=0;
        theRear=current1;
        queueSize*=2;
    }

    que_ptr[theRear]=theNew;
    theRear=step_forward(theRear);
}

int main()
{

    UpQueue<int> que= {2,3,3,4,3};

    int input;

    while(std::cin>>input)
    {
        que.push(input);
        std::cout << que << std::endl
        ;

    }


    return 0;
}
