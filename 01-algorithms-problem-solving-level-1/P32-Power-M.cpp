#include <iostream>
using namespace std;

int ReadNumber ()
{
    int number;
    cout << "Enter A Number ?" << endl;
    cin >> number;
    return number;
}

int ReadN ()
{
    int N;
    cout << "How Many Times" << endl;
    cin >> N;
    return N;
}

int PowerToN (int N, int number)
{
    if ( N == 0)
    {
        return 1;
    }


    int result = 1;
    for (int i = 0; i < N; i++)
    {
        result = result * number; 
    }
    return result;
}

int main ()
{
    int Output = PowerToN(ReadN(), ReadNumber());
    cout << "Result = " << Output << endl;
    return 0;
}