#include <iostream>
#include <stdlib.h> /* srand, rand */
#include <time.h>

using namespace std;

int main()
{
    int guessNumber,secretNumber;

    //Initialize
    srand(time(NULL));

    //Generate 1-10
    secretNumber=rand()%10 +1;

    //Ask the user to guess
    cout<<"Guess my number (1-10) :";

    do
    {
     cin>>guessNumber;
     if(guessNumber<secretNumber)
     {
        cout<<"The number is lower than that."<<endl;
     }

     if(guessNumber>secretNumber)
     {
         cout<<"Then number is greater than that."<<endl;
     }

    } while (guessNumber!=secretNumber);

    cout<<"Congratulation, you guessed the number and it is "<<secretNumber<<endl;


    return 0;
}
