#include <iostream>
using namespace std;

void ReadNumbers (int& num1, int& num2)
{
    cout << "Enter first Number" << endl;
    cin >> num1;
    
    cout << "Enter Second Number" << endl;
    cin >> num2;
}

void PrintOriginal (int num1, int num2)
{
    cout << "\nFrist Number Is: " << num1 << endl;
    cout << "Second Number is: " << num2 << endl;
}

void SwapFunction_ (int& A, int& B)
{
    int TempNum = A;
    A = B;
    B = TempNum;
}

void PrintNewNumber (int num1, int num2)
{
    cout << "\nFrist Number Is: " << num1 << endl;
    cout << "Second Number is: " << num2 << endl;
}

int main()
{
    int num1;
    int num2;
    ReadNumbers(num1,num2);
    PrintOriginal(num1, num2);
    SwapFunction_(num1, num2);
    PrintNewNumber(num1, num2);
    return 0;
}