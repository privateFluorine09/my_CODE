#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

template<typename T>
class NoConst;

template<typename T>
std::ostream &operator<< (std::ostream &os, const NoConst<T> &obj);

template<typename T>
class NoConst
{

friend std::ostream &operator<< <T> (std::ostream &os, const NoConst&);

public:
   NoConst()=default;
   NoConst(const T &the_val): val(the_val) {}
   ~NoConst()=default;

   const NoConst &operator=(const T &obj)const
   {
      val=obj;
      return *this;
   }

   const NoConst &operator=(const NoConst &obj)const
   {
      val=obj.val;
      return *this;
   }

   inline T &change()const
   {
      return val;
   }

   inline void change(const T &new_val)const
   {
      val=new_val;
   }

private:
   mutable T val;
};

template<typename T>
std::ostream &operator<< (std::ostream &os, const NoConst<T> &obj)
{
   os << obj.val;
   return os;
}

int main()
{
   using new_int=NoConst<int>;

   const new_int n=89;

   n=32;

   std::cout << n << std::endl;

   return 0;
}
