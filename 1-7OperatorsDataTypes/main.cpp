#include <iostream>

using namespace std;

int main()
{
    int a=20;
    int b=7;

    cout<<"--------------Math operators-----------------"<<endl;
    cout<<"a+b = "<<a+b<<endl;
    cout<<"a-b= "<<a-b<<endl;
    cout<<"a*b= "<<a*b<<endl;
    cout<<"a/b= "<<a/b<<endl;
    cout<<"(float) a/b= "<<(float) a/b<<endl;
    cout<<"a%b = "<< a % b << endl;

    cout<<"---------------Logical operators---------------"<<endl;
    if(a>b)
    {
        cout<<"A is greater than B"<<endl;
    }
    else
    {
        cout<<"A is not greater than B"<<endl;
    }

   //Loop
    for(int i=0;i<20;i++)
    {
        cout<<"Hello, Alligator! "<<i<<endl;
    }

    //While
    int i=0;
    while (i<20)
    {
        cout<<"Hello, Alligator! "<<i<<endl;
        i++;
    }

    //Do while
     i=1;
    do
    {
     cout<<"Hello, Lion! "<<i<<endl;
     i++;
    } while (i<20);


    return 0;
}
