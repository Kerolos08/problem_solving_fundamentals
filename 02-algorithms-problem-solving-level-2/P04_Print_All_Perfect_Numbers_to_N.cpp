#include <iostream>
#include <cmath>
using namespace std;

enum enPerfectOrNot {Perfect = 1, NotPerfect = 2};

int ReadPossitiveNumber (string msg)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while(number < 0);
    return number;
}


bool IsPerfect (int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return (sum == number);
}


void PrintPerfectNumbersToN (int number)
{
    for (int i = 1; i <= number; i++)
    {
        if(IsPerfect(i))
        {
            cout << i << endl;
        }
    }
}

int main ()
{
    PrintPerfectNumbersToN(ReadPossitiveNumber("Enter N"));
    return 0;
}