#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED


#include<string>
#include<deque>
#include<vector>
#include<utility>
#include<functional>

using namespace std;

//for C++11 only


// need a erase and a pop_back

template<typename>
class ADT_array_list;

template<typename T>
std::ostream &operator<< (std::ostream &os, const ADT_array_list<T> &obj);
template<typename T>
bool operator==(const ADT_array_list<T> &arr1, const ADT_array_list<T> &arr2);
template<typename T>
bool operator!=(const ADT_array_list<T> &arr1, const ADT_array_list<T> &arr2);
template<typename T>
bool operator<(const ADT_array_list<T> &arr1, const ADT_array_list<T> &arr2);

template<typename T>
class ADT_array_list
{
friend std::ostream &operator<< <T>(std::ostream &os, const ADT_array_list &obj);
friend bool operator== <T>(const ADT_array_list &arr1, const ADT_array_list &arr2);
friend bool operator!= <T>(const ADT_array_list &arr1, const ADT_array_list &arr2);
friend bool operator< <T>(const ADT_array_list &arr1, const ADT_array_list &arr2);

//friend std::ostream &operator<T>(std::ostream &os, const ADT_array_list &obj)

public:
    ADT_array_list()=default;
    ADT_array_list(const ADT_array_list& );
    ADT_array_list(int cap): list_capacity(cap) {elm_ptr=new T [cap];};
    ADT_array_list(int cap, const T &elm): list_capacity(cap), list_size(cap), elm_ptr(new T [cap])
                                                    {int i=0;while(i!=cap)elm_ptr[i]=elm,i++;};
    ADT_array_list(const std::vector<T> &);
    ~ADT_array_list() {delete [] elm_ptr;};

    //operators:


    const T &operator[](int)const;
    T &operator[](int);

    //methods:

    T &list_at(int index);
    const T &list_at(int index) const;
    T &list_forward() const{return *elm_ptr;};
    int size() const { return list_size;};
    int capacity() const {return list_capacity;};
    int find_index(const T&) const;
    void insert(int, const T&);
    void print(std::ostream &os)const;
    //int cap(){return capacity;};
    void reserve(int) ;
    //void test(int index){check_index(index);};
    void trim_to_size();
    void resize(int);
    void push_back(const T&);
    void swap(ADT_array_list &);
    void erase(int);
    void pop_back();
    void reverse();


private:

    int list_capacity=0;
    int list_size=0;
    T *elm_ptr=nullptr;

    //methods:

    bool check_index(int index) const;

};

//DEFINATION:

//constructor:
template<typename T>
ADT_array_list<T>::ADT_array_list(const ADT_array_list<T> &obj)
{

    list_capacity=obj.list_capacity;
    list_size=obj.list_size;

    elm_ptr=new T[list_capacity];

    for(int i=0; i!=list_capacity; i++)
    *(elm_ptr+i)=*(obj.elm_ptr+i);

}

template<typename T>
ADT_array_list<T>::ADT_array_list(const std::vector<T> &obj)
{
    elm_ptr=new T[obj.size()];
    list_capacity=obj.size();
    list_size=obj.size();

    int i=0;

    auto itr=obj.begin();

    for(; i!=list_size; i++, itr++)
    {
        *(elm_ptr+i)=*itr;
    }
}

//operators:

template<typename T>
const T &ADT_array_list<T>::operator[](int index)const
{
    if(!check_index(index))
        throw "illegal index";
    return elm_ptr[index];
}

template<typename T>
T &ADT_array_list<T>::operator[](int index)
{
    if(!check_index(index))
        throw "illegal index";
    return elm_ptr[index];
}
//public methods:

template<typename T>
T &ADT_array_list<T>::list_at(int index)
{
    if(!check_index(index))
    throw "illegal index";
    return elm_ptr[index];
}

template<typename T>
const T &ADT_array_list<T>::list_at(int index) const
{
    if(!check_index(index))
    throw "illegal index";
    return elm_ptr[index];
}

template<typename T>
int ADT_array_list<T>::find_index(const T &elm)const
{
    T *cur=elm_ptr;

    while(cur!=elm_ptr+list_size)
    {
        if(*cur==elm)
        return cur-elm_ptr;
        cur++;
    }

    return list_size;

}

