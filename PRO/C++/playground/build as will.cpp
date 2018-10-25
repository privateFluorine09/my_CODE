#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

template<typename T>
struct Node
{
   Node()=default;
   Node(const T &new_elm): elm(new_elm) {};


   T elm;
   std::shared_ptr<Node> left;
   std::shared_ptr<Node> right;
   std::shared_ptr<Node> parent;

   static std::shared_ptr<Node> nil;
};

template<typename T>
std::shared_ptr<Node<T>> Node<T>::nil(nullptr);

template<typename T>
class BinaryTree
{
   template<typename ElmType>
   using ptr_type=std::shared_ptr<Node<ElmType>>;

   const ptr_type<T> &nullptr_t=Node<T>::nil;

public:

private:
};

int main()
{
   std::shared_ptr<int> p(nullptr);

   auto q=p;

   auto q1=p;

   std::cout << q1.use_count() << " " << p.use_count();

   return 0;
}
