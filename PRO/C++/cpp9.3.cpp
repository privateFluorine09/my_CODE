#include<iostream>
#include<vector>
#include<list>
using namespace std;

typedef vector<int>::iterator itr;
bool cmp(itr, itr, itr, itr);


int main()
{
    vector<int> arr1{5,6,6,7,8,9},arr2;
    int input;

    while(cin >> input)
        arr2.push_back(input);

    cout << cmp(arr1.begin(),arr1.end(),
                arr2.begin(), arr2.end()) << endl;

    return 0;
}
bool cmp(itr it1, itr it2, itr it3, itr it4)
{
    itr obj1=it1,obj2=it3;
    while(obj1!=it2)
    {
        if(*obj1 != *obj2)
            return false ;
        obj1++,obj2++;
    }
    return ( (it4-it3)==(it2-it1) )? true: false ;
}