template<typename T>
void ADT_array_list<T>::reserve(int new_cap)
{
    if(new_cap < 0)
    {
        throw "illegal new_size";
    }

    int num=(list_capacity < new_cap)? list_capacity: new_cap;

    list_capacity=new_cap;

    list_size=(list_size<list_capacity)?list_size: list_capacity;

    T *new_ptr=new T[new_cap];

    for(int i=0; i!=num; i++)
    {
        new_ptr[i]=elm_ptr[i];
    }

    delete [] elm_ptr;

    elm_ptr=new_ptr;


}

template<typename T>
void ADT_array_list<T>::insert(int index, const T &obj)
{
    if(!(check_index(index) || index==list_size) )
    {
        throw "illegal index";
    }

    if(index==list_capacity)
    {
        reserve(2*list_capacity);
    }

    list_size++;

    //copy backward:

    for(int i=list_size; i!=index; i--)
    elm_ptr[i+1]=elm_ptr[i];

    elm_ptr[index]=obj;
}

template<typename T>
void ADT_array_list<T>::print(std::ostream &os) const
{
    T *cur=elm_ptr;
    while((cur-elm_ptr)!=list_size )
    {
        os << *cur << " " ;
        cur++;
    }

    os << std::endl;
}

template<typename T>
void ADT_array_list<T>::trim_to_size()
{
     T *new_ptr;
     new_ptr=new T[list_size];

     for(int i=0; i!=list_size; i++)
     new_ptr[i]=elm_ptr[i];

     delete [] elm_ptr;

     elm_ptr=new_ptr;

     list_capacity=list_size;

}

template<typename T>
void ADT_array_list<T>::resize(int new_size)
{
    if(new_size<0 && new_size>list_capacity)
    {
        throw "illegal new_size";
    }

    list_size=(list_capacity<new_size)?list_capacity:new_size;

}

template<typename T>
void ADT_array_list<T>::push_back(const T &obj)
{
    if(list_size==list_capacity)
    {
        reserve(2*list_capacity);
    }
    elm_ptr[list_size]=obj;
    list_size++;
}

template<typename T>
void ADT_array_list<T>::swap(ADT_array_list<T> &obj)
{
    int restore_size=list_size, restore_cap=list_capacity;

    list_capacity=obj.list_capacity;
    list_size=obj.list_size;

    obj.list_capacity=restore_cap;
    obj.list_size=restore_size;

    T *restore;
    restore=elm_ptr;

    elm_ptr=obj.elm_ptr;
    obj.elm_ptr=restore;
}

template<typename T>
void ADT_array_list<T>::erase(int index)
{
    if(!check_index(index))
    {
        throw "illegal index"; //sth wrong
    }

    int i;

    for(i=index; (i+1)!=list_size; i++)
    {
        elm_ptr[i]=elm_ptr[i+1];
    }

    delete (elm_ptr+list_size-1);

    list_size--;
}

template<typename T>
void ADT_array_list<T>::pop_back()
{
    delete (elm_ptr+list_size-1);

    list_size--;

}

template<typename T>
void ADT_array_list<T>::reverse()
{
    int sup=list_size-1,inf=0;

    for(; sup>inf; sup--, inf++)
    {
        T restore=elm_ptr[sup];
        elm_ptr[sup]=elm_ptr[inf];
        elm_ptr[inf]=restore;
    }
}


//private methods:
template<typename T>
bool ADT_array_list<T>::check_index(int index) const
{
    if(index<0 || index>=list_size)
    return false;

    else
    return true;

}

//friend:

template<typename T>
std::ostream &operator<< (std::ostream &os, const ADT_array_list<T> &obj)
{
    T *cur;
    cur=obj.elm_ptr;

    while(cur-obj.elm_ptr!=obj.list_size)
    {
        os << *cur << " " ;
        cur++;
    }
    return os;
}

template<typename T>
bool operator==(const ADT_array_list<T> &arr1, const ADT_array_list<T> &arr2)
{
    if(arr1.size()!=arr2.size())
        return false;

    int i=0;

    while(i!=arr1.size())
    {
        if(arr1.elm_ptr[i]!=arr2.elm_ptr[i])
            return false;
        i++;
    }

    return true;

}

template<typename T>
bool operator!=(const ADT_array_list<T> &arr1, const ADT_array_list<T> &arr2)
{
    if(arr1.size()!=arr2.size())
        return true;

    int i=0;

    while(i!=arr1.size())
    {
        if(arr1.elm_ptr[i]!=arr2.elm_ptr[i])
            return true;

        i++;
    }

    return false;

}

