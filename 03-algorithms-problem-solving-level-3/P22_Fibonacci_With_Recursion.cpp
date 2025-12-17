#include <iostream>
using namespace std;

void FibonacciWithRecursion (int number, int prev1, int prev2)
{
    int FebNumber = 0;
    if (number > 0)
    {
        FebNumber = prev1 + prev2;
        prev2 = prev1;
        prev1 = FebNumber;
        cout << FebNumber << " ";
        FibonacciWithRecursion(number - 1, prev1, prev2);
    }
}


int main ()
{
    int result = 0;
    FibonacciWithRecursion (10, 0, 1);
    return 0;
}