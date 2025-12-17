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

void PrintResult (int age)
{
    if (ValidateNumberInRange(age, 18, 45))
    cout << age << " Is Valid Age" << endl;
    else 
    cout << age << " Is Invalid Age" << endl;
}

int main()
{
    PrintResult(ReadAge());
    return 0;
}