#include <iostream>
#include <string>
using namespace std;

int ReadNumber ()
{
    int number;
    cout << "Please Enter The Number" << endl;
    cin >> number;
    return number;
}

int CountDigitFrequency(int DigitToCheck, int Number)
{ 
    int FreqCount = 0,
    Remainder = 0; 
    while (Number > 0)
        {
        Remainder = Number % 10;
        Number = Number / 10;
        if (DigitToCheck == Remainder)
            {
                FreqCount++;
            }
        }
    return FreqCount;
} 


void PrintHowManyDigit (int number)
{
    cout << endl;
    int DigitFrequency = 0;
    for (int i = 0; i < 10; i++)
    {
    
        DigitFrequency = CountDigitFrequency(i, number);
        if (DigitFrequency > 0)
    {
        cout << "Digit " << i << " Frequency is : " << DigitFrequency << " Time(s)" << endl;
    }
    }
}


int main ()
{
    int number = ReadNumber();
    PrintHowManyDigit(number);
    return 0;
}