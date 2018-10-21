#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

template<typename T>
class UpQueue
{
public:
   UpQueue()=default;
   UpQueue(const initializer_list<T>&);
   ~UpQueue()=default;

   inline size_t size()const
   {
      return difference(theRear, theFront);
   }

private:
   size_t queueSize=0;

   size_t theFront=0;
   size_t theRear=0;
   unique_ptr<T[]> que_ptr;

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

