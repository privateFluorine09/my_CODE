#include<iostream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

using namespace std;


template<typename T>
class ArrayList;

template<typename T>
ostream &operator<< (ostream&, const ArrayList<T>&);

template<typename T>
class ArrayList
{

friend ostream &operator<< <T>(ostream&, const ArrayList<T>&);

public:
   ArrayList()=default;
   ArrayList(const initializer_list<T>&);
   ArrayList(const ArrayList<T>&);
   ~ArrayList()=default;

   inline size_t size()const
   {
      return listSize;
   }

   const T &operator[](const size_t&)const;
   T &operator[](const size_t&);

private:
   unique_ptr<T[]> data_ptr;
   size_t listSize=0;
};

template<typename T>
ostream &operator<< (ostream &os, const ArrayList<T> &theList)
{
   for(size_t i=0; i!=theList.size(); i++)
   {
      os << theList.data_ptr[i] << " ";
   }
   return os;
}

template<typename T>
ArrayList<T>::ArrayList(const initializer_list<T> &theList):listSize(theList.size())
{
   auto ptr=new T[theList.size()];
   auto itr=theList.begin();
   size_t i=0;

   while(itr!=theList.end())
   {
      *(ptr+i)=*itr;
      itr++, i++;
   }

   data_ptr.reset(ptr);
}

template<typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &another): listSize(another.listSize)
{
   data_ptr.reset(new T[another]);

   for(size_t i=0; i!=another.listSize; i++)
   {
      data_ptr[i]=another.data_ptr[i];
   }
}

template<typename T>
const T &ArrayList<T>::operator[](const size_t &index)const
{
   return data_ptr[index];
}

template<typename T>
T &ArrayList<T>::operator[](const size_t &index)
{
   return data_ptr[index];
}

int main()
{
   ArrayList<int> arr({3,2,5,5,3,3,5,6,84,43});

   cout << arr << endl;

   arr[3]=111111;

   cout << arr << endl;

   cout << arr.size() << endl;

   return 0;
}
