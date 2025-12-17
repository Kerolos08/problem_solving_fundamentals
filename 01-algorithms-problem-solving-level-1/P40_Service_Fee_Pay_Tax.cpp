#include <iostream>
using namespace std;

float ReadPossitiveNumber (string msg)
{
    float number;
    do
    {
    cout << msg << endl;
    cin >> number;
    } while (number < 0);
    return number;
}

float CalculateBillAfterServices (float bill)
{
    bill = 1.1 * bill;
    bill = 1.16 * bill;
    return bill;
}


int main ()
{
    int totalbill = ReadPossitiveNumber("Please Enter Total Bill");

    cout << "Total Bill = " << totalbill << endl;
    cout << "Total Bill After Service And Sales Tax = " << CalculateBillAfterServices(totalbill) << endl;
    return 0;
}