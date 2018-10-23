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
public:

private:
   inline size_t parent(const size_t &index)const
   {
      return (index-1)/2;
   }

   inline size_t left(const size_t &index)const//left child
   {
      return 2*index+1;
   }

   inline size_t right(const size_t &index)const
   {
      return 2*index+2;
   }
};

int main()
{
   return 0;
}
