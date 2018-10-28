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
   using ptr=std::unique_ptr<NodeType>;

   Node()=default;
   Node(const T &new_elm): elm(new_elm) {};
   Node(const T &new_elm, ptr<Node> the_l, ptr<Node> the_r, ptr<Node> the_p):
      elm(new_elm), left(the_l), right(the_r), parent(the_p) {};
   ~Node()=default;

   T elm;
   ptr<Node> left;
   ptr<Node> right;
   ptr<Node> parent;

};

template<typename T>
class BinaryTree
{
   template<typename ElmType>
   using ptr_type=std::shared_ptr<Node<ElmType>>;

   static inline bool isNull()
   {
      return;
   }

public:

private:
   ptr_type<T> head;
   size_t tree_size=0;

   template<typename F>
   static void preOrder(const F &, ptr_type<T>&);

   template<typename F>
   static void inOrder(const F &, ptr_type<T>&);

   template<typename F>
   static void postOrder(const F &, ptr_type<T>&);

   template<typename F>
   static void levelOrder(const F &, ptr_type<T>&);

};



//operator:

//constructor:

//method:
template<typename T>
template<typename F>
void BinaryTree<T>::preOrder(const F &visiter, ptr_type<T> &ptr)
{

}

template<typename F, typename Value_T>
static inline bool isTrue(const Value_T &lhs, const Value_T &rhs, const F &callable)
{
   return callable(lhs, rhs);
}

using std::cout;

int main()
{
   std::unique_ptr<Node<int>> n1(new Node<int>(3));

   std::unique_ptr<Node<int>> n2(new Node<int>(3));

   (n1->left).reset(n2.release());

   (n2->parent).reset(n1.release());

   return 0;
}
