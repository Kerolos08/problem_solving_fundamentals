#include <iostream>
using namespace std;

enum enEvenOrOdd {Even , Odd};

enum enWhatToDo {WAll, WEven, WOdd};

int ReadNumber ()
{
    int N;
    cout << "Enter The Number" << endl;
    cin >> N;
    return N;
}

enWhatToDo ReadWhatToDo ()
{
    string input;
    cout << " \nChoose What To Sum" << endl;
    cout << "All - Even - Odd" << endl;
    cin >> input;

    if (input == "All")
    return enWhatToDo::WAll;
    
    else if (input == "Even")
    return enWhatToDo::WEven;

    return enWhatToDo::WOdd;
}

enEvenOrOdd CheckNumber (int number)
{
    if (number % 2 == 0)
    return enEvenOrOdd::Even;
    else
    return enEvenOrOdd::Odd;
}

int SumRangeFrom1ToN (int N, enWhatToDo chooise)
{
    int sum = 0;

    if (chooise == enWhatToDo::WAll)
    {
        for (int i = 0; i <= N; i++)
        {
            sum += i;
        }
    }

    else if (chooise == enWhatToDo::WEven)
    {
        for (int i = 0; i <= N; i++)
        {
            if (CheckNumber(i) == enEvenOrOdd::Even)
            {
                sum += i;
            }
        }
    }

    else if(chooise == enWhatToDo::WOdd)
    {
        for (int i = 0; i <= N; i++)
        {
            if (CheckNumber(i) == enEvenOrOdd::Odd)
            {
                sum += i;
            }
        }
    }

    return sum;
}

int main ()
{
    cout << SumRangeFrom1ToN(ReadNumber(), ReadWhatToDo());
    return 0;
}