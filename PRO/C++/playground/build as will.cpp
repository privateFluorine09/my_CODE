#include<iostream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>



using namespace std;

template<typename T>
class UpStack;

template<typename T>
ostream &operator<< (ostream&, const UpStack<T>&);

template<typename T>
class UpStack
{
   friend ostream &operator<< <T> (ostream&, const UpStack&);
public:
   UpStack()=default;
   UpStack(const UpStack&);
   UpStack(const initializer_list<T>&);
   ~UpStack()=default;

   inline size_t size()const
   {
      return stack_size;
   }

   inline bool empty()const
   {
      return !static_cast<bool>(stack_size);
   }

   inline const T &top()const
   {
      return stc_ptr[stack_size-1];
   }

   inline void pop()
   {
      stack_size--;
   }

   inline bool isfull()const
   {
      return stack_size==stack_capacity;
   }

   void push(const T&);

private:
   size_t stack_size=0;
   size_t stack_capacity=0;
   unique_ptr<T[]> stc_ptr;
};
//constructor:
template<typename T>
UpStack<T>::UpStack(const UpStack<T> &obj):
   stack_size(obj.stack_size), stack_capacity(obj.stack_capacity), stc_ptr(new T[obj.stack_capacity])
{
   for(int i=0; i!=stack_size; i++)
       stc_ptr[i]=obj.stc_ptr[i];
}

template<typename T>
UpStack<T>::UpStack(const initializer_list<T> &obj):
   stack_size(obj.size()), stack_capacity(2*obj.size()), stc_ptr(new T[2*obj.size()])
{
   auto itr=obj.begin();
   int i;
   for(i=0; itr!=obj.end(); itr++, i++)
      stc_ptr[i]=*itr;
}

template<typename T>
void UpStack<T>::push(const T &obj)
{
   if(isfull())
   {
      unique_ptr<T[]> new_ptr(new T[2*stack_capacity]);

      int i;
      for(i=0; i!=stack_size; i++)
         new_ptr[i]=stc_ptr[i];
   }
}
//operator:

//


template<typename T, typename F>
void stackClear(UpStack<T> &stc,F subMethod)
{
   while(!stc.empty())
   {
      subMethod(stc.top());
      stc.pop();
   }
}

int main()
{
   ios::sync_with_stdio(false);
   UpStack<int> stc={2,34,5,6,3,2,1,2,4,5,6};

   auto sub=[](int num)->void
   {
      cout << num << " ";
   };

   stackClear(stc, sub);

   return 0;
}
