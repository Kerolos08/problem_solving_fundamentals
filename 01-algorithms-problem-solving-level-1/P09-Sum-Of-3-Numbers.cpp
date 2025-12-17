#include <iostream>
using namespace std;

void ReadNums (int& num1, int& num2, int& num3)
{
    cout << "Type First Number" << endl;
    cin >> num1;
    cout << "Type Second Number" << endl;
    cin >> num2;
    cout << "Type Third Number" << endl;
    cin >> num3;
}

int SumOfThreeNumbers (int num1, int num2, int num3)
{
    return num1 + num2 + num3;
}

void PrintResult (int total)
{
    cout << "\n The Total Of Numbers is :" << total << endl;
}

int main ()
{
    int num1, num2, num3;
    ReadNums(num1, num2, num3);
    PrintResult(SumOfThreeNumbers(num1, num2, num3));
    return 0;
}