template<typename T>
bool operator<(const ADT_array_list<T> &arr1, const ADT_array_list<T> &arr2)
{
    int i=0;

    while(i!=arr1.size() && i!=arr2.size())
    {
        if(arr1.elm_ptr[i]<arr2.elm_ptr[i])
        return true;

        if(arr1.elm_ptr[i]>arr2.elm_ptr[i])
        return false;

        i++;
    }

    return false;
}






//linked chain




template<typename T>
class ADT_chain_node
{
public:
    T elm;
    ADT_chain_node *next=nullptr;


    ADT_chain_node()=default;
    ADT_chain_node(const T &elm): elm(elm){};
    ADT_chain_node(const T &elm, ADT_chain_node *next): elm(elm), next(next) {};
};

template<typename T>
class ADT_chain;

template<typename T>
std::ostream &operator<< (std::ostream &os, const ADT_chain<T> &obj);

template<typename T>
class ADT_chain
{
friend std::ostream &operator<< <T>(std::ostream &os, const ADT_chain<T> &obj);

public:
    class iterator;

    ADT_chain();
    ADT_chain(const ADT_chain&);
    ADT_chain(const std::vector<T>&);
    ~ADT_chain();

    iterator begin() {return iterator(head_node);}

    bool empty() const {return list_size==0;}
    int size() const {;return list_size;}
    T &at(int index);
    int index_of(const T &elm) const;
    void erase(int);
    void insert(int, const T&);//
    void print(std::ostream&) const;
    void reverse();
    void set(int, T);
    void swap(ADT_chain<T> &obj);
    int last_index_of(const T &) const;


//operator member
    bool operator==(ADT_chain);
    bool operator!=(ADT_chain);

protected:
    bool check_index(int index) {return (index>=0 && index<list_size);}
    ADT_chain_node<T> *head_node=nullptr;
    int list_size=0;

};

//DEFINATION:

//constructor:
template<typename T>
ADT_chain<T>::ADT_chain(const ADT_chain<T> &obj)
{
    list_size=obj.list_size;

    if(list_size==0)
    return;

    ADT_chain_node<T> *source=obj.head_node;
    head_node=new ADT_chain_node<T>(source->elm);

    ADT_chain_node<T> *target=head_node;

    for(source=source->next;
        source!=nullptr;
        source=source->next, target=target->next)
        target->next=new ADT_chain_node<T>(source->elm);

    target->next=nullptr;

}

template<typename T>
ADT_chain<T>::ADT_chain(const std::vector<T> &obj)
{
    auto itr=obj.begin();

    head_node=new ADT_chain_node<T>(*itr);

    ADT_chain_node<T> *target=head_node;

    itr++;

    for(; itr!=obj.end(); itr++, target=target->next)
    {
        target->next=new ADT_chain_node<T>(*itr);
    }

    target->next=nullptr;

    list_size=obj.size();
}


template<typename T>
ADT_chain<T>::~ADT_chain()
{
    ADT_chain_node<T> *next_node;

    while(head_node!=nullptr)
    {
        next_node=head_node->next;
        delete head_node;
        head_node=next_node;
    }
}

//operators:

template<typename T>
std::ostream &operator<< (std::ostream &os, const ADT_chain<T> &obj)
{
    ADT_chain_node<T> *cur=obj.head_node;

    while(cur!=nullptr)
    {
        os << cur->elm <<" ";
        cur=cur->next;
    }

    return os;
}

template<typename T>
bool ADT_chain<T>::operator==(ADT_chain<T> obj)
{
    if(list_size!=obj.list_size)
        return false;

    ADT_chain_node<T> *cmp_tgt1, *cmp_tgt2;

    cmp_tgt1=head_node;

    cmp_tgt2=obj.head_node;

    while(cmp_tgt1!=nullptr)
    {
        if(cmp_tgt1->elm!=cmp_tgt2->elm)
            return false;

        cmp_tgt1=cmp_tgt1->next;
        cmp_tgt2=cmp_tgt2->next;
    }

    return true;
}

template<typename T>
bool ADT_chain<T>::operator!=(ADT_chain<T> obj)
{
    return !(*this==obj);
}

//method:
template<typename T>
class ADT_chain<T>::iterator
{
public:
    iterator(ADT_chain_node<T> *Node=nullptr):node(Node){};

    T& operator*() const {return node->elm;};
    T* operator->() const {return &node->elm;};

    iterator &operator++() {node=node->next; return *this;};
    iterator &operator++(int) {iterator old=*this; node=node->next ;return old;};

