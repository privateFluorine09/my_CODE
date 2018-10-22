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

private:
   size_t the_front=0;
   size_t the_rear=0;
   size_t the_size=10;
   unique_ptr<T[]> que_ptr;

   inline step_forward(const size_t &location, const size_t &steps=1)
   {
      return (location+steps)%the_size;
   }
};
