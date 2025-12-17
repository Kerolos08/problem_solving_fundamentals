#include <iostream>
using namespace std;

void ReadNumbers (int& num1, int& num2)
{
    cout << "Enter first Number" << endl;
    cin >> num1;
    
    cout << "Enter Second Number" << endl;
    cin >> num2;
}

int MaxOf2umbers (int num1, int num2)
{
    if (num1 > num2)
    return num1;
    else
    return num2;
}

void PrintMaxNumber (int max)
{
    cout << "\nThe Greatest Number Is: " << max << endl;
}

int main ()
{
    int num1;
    int num2;
    ReadNumbers(num1, num2);
    PrintMaxNumber(MaxOf2umbers(num1, num2));
    return 0;
}