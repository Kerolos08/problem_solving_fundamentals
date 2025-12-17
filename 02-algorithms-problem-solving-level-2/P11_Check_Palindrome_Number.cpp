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

bool IsPalindrome (int number)
{
    return number == ReverseNumber(number);
}


int main ()
{
    if(IsPalindrome(ReadNumber("please type a number")))
    cout << "Number is Palindrome Number" << endl;
    else
    cout << "Number is Not a palindrome Number" << endl;

    return 0;
}