#include <iostream>
#include <cmath>
using namespace std;

enum enPerfectOrNot {Perfect = 1, NotPerfect = 2};

int ReadPossitiveNumber (string msg)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while(number < 0);
    return number;
}

// enPerfectOrNot CheckPerfectOrNot (int number)
// {
//     int sum = 0;
//     for (int i = 1; i < number; i++)
//     {
//         if (number % i == 0)
//         {
//             sum += i;
//         }
//     }
//         if (sum == number)
//             return enPerfectOrNot::Perfect;
//         else
//             return enPerfectOrNot::NotPerfect;
//     }

// void PrintPerfectOrNot (int number)
// {
//     switch (CheckPerfectOrNot(number))
//     {
//         case enPerfectOrNot::Perfect:
//         cout << "Number Is Perfect Number" << endl;
//         break;

//         case enPerfectOrNot::NotPerfect:
//         cout << "Number Is Not A Perfect Number" << endl;
//         break;
//     }

// }

bool IsPerfect (int number)
{
    int sum = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }
    return (sum == number);
}


void PrintResult (int number)
{
    if (IsPerfect(number))
    cout << number << " Is A Perfect Number" << endl;
    else
    cout << number << " Is A Not Perfect Number" << endl;
}


int main ()
{
    PrintResult(ReadPossitiveNumber("Please Enter A Posstive Number"));
    return 0;
}