    bool operator!=(const iterator right) const{return node!=right.node;}
    bool operator==(const iterator right) const{return node==right.node;}

protected:

    ADT_chain_node<T> *node;

private:
};

template<typename T>
T& ADT_chain<T>::at(int index)
{
    if(!check_index(index))
        throw "illegal index";

    ADT_chain_node<T> *current=head_node;

    for(int i=0; i!=index; i++)
    {
        current=current->next;
    }

    return current->elm;

}

template<typename T>
void ADT_chain<T>::insert(int index, const T &obj)
{
    if(!check_index(index))
        throw "illegal index";
    if(index==0)
        head_node=new ADT_chain_node<T>(obj, head_node);
    else
    {
        ADT_chain_node<T> *ptr=head_node;

        for(int i=0; i!=index-1; i++)
        ptr=ptr->next;

        ptr->next=new ADT_chain_node<T>(obj, ptr->next);

    }

    list_size++;
}

template<typename T>
void ADT_chain<T>::reverse()
{
    ADT_chain_node<T> *target, *prev, *next_node;
    target=head_node->next;
    prev=head_node;

    head_node->next=nullptr;

    while(target!=nullptr)
    {

        next_node=target->next;

        target->next=prev;

        prev=target;

        target=next_node;

    }
    head_node=prev;
}

template<typename T>
void ADT_chain<T>::set(int index, T obj)
{
    if(index<0 || index>=list_size)
        throw "illegal index";

    ADT_chain_node<T> *target;

    target=head_node;

    int i=0;

    while(true)
    {
        if(i==index)
        {
            target->elm=obj;
            break;
        }

        i++;
        target=target->next;
    }
}

template<typename T>
void ADT_chain<T>::swap(ADT_chain<T> &obj)
{
    ADT_chain_node<T> *restore1;
    restore1=head_node;

    head_node=obj.head_node;
    obj.head_node=restore1;

    int restore2=list_size;

    list_size=obj.list_size;

    obj.list_size=restore2;
}

template<typename T>
int ADT_chain<T>::last_index_of(const T &obj) const
{
    ADT_chain_node<T> *target;
    target=head_node;
    int i=0, noteBook, index=0;

    while(target!=nullptr)
    {

        if(target->elm==obj)
            noteBook=index, i++;
        target=target->next;
        index++;
    }

    if(i==0)
        return list_size;

    return noteBook;
}

//template<typename T>
//ADT_chain<T> ADT_chain_meld(ADT_chain<T> obj1, ADT_chain<T> obj2)
//{


//}



//ADT_stack


template<typename T>
class ADT_stack
{
public:
    virtual ~ADT_stack() {}
    virtual bool empty() const=0;
    virtual int size() const=0;
    virtual T &top()=0;
    virtual void pop()=0;
    virtual void push(const T&)=0;
};





template<typename T>
class ADT_vector_stack;

template<typename T>
std::ostream &operator<< (std::ostream&, const ADT_vector_stack<T>&);

template<typename T>
class ADT_vector_stack: private std::vector<T>,
                        public ADT_stack<T>
{

friend std::ostream &operator<< <T>(std::ostream&, const ADT_vector_stack<T>&);

public:

    //ADT_vector_stack(int initial_capacity=10): vec
    ADT_vector_stack()=default;
    ADT_vector_stack(const std::vector<T> &obj);
    bool empty() const { return std::vector<T>::empty(); };
    int size() const { return std::vector<T>::size(); };
    vector<T> to_vector();
    pair<ADT_vector_stack<T>, ADT_vector_stack<T>> devide();
    void combine(ADT_vector_stack<T> &);


    T &top()
    {
        if(std::vector<T>::empty())
            throw "stack is empty";

        return vector<T>::at( std::vector<T>::size()-1 );

    }

    void pop()
    {
        if(vector<T>::empty())
            throw "stack is empty";

        auto itr=vector<T>::end();

        itr--;

        std::vector<T>::erase(itr);
    }

    void push(const T &obj)
    {
        vector<T>::insert(std::vector<T>::end(), obj);
    }

};

template<typename T>
ADT_vector_stack<T>::ADT_vector_stack(const std::vector<T> &obj)
{
    auto itr=obj.begin();
    while(itr!=obj.end())
    {
        push(*itr);
        itr++;
    }
}

//operator:

template<typename T>
std::ostream &operator<<(std::ostream &os, ADT_vector_stack<T> &obj)
{
    ADT_vector_stack<T> another=obj;
    while(!another.empty())
    {
        os << another.top() << " ";

        another.pop();

    }
    return os;
}

