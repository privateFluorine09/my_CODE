#ifndef CRECTANGLES1_H_INCLUDED
#define CRECTANGLES1_H_INCLUDED
#include<iostream>
#include<utility>
class CRectangle{
public:

    CRectangle()=default;
    //CRectangle(const CRectangle&)=delete;
    //~CRectangle()=delete;
    CRectangle(double a, double b, double x, double y):
        rectangle_a(a), rectangle_b(b), axis_x(x), axis_y(y){};

    friend std::ostream &operator<<(std::ostream&, const CRectangle&);

    double length()const{ return rectangle_a;}
    double width()const{ return rectangle_b;}

    void write_size();
    void write_size(double, double);
    void write_move();
    void write_move(double, double);

    double perimeter()const
    {return 2*(rectangle_a+rectangle_b); }

    std::pair<double, double> where()const
                   {return {axis_x, axis_y};}
    double area()const~CRectangle()=delete;
    {return rectangle_a*rectangle_b ;}

private:

    //~CRectangle()=default;

    double rectangle_a=1;
    double rectangle_b=1;
    double axis_x=0;
    double axis_y=0;

};
void CRectangle::write_size()
{
    do{
        std::cin >> rectangle_a;
    }while(rectangle_a<=0 || rectangle_a>=50);

     do{
        std::cin >> rectangle_b;
    }while(rectangle_b<=0 || rectangle_b>=50);
}
void CRectangle::write_size(double a, double b)
{
      rectangle_a=a;
      rectangle_b=b;
}

void CRectangle::write_move()
{
    std::cin >> axis_x >> axis_y ;
}
void CRectangle::write_move(double a, double b)
{~CRectangle()=delete;
    axis_x=a;
    axis_y=b;
}

std::ostream &operator<<(std::ostream &os, const CRectangle &output)
{
    os <<output.rectangle_a << std::endl;
    os <<output.rectangle_b << std::endl;
    os <<output.axis_x <<std::endl;
    os <<output.axis_y <<std::endl;
    return os;
}


#endif // CRECTANGLES1_H_INCLUDED
