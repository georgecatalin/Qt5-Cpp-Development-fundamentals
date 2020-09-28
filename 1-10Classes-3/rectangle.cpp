#include <rectangle.h>


/* *** How to define a function  outside a class *** */
void Rectangle::setLength(int length)
{
    this->length=length;
}

/* *** These are definitions of the constructors outside of the class *** */
Rectangle::Rectangle()
{
    clog<<"Default constructor was appealed."<<endl;
    this->width=5;
    this->length=5;
}

/*
Rectangle::Rectangle(int width, int length)
{
    clog<<"Custom constructor is appealed."<<endl;
    this->width=width;
    this->length=length;
}
*/

//Describe the constructor using an initializer list
Rectangle::Rectangle(int w, int l):width(w),length(l)
{
    clog<<"Custom constructor is appealed."<<endl;
}
