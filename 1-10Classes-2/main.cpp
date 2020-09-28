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

class Para
{
   public:
    Para(int w,int l,int h):r(w,l),height(h)
    {
        clog<<"The constructor of the Para Class has been appealed"<<endl;

        /* *** use this for setting up the private members if you wish without initialization list *** */
        //this->r.setWidth(w);
        //this->r.setLength(l);
        //this->height=h;

    }

    int computeVolume()
    {
        return r.setArea()*height;
    }

private:
    Rectangle r;
    int height;
};


int main()
{
    Rectangle r;


    cout<<"The area of the rectangle is :"<<r.setArea()<<endl;
    cout<<"The area of the rectangle given by the second constructor is: "<<r.setArea()<<endl;

    Para p(30,30,30);
    cout<<"The volume of the piece is: "<<p.computeVolume()<<endl;

    return 0;
}
