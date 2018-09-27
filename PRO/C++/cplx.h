#ifndef CPLX_H_INCLUDED
#define CPLX_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;

class cplx{

friend ostream &operator<<(ostream&, const cplx&);
//friend istream &operator>>(istream&, cplx&);
friend cplx operator+(const cplx&, const cplx&);
friend cplx operator-(const cplx&, const cplx&);


public:
    cplx()=default;
    cplx(double x, double y): axis_x(x), axis_y(y) {};
    cplx(const cplx&)=default;
    ~cplx()=default;

    cplx &operator+=(const cplx&);
    cplx &operator-=(const cplx&);

    double re()const{ return axis_x; }
    double im()const{ return axis_y; }





private:
    double axis_x=0;
    double axis_y=0;

};

ostream &operator<<(ostream &os, const cplx &output)
{
    if(output.axis_y > 0)
    {
        os << output.axis_x <<"+" << output.axis_y << "i" ;
        return os;
    }
    else
    if(output.axis_y == 0)
    {
        os << output.axis_x ;
        return os;
    }
    else
    {
        os << output.axis_x << output.axis_y << "i" ;
        return os;
    }
}

/*istream &operator>>(istream &is, cplx &z)
{
    string input;

    return is;
}*/

cplx &cplx::operator+=(const cplx &z)
{
    axis_x+=z.axis_x;
    axis_y+=z.axis_y;
    return *this;
}

cplx &cplx::operator-=(const cplx &z)
{
    axis_x-=z.axis_x;
    axis_y-=z.axis_y;
    return *this;
}

cplx operator+(const cplx &z1, const cplx &z2)
{
    cplx z3=z1;
    z3+=z2;
    return z3;
}

cplx operator-(const cplx &z1, const cplx &z2)
{
    cplx z3=z1;
    z3-=z2;
    return z3;
}



#endif // CPLX_H_INCLUDED
