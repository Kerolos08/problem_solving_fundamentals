#include <iostream>
using namespace std;

void PrintFibonacciUsingLoop (short number)
{
    int FebNumber = 0;
    int Prev2 = 0, Prev1 = 1;
    cout << "1\t";
    for (int i = 2; i <= number; i++)
    {
        FebNumber = Prev1 + Prev2;
        cout << FebNumber << "\t";
        Prev2 = Prev1;
        Prev1 = FebNumber;
    }
}

int main ()
{
    PrintFibonacciUsingLoop (10);
    return 0;
}