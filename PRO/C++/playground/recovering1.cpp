#include<iostream>
#include<string>
#include<vector>

void insertion_sort(std::vector<int> &l)
{
   int i, j;

   int key;

   i=0, j=1;

   while(j!=l.size())
   {
      key=l[j];
      i=j-1;

      while(i>=0 && l[i] > key)
      {
         l[i+1]=l[i];
         i--;
      }

      l[i+1]=key;

      j++;
   }
}


int main()
{
   std::vector<int> vec={9,3,2,3,42,9,23,8,23,23,2,3,5,3,3,34,322};

   insertion_sort(vec);

   for(const int &elm : vec)
   {
      std::cout << elm << " ";
   }

   return 0;
}
