#include <iostream>

using namespace std;

int main()
{

    /* *** Lambda functions in C++
     * [CAPTURE LIST] (PARAMETER LIST) -> return_type {FUNCTION BODY}
     * */

    /*
     * Method 1: name the lambda function and call it by name later
    auto myfunction=[]()
    {
        cout << "Hello World!" << endl;
    };

    myfunction();
    */

    /* *** Method 2: call the lambda function directly after definition *** */
    []()
    {
        cout<<"Hello World!"<<endl;
    }();


    /* *** Define a lambda function that takes parameters *** */
    [](int a, int b)
    {
        cout<<"a + b= "<<a+b<<endl;
    }(5,6);


    /* *** Define a lambda function that returns something *** */
    /* *** assign the value to an integer *** */
    int sum= [](int a, int b)->int
    {
        return a+b;
    }(5,6);

    cout<<"The sum of two numbers is "<<sum<<endl;

    /* *** Define a lambda function that returns something *** */
    /* *** Use the lambda function right away *** */


    cout<<"The sum of two numbers is :"<<[](int a,int b)->int
    {
        return  a+b;
    }(6,6)<<endl;

    //Capture lists
    int a=7;
    int b=4;

    [a,b]()
    {
        cout<<"a is :"<<a<<endl;
        cout<<"b is :"<<b<<endl;
    }();



    // Capturing by value to a lambda function

    cout<<"---------------------Capturing by value to a lambda function----------------------------------"<<endl<<endl;
    int c=42;
    auto myfunction=[c]()
    {
        cout<<"The value of inner c is: "<<c<<endl;
    };

    for (int i=0;i<5;i++) {
        cout<<"The value of outer c is "<<c<<endl;
        myfunction();
        c=c+1;

    }

    //Capturing by reference
    cout<<"---------------------Capturing by reference to a lambda function----------------------------------"<<endl<<endl;

    int d=18;
    auto myfunction_capture_by_reference=[&d]()
    {
        cout<<"The value of inner d is : "<<d<<endl;

    };

    for (int i=0;i<5;i++)
    {
        cout<<"The value of outer d is "<<d<<endl;
        myfunction_capture_by_reference();
        d=d+1;
    }

  cout<<"---------------------Capturing everything by value to a lambda function----------------------------------"<<endl<<endl;
    //Capturing everything by value
    int e=9;
    int f=41;

    auto myfunction_bibbex=[=]()
    {
        cout<<"The value of inner e is "<<e<<endl;
        cout<<"The value of inner f is "<<f<<endl;
    };

    for (int i=0;i<10;i++)
    {
        cout<<"The value of outer e is "<<e<<endl; //by passing by value it creates a copy
        cout<<"The value of outer f is "<<f<<endl;

        myfunction_bibbex();

        e=e+1;
        f=f+1;

    }



    cout<<"---------------------Capturing everything by reference to a lambda function----------------------------------"<<endl<<endl;
    //Capturing everything by reference

    int g=31;
    int h=43;

    auto myfunc_geo=[&]()
    {
        cout<<"The value of inner g is "<<g<<endl;
        cout<<"The value of inner h is "<<h<<endl;
    };

    for (int i=0;i<10;i++)
    {
        cout<<"The value of outer g is "<<g<<endl; //by passing by value it handles the memory location, thus the actual variable
        cout<<"The value of outer h is "<<h<<endl;

        myfunc_geo();

        g=g+1;
        h=h+1;

    }



       return 0;
}
