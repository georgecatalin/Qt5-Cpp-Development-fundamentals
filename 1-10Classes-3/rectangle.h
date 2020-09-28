#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
using namespace std;

class Rectangle
{
public:

    /* *** This is a default constructor of the class *** */
    Rectangle();
    /* *** This is a custom constructor of the class *** */
    Rectangle(int width,int length);



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



#endif // RECTANGLE_H
