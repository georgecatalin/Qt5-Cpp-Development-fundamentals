#ifndef PARA_H
#define PARA_H

#include "rectangle.h"

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

#endif // PARA_H
