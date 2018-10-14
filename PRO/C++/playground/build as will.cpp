#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<initializer_list>
#include<algorithm>
#include<iterator>

using namespace std;

template<typename T>
class linkedList;

template<typename T>
struct node
{
   node()=default;
   node(const T &obj): element(obj) {}
   node(const T &obj, node *ptr1, node *ptr2): element(obj), prev(ptr1), next(ptr2) {}

   T element;
   node *prev=nullptr;
   node *next=nullptr;
};

template<typename T>
std::ostream &operator<< (std::ostream&, const linkedList<T>&);

template<typename T>
class linkedList
{
   friend std::ostream &operator<< <T> (std::ostream&, const linkedList<T>&);

public:
   linkedList()=default;
   linkedList(const linkedList&);
   linkedList(const initializer_list<T>&);
   ~linkedList();

   inline size_t size()const
   {
      return listSize;
   }

   const T &operator[](const size_t)const;
   T &operator[](const size_t);

   void reverse();

   const T &max()const;
   const T &min()const;


private:
   node<T> *head=new node<T>();
   size_t listSize=0;
};

//finish this class:

template<typename T>
linkedList<T>::linkedList(const initializer_list<T> &theList)
{
   auto itr=theList.begin();

   while(itr!=theList.end())
   {
      head->next=new node<T>(*itr, head, nullptr);

      itr++;
      head=head->next;
   }
}

template<typename T>
linkedList<T>::linkedList(const linkedList<T> &obj)
{
   node<T> *ptr=(obj.head)->next;
   node<T> *cur=head;

   while(ptr!=nullptr)
   {
      cur->next=new node<T>(ptr->element, cur, nullptr);

      cur=cur->next;
      ptr=ptr->next;
   }

}

template<typename T>
const T &linkedList<T>::operator[](const size_t index) const
{
   size_t curIndex=0;

   node<T> *curPtr=head->next;

   while(curPtr!=nullptr && curIndex!=index)
   {
      curIndex++;
      curPtr=curPtr->next;
   }

   if(curPtr==nullptr)
   {
      throw " ";

   }
   return curPtr->element;
}

template<typename T>
T &linkedList<T>::operator[](const size_t index)
{
   size_t curIndex=0;

   node<T> *curPtr=head->next;

   while(curPtr!=nullptr && curIndex!=index)
   {
      curIndex++;
      curPtr=curPtr->next;
   }

   if(curPtr==nullptr)
   {
      throw " ";
   }
   return curPtr->element;
}

int main()
{

   return 0;
}