//method

template<typename T>
vector<T> ADT_vector_stack<T>::to_vector()
{
    vector<T> result;
    ADT_vector_stack<T> stc=*this;

    while(!stc.empty())
    {
        result.push_back(stc.top());
        stc.pop();
    }

    return result;
}

template<typename T>
pair <ADT_vector_stack<T>, ADT_vector_stack<T>> ADT_vector_stack<T>::devide()
{
    ADT_vector_stack<T> obj_copy=*this;
    ADT_vector_stack<T> stc1, stc2;
    int i=0, j=0, size1, size2;

    size1=obj_copy.size()/2;

    size2=obj_copy.size()-size1;

    while(i!=size2)
    {
        stc2.push(obj_copy.top());

        obj_copy.pop();

        i++;
    }


      while(j!=size1)
    {
        stc1.push(obj_copy.top());

        obj_copy.pop();

        j++;
    }

    return make_pair(stc1, stc2);
}

template<typename T>
void ADT_vector_stack<T>::combine(ADT_vector_stack<T> &obj)
{
    ADT_vector_stack<T> anot=obj;

    while(!anot.empty())
    {
        push(anot.top());
        anot.pop();
    }

}


template<typename T>
class ADT_array_stack;

template<typename T>
std::ostream &operator<< (std::ostream&, ADT_array_stack<T>&);

template<typename T>
class ADT_array_stack: public ADT_stack<T>
{

    friend ostream &operator << <T> (std::ostream&, ADT_array_stack<T>&);

public:
    //constructor:
    ADT_array_stack()=default;
    ADT_array_stack(int capacity): stack_capacity(capacity) { stc_ptr=new T[capacity]; };
    ADT_array_stack(vector<T>&);
    ~ADT_array_stack() { delete stc_ptr;};

    bool empty() const { return (stack_size==0); };
    int size() const { return stack_size; };
    T &top();
    void push(const T&);
    void pop();

private:

    int stack_capacity;
    int stack_size;
    T *stc_ptr;

};

//constructor:

template<typename T>
ADT_array_stack<T>::ADT_array_stack(vector<T> &obj)
{
    stack_size=obj.size();
    stack_capacity=2*stack_size;

    stc_ptr=new T[stack_capacity];

    int i=0;
    auto itr=obj.begin();

    while(itr!=obj.end())
    {
        stc_ptr[i]=*itr;

        itr++;
        i++;
    }
}

//operator:

template<typename T>
std::ostream &operator<< (std::ostream &os, ADT_array_stack<T> &stc)
{
    int i=0;

    while( i!= stc.stack_size)
    {
        os << stc.stc_ptr[i] << " ";

        i++;
    }


    return os;
}

//method:

template<typename T>
T &ADT_array_stack<T>::top()
{
    if(empty())
    throw " stack is empty";

    return stc_ptr[stack_size-1];
}


template<typename T>
void ADT_array_stack<T>::pop()
{
    if(empty())
    throw " stack is empty";

    delete (stc_ptr+stack_size-1);

    stack_size--;
}

template<typename T>
void ADT_array_stack<T>::push(const T &obj)
{
    if(stack_size==stack_capacity)
    {
        T *new_ptr;
        new_ptr=new T[2*stack_capacity];

        int i=0;

        for(i=0; i!=stack_size; i++)
        {
            new_ptr[i]=stc_ptr[i];
        }


        stc_ptr=new_ptr;
    }

    stc_ptr[stack_size]=obj;

    stack_size++;
}

template<typename T>
class ADT_chain_stack;
template<typename T>
std::ostream &operator<< (std::ostream &, const ADT_chain_stack<T> &);

/*template<typename T>
class ADT_chain_stack: ADT_stack
{
     typedef ADT_chain_node<T> node;
     typedef ADT_chain_stack<T> stack;
};*/



template<typename T>
class ADT_queue
{
public:
	virtual bool empty() const = 0;
	virtual int size() const = 0;
	virtual T &front() = 0;
	virtual T &back() = 0;
	virtual void pop() = 0;
	virtual void push(const T &obj) = 0;

};

template<typename T>
class ADT_array_queue;

template<typename T>
std::ostream &operator<< (std::ostream&, const ADT_array_queue<T>&);

template<typename T>
class ADT_array_queue: public ADT_queue<T>
{

