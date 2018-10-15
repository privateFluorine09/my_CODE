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

    inline bool empty()const
    {
       return (listSize==0);
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
linkedList<T>::~linkedList()
{
   auto ptr1=head->next;

   decltype(ptr1) ptr2=ptr1->next;

   while(ptr2!=nullptr)
   {
      delete ptr1;
      ptr1=ptr2;
      ptr2=ptr2->next;
   }

   delete ptr1;
   delete head;
}

template<typename T>
std::ostream &operator<< (std::ostream &os, const linkedList<T> &theList)
{
   auto cur=theList.head;

   while(cur->next!=nullptr)
   {
      os << cur->next->element << " ";
      cur=cur->next;
   }
   return os;
}

template<typename T>
linkedList<T>::linkedList(const initializer_list<T> &theList)
{
    auto itr=theList.begin();

    auto ptr=head;

    while(itr!=theList.end())
    {
        ptr->next=new node<T>(*itr, ptr, nullptr);
        listSize++;

        itr++;
        ptr=ptr->next;
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
    listSize=obj.listSize;
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

template<typename T>
void linkedList<T>::reverse()
{
    node<T> *ptr=head->next;
    ptr->prev=nullptr;
    node<T> *store=nullptr;

    while(ptr->next!=nullptr)
    {
        store=ptr->next;
        ptr->next=ptr->prev;
        ptr->prev=store;

        ptr=ptr->prev;
    }

    ptr->next=ptr->prev;
    ptr->prev=head;
    head->next=ptr;
}

template<typename T>
const T &linkedList<T>::max()const
{
   if(empty())
      throw " ";

   auto cur=head;

   auto result=cur->next;

   cur=cur->next;

   while(cur->next!=nullptr)
   {
      if(cur->next->element > result->element)
         result=cur->next;

      cur=cur->next;
   }

   return result->element;
}

template<typename T>
const T &linkedList<T>::min()const
{
   if(empty())
      throw " ";

   auto cur=head;

   auto result=cur->next;

   cur=cur->next;

   while(cur->next!=nullptr)
   {
      if(cur->next->element < result->element)
         result=cur->next;

      cur=cur->next;
   }

   return result->element;
}


int main()
{
    linkedList<int> list1({9,3,4,2,13,3,43,4,2,23});

    list1.reverse();

    cout << list1.min();

    return 0;
}
