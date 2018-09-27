#include<iostream>
#include<algorithm>
#include<vector>
#include"print.h"
#include"my_algorithm.h"

template<typename T>
void alg_bubble_sort(T &obj);

int main()
{
     vector<int> dec;
     int result=0;
     int num;

     for(num=123; num!=num/10; num=num/10)
            dec.push_back(num%10);

     for(int i=dec.size()-1, q=1; i>=0; i--){
            result=q*dec[i];
            q=q*10;
        }

     cout << result <<endl;
     print(dec);

     sor
}

