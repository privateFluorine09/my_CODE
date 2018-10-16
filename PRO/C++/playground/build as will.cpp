#include<iostream>
#include<cstdlib>
#include<initializer_list>
#include<string>
#include<vector>
#include<utility>
#include<memory>

using namespace std;

//1:
template<typename Itr>
struct Printer
{
    ostream &operator() (const Itr &bi, const Itr &ei, ostream &os)const //bi means begin iterator
    {
        auto itr=bi;

        while(itr!=ei)
        {
            os<< *itr << " ";
            itr++;
        }

        return os;
    }
};

//2:
template<typename Itr>
ostream &print(const Itr &bi, const Itr &ei, ostream &os)
{
    auto itr=bi;

    while(itr!=ei)
    {
        os<< *itr << " ";
        itr++;
    }

    return os;
}

int main()
{
    vector<int> vec(12,12);

    Printer<vector<int>::iterator> the_printer;

    the_printer(vec.begin(), vec.end(), cout)<<endl;
    cout << sizeof(Printer<int>) << endl;//<<" " << sizeof(print)<< endl;

    return 0;
}

