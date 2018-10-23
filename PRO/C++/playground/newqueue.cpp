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
   inline bool empty()const
   {
      return (the_size==0)||(the_front==the_rear);
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
      return que_ptr[step_back(the_rear)];
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

int main()
{
   return 0;
}
