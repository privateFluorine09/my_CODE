#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED


#include<string>
#include<initializer_list>
#include<queue>
#include<deque>
#include<vector>
#include<utility>
#include<functional>

using namespace std;

//for C++11 only


//This code is totally crap and shit, needs time to improve. //20181012


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
    ADT_array_list(int cap): list_capacity(cap)
    {
        elm_ptr=new T [cap];
    };
    ADT_array_list(int cap, const T &elm): list_capacity(cap), list_size(cap), elm_ptr(new T [cap])
    {
        int i=0;
        while(i!=cap)elm_ptr[i]=elm,i++;
    };
    ADT_array_list(const std::vector<T> &);
    ~ADT_array_list()
    {
        delete [] elm_ptr;
    };

    //operators:


    const T &operator[](int)const;
    T &operator[](int);

    //methods:

    T &list_at(int index);
    const T &list_at(int index) const;
    T &list_forward() const
    {
        return *elm_ptr;
    };
    int size() const
    {
        return list_size;
    };
    int capacity() const
    {
        return list_capacity;
    };
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
    ADT_chain_node(const T &elm): elm(elm) {};
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

    iterator begin()
    {
        return iterator(head_node);
    }

    bool empty() const
    {
        return list_size==0;
    }
    int size() const
    {
        ;
        return list_size;
    }
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
    bool check_index(int index)
    {
        return (index>=0 && index<list_size);
    }
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
    iterator(ADT_chain_node<T> *Node=nullptr):node(Node) {};

    T& operator*() const
    {
        return node->elm;
    };
    T* operator->() const
    {
        return &node->elm;
    };

    iterator &operator++()
    {
        node=node->next;
        return *this;
    };
    iterator &operator++(int)
    {
        iterator old=*this;
        node=node->next ;
        return old;
    };

    bool operator!=(const iterator right) const
    {
        return node!=right.node;
    }
    bool operator==(const iterator right) const
    {
        return node==right.node;
    }

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
    bool empty() const
    {
        return std::vector<T>::empty();
    };
    int size() const
    {
        return std::vector<T>::size();
    };
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

//stack

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
    ADT_array_stack(int capacity): stack_capacity(capacity)
    {
        stc_ptr=new T[capacity];
    };
    ADT_array_stack(vector<T>&);
    ~ADT_array_stack()
    {
        delete stc_ptr;
    };

    bool empty() const
    {
        return (stack_size==0);
    };
    int size() const
    {
        return stack_size;
    };
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
};*/  //not enough time to complete

//queue:

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
    ADT_array_queue(int cap):queue_capacity(cap)
    {
        queue_ptr=new T[cap];
    }
    ~ADT_array_queue()
    {
        delete []queue_ptr;
    }

    bool empty() const;
    int size() const;
    T &front()
    {
        return queue_ptr[queue_front];
    };
    T &back()
    {
        return queue_ptr[queue_back];
    };
    int capacity() const
    {
        return queue_capacity;
    }
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
    ADT_binary_tree_node(const T &key):elm(key), left(nullptr), right(nullptr) {}
    ADT_binary_tree_node(const T &key, ADT_binary_tree_node *theLeft, ADT_binary_tree_node *theRight):elm(key), left(theLeft), right(theRight) {}

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
void print(ADT_binary_tree_node<T> *ptr)
{
    cout << ptr->elm <<" ";
}

template<typename T>
void dispose(ADT_binary_tree_node<T> *t)
{
    delete t;
}

template<typename T>
class ADT_binary_tree;

//template<typename T>
//std::ostream &operator<< (std::ostream&, const ADT_binary_tree<T>&);

//binary tree:

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

    ADT_binary_tree(ADT_binary_tree_node<T> *ptr): root(ptr), tree_size(1) {}

    ~ADT_binary_tree()
    {
        deroot(root);
    }

    bool empty()const
    {
        return tree_size==0;
    }
    int size()const
    {
        return tree_size;
    }

    template<typename F>
    void pre_order(F visiter)
    {
        preOrder(root, visiter);
    }

    void pre_order(void(*visiter)(ADT_binary_tree_node<T>*))
    {
        preOrder(root, visiter);
    }

    template<typename F>
    void in_order(F visiter)
    {
        inOrder(root, visiter);
    }

    void in_order(void(*visiter)(ADT_binary_tree_node<T>*))
    {
        inOrder(root, visiter);
    }

    template<typename F>
    void post_order(F visiter)
    {
        postOrder(root, visiter);
    }

    void post_order(void(*visiter)(ADT_binary_tree_node<T>*))
    {
        postOrder(root, visiter);
    }

    template<typename F>
    void level_order(F visiter)
    {
        levelOrder(root, visiter);
    }

    void level_order(void(*visiter)(ADT_binary_tree_node<T>*))
    {
        levelOrder(root, visiter);
    }

    int height() const;

    //int size() const { return tree_size;};


    void deroot(ADT_binary_tree_node<T>*);

    void swap();//tree swap, swap left and right

    bool operator==(ADT_binary_tree&);

    // void print(std::ostream&);


