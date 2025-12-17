#include <iostream>
using namespace std;

enum enEvenOrOdd {Even , Odd};

int ReadNumber ()
{
    int N;
    cout << "Enter The Number" << endl;
    cin >> N;
    return N;
}

enEvenOrOdd CheckEvenOrOdd (int Number)
{
    if (Number % 2 == 0)
    return enEvenOrOdd::Even;
    else 
    return enEvenOrOdd::Odd;
}

int SumOfOddNumbersFrom1ToN_UsingForLoop (int N)
{
    cout << "\nSum Of Odd Numbers From 0 To N Using For Loop" << endl;
    int sum = 0;
    for (int i = 0; i <= N; i++)
    {
        if (CheckEvenOrOdd(i) == enEvenOrOdd::Even)
        sum += i;
    }
    return sum;
}

int SumOfOddNumbersFrom1ToN_UsingDoWhileLoop (int N)
{
    cout << "\nSum Of Odd Numbers From 0 To N Using Do While Loop" << endl;
    int counter = 0;
    int sum = 0;
    do{
    counter ++;
        if (CheckEvenOrOdd(counter) == enEvenOrOdd::Even)
        {
            sum += counter;
        }
    }while (counter < N);
    return sum;
}

int SumOfOddNumbersFrom1ToN_UsingWhileLoop (int N)
{
        cout << "\nSum Of Odd Numbers From 0 To N Using While Loop" << endl;
    int counter = 0;
    int sum = 0;
    while (counter < N)
    {
    counter ++;
    if (CheckEvenOrOdd(counter) == enEvenOrOdd::Even)
    {
        sum += counter;
    }
    }
    return sum;
}

int main ()
{
    int M = ReadNumber();
    cout << SumOfOddNumbersFrom1ToN_UsingDoWhileLoop(M) << endl;
    cout << SumOfOddNumbersFrom1ToN_UsingForLoop(M) << endl;
    cout << SumOfOddNumbersFrom1ToN_UsingWhileLoop(M) << endl;
    return 0;
}