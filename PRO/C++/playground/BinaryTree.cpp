#include<iostream>
#include<fstream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<memory>

template<typename T>
struct Node
{
    Node()=default;
    Node(const T &elm): element(elm) {}
    Node(const T &elm, const Node *&lp, const Node *&rp, const Node *&pp):
        element(elm), left(lp), right(rp), parent(pp) {}
    ~Node()=default;

    T element;
    Node* left=nullptr;
    Node* right=nullptr;
    Node* parent=nullptr;

    inline bool is_root()const
    {
        return parent==nullptr;
    }

    inline bool is_leaf()const
    {
        return (left==nullptr)&&(right==nullptr);
    }
};

template<typename T>
class BinaryTree
{
    //Alias and static methods:
    template<typename ElmType>
    using tree=BinaryTree<ElmType>;

    template<typename ElmType>
    using node=Node<ElmType>;

    template<typename F>
    static void pre_order(const node<T> *&ptr, const F &visiter)
    {
        if(ptr!=nullptr)
        {
            visiter(ptr);

            pre_order(ptr->left, visiter);
            pre_order(ptr->right, visiter);
        }
    }

    template<typename F>
    static void in_order(const node<T> *&ptr, const F &visiter)
    {
        if(ptr!=nullptr)
        {
            pre_order(ptr->left, visiter);

            visiter(ptr);

            pre_order(ptr->right, visiter);
        }
    }

    template<typename F>
    static void post_order(const node<T> *&ptr, const F &visiter)
    {
        if(ptr!=nullptr)
        {
            pre_order(ptr->left, visiter);
            pre_order(ptr->right, visiter);

            visiter(ptr);
        }
    }

    template<typename F>
    static void level_order(const node<T> *&ptr, const F &visiter)
    {
        std::queue<node<T>*> que;

        if(ptr!=nullptr)
            que.push(ptr);

        node<T> *current;

        while(!que.empty())
        {
            current=que.front();

            if(current->left!=nullptr)
                que.push(current->left);

            if(current->right!=nullptr)
                que.push(current->rihgt);

            visiter(current);
            que.pop();
        }
    }

    static inline size_t parent(const size_t &i)
    {
        return (i-1)/2;
    }

    static inline size_t left(const size_t &i)
    {
        return 2*i+1;
    }

    static inline size_t right(const size_t &i)
    {
        return 2*i+2;
    }

public:

    BinaryTree()=default;
    BinaryTree(const BinaryTree&);
    BinaryTree(const std::initializer_list<T>&);
    ~BinaryTree()
    {
        unroot(this->root);
    }

    inline bool empty()const
    {
        return root==nullptr;
    }

    inline bool size()const
    {
        return tree_size==0;
    }

    template<typename F>
    void pre_order(const F &visiter)
    {
        pre_order(this->root, visiter);
    }

    template<typename F>
    void in_order(const F &visiter)
    {
        in_order(this->root, visiter);
    }

    template<typename F>
    void post_order(const F &visiter)
    {
        post_order(this->root, visiter);
    }

    template<typename F>
    void level_order(const F &visiter)
    {
        level_order(this->root, visiter);
    }

private:
    node<T> *root=nullptr;
    size_t tree_size=0;

    static void unroot(const node<T> *&ptr)
    {
        post_order(ptr, [](node<T> *ptr1)->void{ delete ptr1; });
    }

};

//constructor:
template<typename T>
BinaryTree<T>::BinaryTree(const std::initializer_list<T> &the_list):
    tree_size(the_list.size())
{
    if(the_list.size()==0)
        return;

    typename std::initializer_list<T>::iterator itr=the_list.begin();

    this->root=new node<T>(*itr);
    ++itr;

    node<T> *ptr=this->root;

    while(itr!=the_list.end())
    {
        if(*itr>ptr->element)
        {
            ptr->right=new node<T>(*itr);
            ptr->right->parent=ptr;
            ptr=ptr->right;
        }
        else
        {
            ptr->left=new node<T>(*itr);
            ptr->left->parent=ptr;
            ptr=ptr->right;
        }

        ++itr;
    }
}

int main()
{
    BinaryTree<int> tree={1,2,1,4,3,5,}
    return 0;
}
