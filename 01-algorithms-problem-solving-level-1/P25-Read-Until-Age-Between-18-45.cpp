#include <iostream>
using namespace std;

int ReadAge ()
{
    int age;
    cout << "Enter Your Age" << endl;
    cin >> age;
    return age;
}

bool ValidateNumberInRange (int Number, int From, int To)
{
    return (Number >= From && Number <= To);
}

int ReadUntilAgeBetween(int From, int To)
{
    int age = 0;
    do
    {
    age = ReadAge();
    }while (!ValidateNumberInRange(age, From, To));

    return age;
}

void PrintResult (int age)
{
    cout << age << " Is Valid Age" << endl;
}

int main()
{
    PrintResult(ReadUntilAgeBetween(18,45));
    return 0;
}