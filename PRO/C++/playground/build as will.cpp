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
std::ostream &operator<< (std::ostream&, const UpQueue<T>&);

template<typename T>
class UpQueue
{
    friend std::ostream &operator<< <T> (std::ostream&, const UpQueue&);

public:

    //
    UpQueue()=default;
    UpQueue(const std::initializer_list<T>&);
    UpQueue(const UpQueue&);
    ~UpQueue()=default;
    //

    inline bool empty()const
    {
        return (the_size==0)||(the_rear==the_front);
    }

    inline bool full()const
    {
        return step_forward(the_rear)=the_front;
    }

    inline size_t size()const
    {
        return difference(the_rear, the_front);
    }

    void push(const T&);
    void pop();

    inline const T &front()const
    {
        return que_ptr[the_front];
    }

    inline const T &back()const
    {
        return que_ptr[the_rear];
    }

private:
    size_t the_front=0;
    size_t the_rear=0;
    size_t the_size=0;
    std::unique_ptr<T[]> que_ptr;

    inline size_t step_forward(const size_t &location, const size_t &steps=1)const
    {
        return (location+steps)%the_size;
    }

    inline size_t step_back(const size_t &location, const size_t &steps=1)const
    {
        return (location-steps)%the_size;
    }

    inline size_t difference(const size_t &location1, const size_t &location2)const //location1-location2
    {
        return (the_size+location1-location2)%the_size;
    }
};
//operators:
template<typename T>
std::ostream &operator<<(std::ostream &os, const UpQueue<T> &que)
{
    if(que.empty())
        return os;

    size_t steps=0;

    for(; steps!=que.size(); steps++)
    {
        os << que.que_ptr[que.step_forward(que.the_front, steps)] << " ";
    }

    return os;
}
//constructors:
template<typename T>
UpQueue<T>::UpQueue(const std::initializer_list<T> &the_list):
    the_rear(the_list.size()), the_size(2*the_list.size()), que_ptr(new T[2*the_list.size()])
{
    auto itr=the_list.begin();
    size_t location=the_front;

    for(; itr!=the_list.end(); itr++, location=step_forward(location))
    {
        que_ptr[location]=*itr;
    }
}

template<typename T>
UpQueue<T>::UpQueue(const UpQueue<T> &obj):
    the_rear(obj.the_rear), the_front(obj.the_front), the_size(obj.the_size), que_ptr(new T[obj.the_size])
{
    size_t steps=0;

    for(; steps!=obj.size(); steps++)
    {
        que_ptr[step_forward(the_front, steps)]=obj.que_ptr[step_forward(the_front, steps)];
    }
}

//methods:
template<typename T>
void UpQueue<T>::push(const T &obj)
{
   if(full())
   {
      std::unique_ptr<T[]> new_ptr(new T[2*the_size]);

      size_t steps=0;

      for(; steps!=the_size ; steps++)
      {
         new_ptr[steps]=que_ptr[step_forward(the_front, steps)];
      }

      the_front=0;
      the_rear=the_size-1;
      the_size*=2;
   }

   the_rear=step_forward(the_rear);
   que_ptr[the_rear]=obj;
}

template<typename T>
void UpQueue<T>::pop()
{
   if(empty())
      return;

   the_front=step_forward(the_front);
}

template<typename T>
using queue=UpQueue<T>;

int main()
{
    queue<int> que={1,2,3,4,5,6,7};

    std::cout << que <<std::endl;

    return 0;
}
