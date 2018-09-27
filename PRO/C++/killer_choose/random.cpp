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

    cout <<"输入exit退出程序，输入其他内容来抽签确定本局杀手" <<endl<<endl;

    while(cin >> control)
    {
        if(control == "exit")
            break;

        cout <<"本局抽签结果：" << name_map(d(e)) <<endl<<endl;
        cout <<"输入exit退出程序，输入其他内容来抽签确定本局杀手" <<endl<<endl;
    }

    system("pause");

    return 0;
}
