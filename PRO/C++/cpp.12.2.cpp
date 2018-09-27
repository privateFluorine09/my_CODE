#include<iostream>
#include<cstdlib>
#include<memory>
#include<vector>

using namespace std;

shared_ptr<vector<int>> func();
void input(shared_ptr<vector<int>>);
void output(shared_ptr<vector<int>>);

int main()
{
    shared_ptr<vector<int>> ptr=func();

    input(ptr);
    output(ptr);

    system("pause");

    return 0;
}

shared_ptr<vector<int>> func()
{
    return shared_ptr<vector<int>>(new vector<int>);
}


void input(shared_ptr<vector<int>> ptr)
{
    int in;
    while(cin >> in)
        ptr->push_back(in);
}



void output(shared_ptr<vector<int>> ptr)
{
    vector<int>::iterator itr=ptr->begin();

    while(itr != ptr->end() )
    {
        cout << *itr <<" ";
        itr++;
    }
}