    friend std::ostream &operator<< <T> (std::ostream&, const ADT_array_queue<T>&);

public:
    ADT_array_queue()=default;
    ADT_array_queue(int cap):queue_capacity(cap) {queue_ptr=new T[cap];}
    ~ADT_array_queue() { delete []queue_ptr;}

    bool empty() const;
    int size() const;
    T &front() { return queue_ptr[queue_front];};
    T &back(){return queue_ptr[queue_back];};
    int capacity() const { return queue_capacity;}
    void pop();
    void push(const T&);


    void print();

private:
    int queue_front=0;
    int queue_back=0;
    int queue_capacity=10;
    T *queue_ptr;
};
//constructor:

//operator:

template<typename T>
std::ostream &operator << (std::ostream &os, const ADT_array_queue<T> &obj)
{
    int location=obj.queue_front;

    while(location!=obj.queue_back)
    {
        os << obj.queue_ptr[location] <<" ";
        location=(location+1)%obj.queue_capacity;
    }

    return os;
}

//method:

template<typename T>
bool ADT_array_queue<T>::empty()const
{
    return (queue_front==queue_back);
}

template<typename T>
int ADT_array_queue<T>::size()const
{
    return (queue_back-queue_front+queue_capacity)%queue_capacity;
}


template<typename T>
void ADT_array_queue<T>::pop()
{
    if(queue_back==queue_front)
        throw "queue is empty";

   // int old_front=queue_front;

    queue_front=(queue_front+1)%queue_capacity;
}


template<typename T>
void ADT_array_queue<T>::push(const T &obj)
{
    if((queue_back+1)%queue_capacity==queue_front)
    {
        T *new_ptr=new T[2*queue_capacity];

        int loaction, i;

        for(i=0; i!=size(); i++)
        {
            loaction=(queue_front+i)%queue_capacity;

            new_ptr[i]=queue_ptr[loaction];
        }

        queue_front=0;

        queue_back=i-1;

        queue_capacity*=2;

        delete []queue_ptr;

        queue_ptr=new_ptr;
    }


    queue_ptr[queue_back]=obj;

    queue_back=(queue_back+1)%queue_capacity;
}

template<typename T>
void ADT_array_queue<T>::print()
{
    int i=0;
    while(i!=queue_capacity)
    {
        cout << queue_ptr[i] <<" ";

        i++;
    }
}

template<typename T>
class ADT_binary_tree_node;

template<typename T>
std::ostream &operator<< (std::ostream&, const ADT_binary_tree_node<T>&);

template<typename T>
class ADT_binary_tree_node
{

friend std::ostream &operator<< <T>(std::ostream&, const ADT_binary_tree_node&);

public:

    ADT_binary_tree_node(): left(nullptr), right(nullptr) {}
    ADT_binary_tree_node(const T &key):elm(key), left(nullptr), right(nullptr){}
    ADT_binary_tree_node(const T &key, ADT_binary_tree_node *theLeft, ADT_binary_tree_node *theRight):elm(key), left(theLeft), right(theRight){}

    T elm;
    ADT_binary_tree_node *left, *right;
};

//operator

template<typename T>
std::ostream &operator<< (std::ostream &os, const ADT_binary_tree_node<T> &obj)
{
    os <<obj.elm;
    return os;
}

//method:

template<typename T>
void print(ADT_binary_tree_node<T> *ptr) {cout << ptr->elm <<" ";}

template<typename T>
void dispose(ADT_binary_tree_node<T> *t) {delete t;}

template<typename T>
class ADT_binary_tree;

//template<typename T>
//std::ostream &operator<< (std::ostream&, const ADT_binary_tree<T>&);

template<typename T>
class ADT_binary_tree
{

    //typedef void(*visiter)(ADT_binary_tree_node<T>*);
friend void dispose<T>(ADT_binary_tree_node<T> *t);
//friend std::ostream &operator << <T> (std::ostream&, const ADT_binary_tree<T>&);

public:

    ADT_binary_tree(): root(nullptr), tree_size(0) {}

    ADT_binary_tree(vector<T> &obj):tree_size(obj.size())
    {
        create_tree(root, obj, 0);
    }

    ADT_binary_tree(ADT_binary_tree&);

    ~ADT_binary_tree() {deroot(root);}

    bool empty()const {return tree_size==0;}
    int size()const {return tree_size;}

    template<typename F>
    void pre_order(F visiter){preOrder(root, visiter);}

    void pre_order(void(*visiter)(ADT_binary_tree_node<T>*)){ preOrder(root, visiter);}

    template<typename F>
    void in_order(F visiter){inOrder(root, visiter);}

