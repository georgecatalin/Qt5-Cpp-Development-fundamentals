#include <iostream>
#include <string>

using namespace std;

int main()
{
    //1. cout
    cout << "Hello World!" << endl;

    //2. cerr
    cerr<<"There was an error"<<endl;

    //3. clog
    clog<<"This is a log message"<<endl;

    //4. cin
    string name;

    cout<<"Please type in your firstname: ";
    cin>>name;

    cout<<"Your first name is : "<<name<<endl;

    return 0;
}
