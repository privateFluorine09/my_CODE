#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
class Cdateinfo{
public:
    Cdateinfo()=default;
    Cdateinfo(int m, int d, int y):
        month(m), day(d), year(y){}
    void date_reset(int, int, int);
    void date_get();

private:
    int day=1;
    int month=1;
    int year=2000;

};


#endif // DATE_H_INCLUDED
