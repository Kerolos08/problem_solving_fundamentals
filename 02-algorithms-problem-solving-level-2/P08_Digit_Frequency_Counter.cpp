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

void ReadNumber (int& number1, int& number2)
{
    cout << "Please Enter The Whole Number" << endl;
    cin >> number1;
    cout << "Please Enter The Doublicated Number" << endl;
    cin >> number2;
}

// void PrintDigits (string number)
// {
//     int length = number.size();
//     for (int i = length - 1; i >= 0; i--)
//     {
//         cout << number[i] << endl;
//     }
// }


int PrintDigitFrequency (int number, int number2)
{
    int remainder = 0;
    int counter = 0; 
    while (number > 0)
    {
        remainder = number % 10;
        number = number / 10;
        if (remainder == number2)
        {
            counter ++;
        }
    }
    return counter;
}


int main ()
{
    int number1, number2;
    ReadNumber(number1, number2);
    cout << endl;
    cout << "Degit " << number2 << " Frequency " << PrintDigitFrequency(number1, number2) << " Times" << endl;
    return 0;
}