#include<iostream>
#include<string>
#include<ctime>
#include<random>
#include<cstdlib>

using namespace std;

extern string name_map(int n);

int main()
{

    default_random_engine e(time(0));
    uniform_int_distribution<int> d(1, 11);
    string control;

    d(e);

    cout <<"����exit�˳���������������������ǩȷ������ɱ��" <<endl<<endl;

    while(cin >> control)
    {
        if(control == "exit")
            break;

        cout <<"���ֳ�ǩ�����" << name_map(d(e)) <<endl<<endl;
        cout <<"����exit�˳���������������������ǩȷ������ɱ��" <<endl<<endl;
    }

    system("pause");

    return 0;
}
