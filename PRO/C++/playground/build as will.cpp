#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

template<typename Itr>
void heap_sort(const Itr &_begin, const Itr &_end);

template<typename Itr>
class Heap_sort_pack
{
   ~Heap_sort_pack()=delete;

   friend void heap_sort<Itr>(const Itr&, const Itr&);

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

   static void max_heapify(const Itr&, const Itr&, const size_t &index)
   {

   }
};

template<typename Itr>
void heap_sort(const Itr &_begin, const Itr &_end)
{

}


int main()
{

   return 0;
}
