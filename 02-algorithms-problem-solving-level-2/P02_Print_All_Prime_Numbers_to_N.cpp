#include <iostream>
#include <cmath>
using namespace std;

enum enPrimeOrNotPrime {Prime = 1, NotPrime = 2};

int ReadPossitiveNumber (string msg)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while(number < 0);
    return number;
}

enPrimeOrNotPrime CheckPrimeOrNot (int number)
{
    int M = round(number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (number % i == 0)
        {
            return enPrimeOrNotPrime::NotPrime;
        }
    }
    return enPrimeOrNotPrime::Prime;
}

void PrintPrimeToN (int number)
{
    cout << "\n";
    cout << "The Prime Numbers From " << 1 << " To " << number << " Are: " << endl;
    for (int i = 1; i <= number; i++)
    {
        if(CheckPrimeOrNot(i) == enPrimeOrNotPrime::Prime)
        {
            cout << i << endl;
        }
    }
}

int main ()
{
    PrintPrimeToN(ReadPossitiveNumber("Please Enter N"));
    return 0;
}