protected:
    ADT_binary_tree_node<T>* root=nullptr;
    int tree_size=0;

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

    tree_size=obj.tree_size;
}

//operators:

template<typename T>
bool ADT_binary_tree<T>::operator==(ADT_binary_tree<T> &another)
{
    if(tree_size!=another.tree_size)
        return false;
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
void ADT_binary_tree<T>::inOrder(ADT_binary_tree_node<T>* tree, F visiter)
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
void ADT_binary_tree<T>::inOrder(ADT_binary_tree_node<T>* tree, void(*visiter)(ADT_binary_tree_node<T>*))
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

    tree_size++;

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
int ADT_binary_tree<T>::height() const
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


//max_priority_queue

template<typename T>
class ADT_max_priority_queue
{
public:

    virtual ~ADT_max_priority_queue() {}
    virtual bool empty() const =0;
    virtual int size() const=0;
    virtual const T &top()const=0;
    virtual void pop()=0;
    virtual void push(const T &elm)=0;

};

template<typename T>
class ADT_max_heap;

template<typename T>
std::ostream &operator<< (std::ostream&, const ADT_max_heap<T>&);

template<typename T>
class ADT_max_heap: public ADT_max_priority_queue<T>
{

    friend std::ostream &operator<< <T> (std::ostream &os, const ADT_max_heap<T> &obj);

public:
    ADT_max_heap()=default;
    ADT_max_heap(const initializer_list<T> &lst);
    ~ADT_max_heap()
    {
        delete [] heap_ptr;
    }

    bool empty() const
    {
        return (heap_size==0);
    }
    int size() const
    {
        return heap_size;
    }
    const T &top() const
    {
        return heap_ptr[0];
    }
    T pop();
    void push(const T &elm);

private:
    int heap_size=0;
    T *heap_ptr=nullptr;
    int heap_capacity=0;

    void max_heapify(int i);
};

//constructor:

template<typename T>
ADT_max_heap<T>::ADT_max_heap(const initializer_list<T> &lst): heap_size(lst.size()), heap_capacity(2*lst.size())
{
    heap_ptr=new T[2*lst.size()];

    typename initializer_list<T>::iterator itr=lst.begin();
    int i=0;

    while(itr!=lst.end())
    {
        heap_ptr[i]=*itr;
        itr++, i++;
    }

    for(int j=heap_size/2-1; j>=0; j--)
        max_heapify(j);
}

//operator:

template<typename T>
std::ostream &operator<< (std::ostream &os, const ADT_max_heap<T> &obj)
{
    int i=0;

    while(i!=obj.heap_size)
    {
        os << obj.heap_ptr[i] <<" ";
        i++;
    }

    return os;
}

//method:
template<typename T>
void ADT_max_heap<T>::max_heapify(int i)
{

    if(i<0 || i>=heap_size)
        throw "illegal index";

    int _left=2*i+1;
    int _right=2*i+2;
    int _largest;

    if(_left<heap_size && heap_ptr[_left]>heap_ptr[i])
        _largest=_left;
    else _largest=i;

    if(_right<heap_size && heap_ptr[_right]>heap_ptr[_largest])
        _largest=_right;

    if(_largest!=i)
    {
        T store=heap_ptr[i];
        heap_ptr[i]=heap_ptr[_largest];
        heap_ptr[_largest]=store;
        max_heapify(_largest);
    }
}

template<typename T>
void ADT_max_heap<T>::push(const T &elm)
{
    if(heap_size+1==heap_capacity)
    {
        T *ptr1=heap_ptr;

        heap_ptr=new T[2*heap_capacity];

        //heap_size++;
        heap_capacity*=2;

        for(int i=0; i!=heap_size; i++)
            heap_ptr[i]=ptr1[i];
    }

    int current=++heap_size;

    while(current!=0 && heap_ptr[(current-1)/2] < elm)
    {
        heap_ptr[current]=heap_ptr[(current-1)/2];
        current=(current-1)/2;

    }

    heap_ptr[current]=elm;
}

template<typename T>
void ADT_max_heap<T>::pop()
{
    if(heap_size==0)
        throw "Empty queue.";

    T lastElm=heap_ptr[--heap_size];

    int current=0, child=1;

    while(child < heap_size)
    {
        if(child<heap_size-1 && heap_ptr[child]< heap_ptr[child+1])
            child++;

        if(lastElm>=heap_ptr[child])
            break;

        heap_ptr[current]=heap_ptr[child];
        current=child;
        child=2*child+1;

    }

    heap_ptr[current]=lastElm;
}


//HBLT:


template<typename T>
class ADT_HBLT;  //height biased leftist tree

template<typename T>
class ADT_HBLT: public ADT_binary_tree<pair<T, int>>, public ADT_max_priority_queue<T>
{
    template<typename T1> using node=ADT_binary_tree_node<pair<T1, int>>;

public:

    ADT_HBLT(const initializer_list<T>&);
    ADT_HBLT(node<T> *the_node): ADT_binary_tree<pair<T, int>>(the_node) {}
    //ADT_HBlT(ADT_HBLT &obj): ADT_binary_tree<pair<T, int>>(obj) {}

    void meld(ADT_HBLT &);
    void push(const T &);
    void pop();
    bool empty() const
    {
        return ((this->root)==nullptr);
    }
    const T &top() const
    {
        return (this->root)->elm.first;
    }
    int size() const
    {
        return this->tree_size;
    }

private:
    void meld(node<T>*&,node<T>*&);
};

//constructor:

template<typename T>
ADT_HBLT<T>::ADT_HBLT(const initializer_list<T> &obj)
{
    typename initializer_list<T>::iterator itr=obj.begin();

    while(itr!=obj.end())
    {
        push(*itr);
        itr++;
    }
}

//method:

template<typename T>
void ADT_HBLT<T>::push(const T &obj)
{
    node<T> *new_node=new ADT_binary_tree_node<pair<T, int>>(make_pair(obj, 1));

    meld(this->root, new_node);

    this->tree_size++;
}

template<typename T>
void ADT_HBLT<T>::pop()
{
    this->tree_size--;
    meld(this->root->left, this->root->right);

    delete this->root;
    this->root=this->root->left;
}

template<typename T>
void ADT_HBLT<T>::meld(ADT_HBLT<T> &another)
{
    meld(this->root, another.root);

    this->tree_size+=another.tree_size;

    another.root=nullptr;
    another.tree_size=0;
}

template<typename T>
void ADT_HBLT<T>::meld(node<T> *&tree1, node<T> *&tree2)
{
    if(tree2==nullptr)
        return;

    if(tree1==nullptr)
    {
        tree1=tree2;
        return;
    }

    if(tree1->elm.first < tree2->elm.first) //pair.first is elm
    {
        auto store=tree1;
        tree1=tree2;
        tree2=store;
    }
    //let tree1->elm.first to be the maxima
    meld(tree1->right, tree2);

    if(tree1->left==nullptr)
    {
        tree1->left=tree1->right;
        tree1->right=nullptr;
        tree1->elm.second=1;                  //if tree->left is null
    }

    else
    {
        if( (tree1->left->elm).second < (tree1->right->elm).second )
        {
            auto store=tree1->left;
            tree1->left=tree1->right;
            tree1->right=store;                                 //if tree->left->second is lower
        }

        (tree1->elm).second=((tree1->right)->elm).second+1;
    }
}

//BS tree:

template<typename T1, typename T2>
class ADT_BS_tree_virtual: public ADT_binary_tree<pair<const T1, T2>>
{
public:

    virtual ~ADT_BS_tree_virtual();
    virtual void insert(const pair<const T1, T2>&)=0;
    virtual pair<const T1, T2> remove(const T1 &key)=0;
    virtual pair<const T1, T2> &search(const T1 &key) const=0;

};

template<typename KEY, typename VAL>
class ADT_BS_tree: public ADT_binary_tree<pair<const KEY, VAL>>
{
    template<typename K, typename I> using node=ADT_binary_tree_node<pair<const K, I>>;
    template<typename K, typename I> using tree=ADT_BS_tree<K, I>;

public:
    ADT_BS_tree()=default;
    //ADT_BS_tree(const vector<pair<const T1, T2>>)

    void insert(const pair<const KEY, VAL>&);
    void remove(const KEY);
    pair<const KEY, VAL> search(const KEY &key) const;
    pair<const KEY, VAL> min()const;
    pair<const KEY, VAL> max()const;

    //pair<const KEY, VAL> nil;

protected:
    const pair<const KEY, VAL> nil;

};


//constructors:

//operators:

//methods:
template<typename KEY, typename VAL>
void ADT_BS_tree<KEY, VAL>::insert(const pair<const KEY, VAL> &pr)
{
    this->tree_size++;

    if(this->root==nullptr)
    {
        node<KEY, VAL> *new_root=new ADT_binary_tree_node<pair<const KEY, VAL>>(pr);
        this->root=new_root;
        return;
    }

    node<KEY, VAL> *ptr, *p_ptr; //p_ptr means ptr's parent

    ptr=this->root, p_ptr=nullptr;

    while(ptr!=nullptr)
    {
        p_ptr=ptr;

        if(pr.first>(ptr->elm).first )
            ptr=ptr->right;
        else
        {
            if(pr.first==(ptr->elm).first)
            {
                (ptr->elm).second=pr.second;
                return;
            }

            else
                ptr=ptr->left;
        }
    }

    auto new_node=new ADT_binary_tree_node<pair<const KEY, VAL>>(pr);

    if(pr.first>(p_ptr->elm).first)
        p_ptr->right=new_node;
    else
        p_ptr->left=new_node;

}

template<typename KEY, typename VAL>
pair<const KEY, VAL> ADT_BS_tree<KEY, VAL>::search(const KEY &key) const
{
    node<KEY, VAL> *ptr=this->root;

    while(ptr!=nullptr)
    {
        if(key<(ptr->elm).first)
            ptr=ptr->left;
        else
        {
            if(key==(ptr->elm).first)
                return ptr->elm;

            else
                ptr=ptr->right;
        }
    }
//nothing find, return the nil:
    return nil;
}

template<typename KEY, typename VAL>
void ADT_BS_tree<KEY, VAL>::remove(const KEY the_key)
{
    //pair<const KEY, VAL> to_remove;
    node<KEY, VAL> *ptr, *p_ptr;
    ptr=this->root, p_ptr=nullptr;

    while(ptr!=nullptr && ptr->elm.first!=the_key)
    {
        p_ptr=ptr;

        if(ptr->elm.first<the_key)
        {
            ptr=ptr->right;
        }
        else
            ptr=ptr->left;
    }


    //if p_ptr has two children
    if(p_ptr->left!=nullptr && p_ptr->right!=nullptr)
    {
        node<KEY, VAL> *ptr2, *p_ptr2;
        ptr2=ptr->left, p_ptr2=nullptr;

        while(ptr2->right!=nullptr)
        {
            p_ptr2=ptr2;
            ptr2=ptr2->right;
        }

        node<KEY, VAL> *new_node= new node<KEY, VAL>(ptr2->elm, ptr->left, ptr->right);

        if(p_ptr==nullptr)
            this->root=new_node;

        else
        {
            if(p_ptr->left==ptr)
                p_ptr->left=new_node;
            else
                p_ptr->right=new_node;
        }
        delete ptr;

        if(p_ptr2==ptr)
            p_ptr=new_node;
        else
            p_ptr=p_ptr2;

        ptr=ptr2;
    }

    //successfully replaced ptr or ptr has no more than one child

    node<KEY, VAL> *ptr3;

    if(ptr->left!=nullptr)
        ptr3=ptr->left;
    else
        ptr3=ptr->right;

    if(ptr==this->root)
        this->root=ptr3;
    else
    {
        if(ptr==p_ptr->left)
            p_ptr->left=ptr3;
        else
            p_ptr->right=ptr3;
    }

    this->tree_size--;

    delete ptr;

    //return to_remove;
}

template<typename KEY, typename VAL>
pair<const KEY, VAL> ADT_BS_tree<KEY, VAL>::min()const
{
    node<KEY, VAL> *ptr=this->root;

    while(ptr->left!=nullptr)
    {
        ptr=ptr->left;
    }

    return ptr->elm;
}

template<typename KEY, typename VAL>
pair<const KEY, VAL> ADT_BS_tree<KEY, VAL>::max()const
{
    node<KEY, VAL> *ptr=this->root;

    while(ptr->right!=nullptr)
    {
        ptr=ptr->right;
    }

    return ptr->elm;
}

//start for RB tree??

//defination for nodes
template<typename T>
struct ADT_RBtree_node
{
    template<typename T1> using node=ADT_RBtree_node<T1>;

    ADT_RBtree_node()=default;
    ADT_RBtree_node(const bool &color): is_black(color) {}
    ADT_RBtree_node(const T &val, const bool &color): elm(val), is_black(color) {}
    ADT_RBtree_node(const T &val, const bool &color, node<T> *ptr1, node<T> *ptr2, node<T> *ptr3): elm(val), is_black(color), parent(ptr1), left(ptr2), right(ptr3) {}
    //parent: parent parameter , ptr2: left chid, ptr3: right child

    bool is_black=true;
    T elm;

    node<T> *parent=nullptr, *left=nullptr, *right=nullptr;
};


//defination for the tree


template<typename T>
class ADT_RB_tree
{
public:

    template<typename T1> using node=ADT_RBtree_node<T1>;
    template<typename T2> using tree=ADT_RB_tree<T2>;

    ADT_RB_tree()=default;
    ~ADT_RB_tree()
    {
        unroot(root);
    }


    template<typename F>
    void pre_order(F visitor)
    {
        pre_order(visitor, root);
    }

    template<typename F>
    void in_order(F visitor)
    {
        in_order(visitor, root);
    }

    template<typename F>
    void post_order(F visitor)
    {
        post_order(visitor, root);
    }

    template<typename F>
    void level_order(F visitor);

    inline size_t size() const
    {
        return tree_size;
    }

    //in progress:right rotate, and fix_up



private:
    node<T> *root=nilptr;
    size_t tree_size=0;

    void unroot(node<T> *root);

    template<typename F>
    void pre_order(F visitor, node<T> *ptr);

    template<typename F>
    void in_order(F visitor, node<T> *ptr);

    template<typename F>
    void post_order(F visitor, node<T> *ptr);

    void left_rotate(node<T> *ptr);

    void right_rotate(node<T> *ptr);

    static const node<T> nil;

    static const node<T>* const nilptr;
};
//static member:
template<typename T>
const ADT_RBtree_node<T> ADT_RB_tree<T>::nil(true);

template<typename T>
const ADT_RBtree_node<T>* const ADT_RB_tree<T>::nilptr=&nil;

//operator:

//constructor:

//method:
template<typename T>
void ADT_RB_tree<T>::unroot(node<T> *the_root)
{
    unroot(the_root->left);
    unroot(the_root->right);

    if(the_root==nilptr)
        return;
    else
        delete the_root;
}

template<typename T>
template<typename F>
void ADT_RB_tree<T>::pre_order(F visitor, node<T> *ptr)
{
    if(ptr!=nilptr)
        visitor(ptr);//visitor must be a (node*)->returnType;
    else
        return;

    pre_order(visitor, ptr->left);
    pre_order(visitor, ptr->right);
}

template<typename T>
template<typename F>
void ADT_RB_tree<T>::in_order(F visitor, node<T> *ptr)
{
    if(ptr==nilptr)
        return;

    in_order(visitor, ptr->left);

    visitor(ptr);

    in_order(visitor, ptr->right);
}

template<typename T>
template<typename F>
void ADT_RB_tree<T>::post_order(F visitor, node<T> *ptr)
{
    if(ptr==nilptr)
        return;

    post_order(visitor, ptr->left);
    post_order(visitor, ptr->right);

    visitor(ptr);
}

template<typename T>
template<typename F>
void ADT_RB_tree<T>::level_order(F visiter)
{
    if(root==nilptr)
        return;

    queue<node<T>*> ptrQue;

    node<T> *cur=nilptr;

    ptrQue.push(root);

    while(!ptrQue.empty())
    {
        cur=ptrQue.front();

        visiter(cur);

        ptrQue.pop();

        if(cur->left!=nilptr)
            ptrQue.push(cur->left);

        if(cur->right!=nilptr)
            ptrQue.push(cur->right);
    }

}

template<typename T>
void ADT_RB_tree<T>::left_rotate(node<T> *ptr)
{
    if(ptr->right==nilptr)
        return;

    node<T> *lower=ptr->right;

    if(lower->left!=nilptr)
    {
        lower->left->parent=ptr;
    }

    ptr->right=lower->left;
    lower->parent=ptr->parent;

    if(ptr->parent==nilptr)
        root=lower;

    else
    {
        if(ptr==ptr->parent->left)
            ptr->parent->left=lower;
        else
            ptr->parent->right=lower;
    }

    lower->left=ptr;
    ptr->parent=lower;

}


//need to re-write
template<typename T>
void ADT_RB_tree<T>::right_rotate(node<T> *ptr)
{
    if(ptr->left==nilptr)
        return;

    node<T> *lower=ptr->left;

    ptr->left=lower->right
              lower->right=ptr;
    lower->parent=ptr->parent;

    if(ptr->parent!=nilptr)
    {
        if(ptr==ptr->parent->left)
            ptr->parent->left=lower;
        else
            ptr->parent->right=lower;

    }
    else
        root=lower;

    ptr->parent=lower;

}
#endif //
