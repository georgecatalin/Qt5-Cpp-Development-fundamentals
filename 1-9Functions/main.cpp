#include <iostream>

using namespace std;

void sayHi()
{
    cout << "Hello World!" << endl;
}

int sumation(int a,int b)
{
    return  a+b;
}

float sumation(float a, float b)
{
    return a+b;
}

double sumation(double a, double b)
{
    return a+b;
}

int main()
{
    sayHi();
    sayHi();
    sayHi();

    cout<<"the sum between two integers 3 + 6 is: "<<sumation(3,6)<<endl;
    cout<<"the sum between two floats 3.1 + 4.4 is: "<<sumation(3.3f,4.2f)<<endl;
    cout<<"the sum between two doubles 3.5 + 5.7 is: "<< sumation(3.5,5.7)<<endl;


    return 0;
}
