#include <iostream>
using namespace std;

void ReadNumbers (int& num1, int& num2, int& num3)
{
    cout << "Enter first Number" << endl;
    cin >> num1;

    cout << "Enter Second Number" << endl;
    cin >> num2;

    cout << "Enter Third Number" << endl;
    cin >> num3;
}

int MaxOf2umbers (int num1, int num2, int num3)
{
if (num1 > num2 && num1 > num3)
return num1;

else if (num2 > num1 && num2 > num3)
return num2;

else
return num3;
}

void PrintMaxNumber (int max)
{
    cout << "\nThe Greatest Number Is: " << max << endl;
}

int main ()
{
    int num1;
    int num2;
    int num3;
    ReadNumbers(num1, num2, num3);
    PrintMaxNumber(MaxOf2umbers(num1, num2, num3));
    return 0;
}