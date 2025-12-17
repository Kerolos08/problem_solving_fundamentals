#include <iostream>
using namespace std;

int ReadPossitiveNumber (string msg)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while(number < 0);
    return number;
}

int FactorialOfNumber (int number)
{
    int f = 1;
    for (int i = number; i >= 1; i--)
    {
        f = f * i;
    }
    return f;
}

int main ()
{
    cout << FactorialOfNumber(ReadPossitiveNumber("Enter Possitive Number ?")) << endl;
    return 0;
}