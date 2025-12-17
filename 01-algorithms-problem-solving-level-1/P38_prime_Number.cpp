#include <iostream>
#include <string>
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

void PrintPrimeOrNot (int number)
{
    switch (CheckPrimeOrNot(number))
    {
    case enPrimeOrNotPrime::Prime:
    cout << "Number Is Prime" << endl;
    break;

    case enPrimeOrNotPrime::NotPrime:
    cout << "Number Is Not prime" << endl;
    break;
}
}

int main ()
{
    PrintPrimeOrNot(ReadPossitiveNumber("Please Enter A Possitive Number"));
    return 0;
}