#include<iostream>
#include<memory>
#include<vector>

using namespace std;

vector<int> *fun1();
void input(vector<int>*);
void output(vector<int>*);

int main()
{
    vector<int> *ptr=fun1();

    input(ptr);
    output(ptr);

    delete ptr;

    ptr=nullptr;

    return 0;
}

vector<int> *fun1()
{
    return new vector<int>;
}

void input(vector<int> *p)
{
    int in;
    while(cin >> in)
        p->push_back(in);
}

void output(vector<int> *p)
{
    vector<int>::iterator itr=p->begin();

    while(itr != p->end() )
    {
        cout << *itr <<" ";
        itr++;
    }
}
