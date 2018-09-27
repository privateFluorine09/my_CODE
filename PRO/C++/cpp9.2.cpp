#include<iostream>
#include<vector>

using namespace std;
typedef vector<int>::iterator itr;

itr function_find(itr, itr, int);

int main()
{
    vector<int> arr;
    int input1,input2;

    while( cin >> input1)
        arr.push_back(input1);

    itr iterator1=function_find(arr.begin(), arr.end(), 5);

    cout << &*iterator1 <<" "  << *iterator1 << endl;

    return 0;
}

itr function_find(itr beGin, itr eNd, int inp)
{
    itr find_obj=beGin;
    while(find_obj!=eNd)
    {
        if(*find_obj==inp)
        return find_obj;

        find_obj++;
    }

    return eNd;
}
