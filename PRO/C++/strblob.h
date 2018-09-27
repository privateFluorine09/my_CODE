#ifndef STRBLOB_H_INCLUDED
#define STRBLOB_H_INCLUDED
#include<iostream>
#include<vector>
#include<memory>
#include<string>

using namespace std;


class strblob
{
friend int new_strblob::status();
public:
    strblob()=default;
    strblob(initializer_list<string> il):
        data(make_shared<vector<string>>(il)) {}
    strblob(unsigned n, string str):
        data(make_shared<vector<string>>(n, str) ) {}

    ~strblob()=default;

    string front() const{ return data->front() ;}
    string back() const{ return data->back() ;}



private:
    shared_ptr<vector<string>> data;

    int status2=0;
};

class new_strblob: public strblob
{

public:
    int t=0;
    int status() const {return status2;}



};


#endif // STRBLOB_H_INCLUDED
