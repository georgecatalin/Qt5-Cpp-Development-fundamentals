#include <iostream>
#include <string>

using namespace std;

int main()
{
    string hello="Hello World";
    int count=7;

    cout<<"The message is : "<<hello<<endl;
    cout<<"The count is : "<<count<<endl;

    cout<<"Size of int: "<< sizeof (int)<<" bytes"<<endl;
    cout<<"Size of char: "<< sizeof (char)<<" bytes"<<endl;
    cout<<"Size of bool: "<< sizeof (bool)<<" bytes"<<endl;
    cout<<"Size of float: "<< sizeof (float)<<" bytes"<<endl;
    cout<<"Size of double: "<< sizeof (double)<<" bytes"<<endl;

    unsigned int var1=-200;
    cout<<"Var1 is :"<<var1<<endl;


    return 0;
}
