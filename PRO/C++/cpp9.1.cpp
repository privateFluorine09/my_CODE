#include<iostream>
#include<vector>

using namespace std;
typedef vector<int>::iterator itr;

bool function_find(itr, itr, int);

int main()
{
    vector<int> arr;
    int input1,input2;

    while( cin >> input1)
        arr.push_back(input1);



    cout << function_find(arr.begin(), arr.end(), 5) <<endl;

    return 0;
}

bool function_find(itr beGin, itr eNd, int inp)
{
    itr find_obj=beGin;
    while(find_obj!=eNd)
    {
        if(*find_obj==inp)
        return true;

        find_obj++;
    }

    return false;
}
