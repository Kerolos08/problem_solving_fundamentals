#include <iostream>
#include <string>
using namespace std;

// string ReadNumber ()
// {
//     string number;
//     cout << "Please Enter The Number" << endl;
//     cin >> number;
//     return number;
// }

int ReadNumber (string msg)
{
    int number;
    cout << msg << endl;
    cin >> number;
    return number;
}

// int SumOfDigits (string number)
// {
//     int length = number.size();
//     int sum = 0;
//     for (int i = length - 1; i >= 0; i--)
//     {
//     sum += number[i] - '0';
//     }
//     return sum;
// }


int SumOfDigits (int number)
{
    int remainder = 0;
    int sum = 0;
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        sum += remainder;
    }
    return sum;
}


int main ()
{
    int sum = SumOfDigits(ReadNumber("Please The Number"));
    cout << "The Sum Of Digits = " << sum << endl;
    return 0;
}