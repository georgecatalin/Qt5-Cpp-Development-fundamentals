#include <iostream>

using namespace std;

class Rectangle
{
public:

    /* ***  how to define a function inside a class *** */
    void setWidth(int width)
    {
        this->width=width;
    }

    void setLength(int length);

    int setArea()
    {
        return this->width*this->length;
    }

private:
    int width;
    int length;
};

/* *** How to define a function  outside a class *** */
void Rectangle::setLength(int length)
{
    this->length=length;
}


int main()
{
    Rectangle r;
    r.setWidth(10);
    r.setLength(30);

    cout<<"The area of the rectangle is :"<<r.setArea()<<endl;

    return 0;
}
