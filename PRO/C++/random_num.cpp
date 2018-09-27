#include<iostream>
#include<string>
#include<ctime>
#include<random>
#include<cstdlib>

using namespace std;

int main()
{

    default_random_engine e(time(0));
    uniform_int_distribution<int> d(1, 11);
    string control;

    d(e);

    while(cin >> control)
    {
        if(control == "exit")
            break;

        cout << d(e) <<endl;
    }

    system("pause");

    return 0;
}