    void in_order(void(*visiter)(ADT_binary_tree_node<T>*)){ inOrder(root, visiter);}

    template<typename F>
    void post_order(F visiter){postOrder(root, visiter);}

    void post_order(void(*visiter)(ADT_binary_tree_node<T>*)){ postOrder(root, visiter);}

    template<typename F>
    void level_order(F visiter){levelOrder(root, visiter);}

    void level_order(void(*visiter)(ADT_binary_tree_node<T>*)){levelOrder(root, visiter);}

    int height();


    void deroot(ADT_binary_tree_node<T>*);

    void swap();//tree swap, swap left and right

    bool operator==(ADT_binary_tree&);

   // void print(std::ostream&);


private:
    ADT_binary_tree_node<T>* root;
    T elm;
    int tree_size;

    //static void (*visit)(ADT_binary_tree_node<T>*);

     template<typename F>
     void preOrder(ADT_binary_tree_node<T>* tree, F visiter);

     void preOrder(ADT_binary_tree_node<T>*, void(*visiter)(ADT_binary_tree_node<T>*));

     template<typename F>
     void inOrder(ADT_binary_tree_node<T>* tree, F visiter);

     void inOrder(ADT_binary_tree_node<T>*, void(*visiter)(ADT_binary_tree_node<T>*));

     template<typename F>
     void postOrder(ADT_binary_tree_node<T>* tree, F visiter);

     void postOrder(ADT_binary_tree_node<T>*, void(*visiter)(ADT_binary_tree_node<T>*));

     template<typename F>
     void levelOrder(ADT_binary_tree_node<T> *ptr, F visiter);

     void levelOrder(ADT_binary_tree_node<T> *ptr, void(*visiter)(ADT_binary_tree_node<T>*));

     //void dispose(ADT_binary_tree_node<T> *t) {delete t;}

     void create_tree(ADT_binary_tree_node<T> *&ptr, vector<T> &vec, int location);

     void copy_tree(ADT_binary_tree_node<T> *&ptr1, ADT_binary_tree_node<T> *&ptr2);

     bool tree_cmp(ADT_binary_tree_node<T> *ptr1, ADT_binary_tree_node<T> *ptr2);//tree compare

     void tree_swp(ADT_binary_tree_node<T> *&ptr);

     int tree_height(ADT_binary_tree_node<T> *ptr);

};

//constructor:

template<typename T>
ADT_binary_tree<T>::ADT_binary_tree(ADT_binary_tree<T> &obj)
{
    copy_tree(root, obj.root);
}

//operators:

template<typename T>
bool ADT_binary_tree<T>::operator==(ADT_binary_tree<T> &another)
{
    return tree_cmp(root, another.root);
}
//method:



template<typename T>
template<typename F>
void ADT_binary_tree<T>::preOrder(ADT_binary_tree_node<T>* tree, F visiter)
{

     if(tree!=nullptr)
    {

        visiter(tree);

        preOrder(tree->left, visiter);
        preOrder(tree->right, visiter);
    }

    else
        return;

}

template<typename T>
void ADT_binary_tree<T>::preOrder(ADT_binary_tree_node<T>* tree, void(*visiter)(ADT_binary_tree_node<T>*))
{

     if(tree!=nullptr)
    {

        visiter(tree);

        preOrder(tree->left, visiter);
        preOrder(tree->right, visiter);
    }

    else
        return;

}

template<typename T>
template<typename F>
void ADT_binary_tree<T>::inOrder(ADT_binary_tree_node<T>* tree , F visiter)
{
     if(tree!=nullptr)
    {
        inOrder(tree->left, visiter);

        visiter(tree);

        inOrder(tree->right, visiter);
    }
    else
        return;
}

template<typename T>
void ADT_binary_tree<T>::inOrder(ADT_binary_tree_node<T>* tree , void(*visiter)(ADT_binary_tree_node<T>*))
{
    if(tree!=nullptr)
    {
        inOrder(tree->left, visiter);

        visiter(tree);

        inOrder(tree->right, visiter);
    }
    else
        return;
}


template<typename T>
template<typename F>
void ADT_binary_tree<T>::postOrder(ADT_binary_tree_node<T>* tree,  F visiter)
{
    if(tree!=nullptr)
    {
        postOrder(tree->left, visiter);
        postOrder(tree->right, visiter);

        visiter(tree);
    }
    else
        return;
}

