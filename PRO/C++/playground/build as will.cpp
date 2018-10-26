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

   template<typename NodeType>
   using ptr=std::shared_ptr<NodeType>;

   Node()=default;
   Node(const T &new_elm): elm(new_elm) {};
   Node(const T &new_elm, ptr<Node> the_l, ptr<Node> the_r, ptr<Node> the_p):
      elm(new_elm), left(the_l), right(the_r), parent(the_p) {};
   ~Node()=default;

   T elm;
   ptr<Node> left;
   ptr<Node> right;
   ptr<Node> parent;

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
   ptr_type<T> head=nullptr_t;
   size_t tree_size=0;

   template<typename F>
   static void preOrder(const F &);

   template<typename F>
   static void inOrder(const F &);

   template<typename F>
   static void postOrder(const F &);

   template<typename F>
   static void levelOrder(const F &);

};

template<typename F, typename Value_T>
static inline bool isTrue(const Value_T &lhs, const Value_T &rhs, const F &callable)
{
   return callable(lhs, rhs);
}

int main()
{
//int a=43, b=32;
   auto fun=[](const int &a, const int &b)->bool
   {
      return a==b;
   };

   std::cout << isTrue(1,2,fun);

   return 0;
}
