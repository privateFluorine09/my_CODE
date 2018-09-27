#ifndef CRECTANGLES1_H_INCLUDED
#define CRECTANGLES1_H_INCLUDED
#include<utility>
class CRectangle{
    public:
    CRectangle()=default;

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
    double area()const
    {return rectangle_a*rectangle_b ;}

    private:

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
{
    axis_x=a;
    axis_y=b;
}

#endif // CRECTANGLES1_H_INCLUDED