template<typename T>
void ADT_binary_tree<T>::postOrder(ADT_binary_tree_node<T>* tree, void(*visiter)(ADT_binary_tree_node<T>*))
{
    if(tree!=nullptr)
    {
        postOrder(tree->left, visiter);
        postOrder(tree->right, visiter);

        visiter(tree);
    }
    else
        return;
}

template<typename T>
template<typename F>
void ADT_binary_tree<T>::levelOrder(ADT_binary_tree_node<T> *ptr,  F visiter)
{
     deque<ADT_binary_tree_node<T>*> que;

     while(ptr!=nullptr)
     {
         visiter(ptr);

         if(ptr->left!=nullptr)
         que.push_back(ptr->left);

         if(ptr->right!=nullptr)
         que.push_back(ptr->right);

         if(!que.empty())
            ptr=que.front(),
            que.pop_front();
         else
            return;
     }
}

template<typename T>
void ADT_binary_tree<T>::levelOrder(ADT_binary_tree_node<T> *ptr,  void(*visiter)(ADT_binary_tree_node<T>*))
{
     deque<ADT_binary_tree_node<T>*> que;

     while(ptr!=nullptr)
     {
         visiter(ptr);

         if(ptr->left!=nullptr)
         que.push_back(ptr->left);

         if(ptr->right!=nullptr)
         que.push_back(ptr->right);

         if(!que.empty())
            ptr=que.front(),
            que.pop_front();
         else
            return;
     }
}

template<typename T>
void ADT_binary_tree<T>::create_tree(ADT_binary_tree_node<T> *&ptr, vector<T> &vec, int location)
{
    if(location>=vec.size())
        return;

    ptr=new ADT_binary_tree_node<T>(vec.at(location));

    create_tree(ptr->left, vec, 2*location+1);
    create_tree(ptr->right, vec, 2*location+2);
}

template<typename T>
void ADT_binary_tree<T>::copy_tree(ADT_binary_tree_node<T> *&ptr1, ADT_binary_tree_node<T> *&ptr2)
{
    //ptr2: tree being copied ptr1:a new tree

    if(ptr2!=nullptr)
    {
        ptr1=new ADT_binary_tree_node<T>(ptr2->elm);

        copy_tree(ptr1->left, ptr2->left);
        copy_tree(ptr1->right, ptr2->right);
    }
    else
        return;
}

template<typename T>
bool ADT_binary_tree<T>::tree_cmp(ADT_binary_tree_node<T> *ptr1, ADT_binary_tree_node<T> *ptr2)
{
    if(ptr1==nullptr && ptr2!=nullptr)
        return false;

    if(ptr2==nullptr && ptr1!=nullptr)
        return false;

    if(ptr1==nullptr)
        return true;

    if(ptr1->elm==ptr2->elm)
        return tree_cmp(ptr1->left, ptr2->left)&&tree_cmp(ptr1->right, ptr2->right);

    else
        return false;

}

template<typename T>
void ADT_binary_tree<T>::swap()
{
    tree_swp(root);
}

template<typename T>
int ADT_binary_tree<T>::height()
{
    return tree_height(root);
}

template<typename T>
void ADT_binary_tree<T>::tree_swp(ADT_binary_tree_node<T> *&ptr)
{
    if(ptr!=nullptr)
    {
        ADT_binary_tree_node<T> *the_left=ptr->left;
        ptr->left=ptr->right;
        ptr->right=the_left;

        tree_swp(ptr->left);
        tree_swp(ptr->right);
    }
    else
        return;
}

template<typename T>
int ADT_binary_tree<T>::tree_height(ADT_binary_tree_node<T> *ptr)
{
    if(ptr==nullptr)
        return 0;
    else
    {
        int the_left, the_right;

        the_left=tree_height(ptr->left);
        the_right=tree_height(ptr->right);

        if(the_left>the_right)
            return ++the_left;

        else
            return ++the_right;
    }
}

template<typename T>
void ADT_binary_tree<T>::deroot(ADT_binary_tree_node<T> *root)
{
        ADT_binary_tree_node<T> *tmp=root;

        if(tmp==nullptr)
            return;

        deroot(tmp->left);
        deroot(tmp->right);

        delete tmp;
}



template<typename T>
class ADT_max_priority_queue
{
public:

    virtual ~ADT_max_priority_queue() {}
    virtual bool empty() const =0;
    virtual int size() const=0;
    virtual const T &top()=0;
    virtual void pop();
    virtual void push(const T &elm)=0;

};

#endif // ADT_H_INCLUDED
