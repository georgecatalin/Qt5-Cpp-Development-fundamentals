#include <iostream>
#include "rectangle.h"
#include "Para.h"
#include "square.h"

using namespace std;

int main()
{
    Rectangle r;


    cout<<"The area of the rectangle is :"<<r.setArea()<<endl;
    cout<<"The area of the rectangle given by the second constructor is: "<<r.setArea()<<endl;

    Para p(30,30,30);
    cout<<"The volume of the piece is: "<<p.computeVolume()<<endl;

    Square s(40);
    cout<<"The area of the square is: "<<s.setArea()<<endl;

    return 0;
}
