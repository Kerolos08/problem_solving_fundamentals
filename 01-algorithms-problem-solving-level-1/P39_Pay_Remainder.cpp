#include <iostream>
using namespace std;

int ReadPossitiveNumber(string msg)
{
    int number;
    do
    {
        cout << msg << endl;
        cin >> number;
    } while (number < 0);
    return number;
}

int CalculateRemainder(int number1, int number2)
{
    return number1 - number2;
}

int main()
{
    int totalbill = ReadPossitiveNumber("Please Enter The Total Bill Value");
    int cashpaid = ReadPossitiveNumber("Please Enter Cash Paid");

    cout << endl;
    cout << endl;

    cout << "Total Bill= " << totalbill << endl;
    cout << "Cash Paid = " << cashpaid << endl;

    cout << "******************************" << endl;
    cout << "Remainder = " << CalculateRemainder(cashpaid, totalbill) << endl;

    return 0;
}