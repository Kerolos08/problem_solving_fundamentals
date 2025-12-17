#include <iostream>
#include <string>
using namespace std;

int ReadNumber (string msg)
{
    int number;
    cout << msg << endl;
    cin >> number;
    return number;
}

int ReverseNumber (int number)
{
    int number2 = 0;
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        number2 = number2 * 10 + remainder;
    }
    return number2;
}


void PrintNumber(int number)
{
    int remainder = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        cout << remainder << endl;
    }
}


int main ()
{
    int number = ReadNumber("Enter A Number");
    PrintNumber(ReverseNumber(number));
    return 0;
}