#include <iostream>
using namespace std;

int ReadPossitiveNumber (string msg)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while (number < 0);
    return number;
}

float CalculateHowManyMonths (int LoanAmount, int MonthsToPay)
{
    return (float) LoanAmount / MonthsToPay;
}

int main ()
{
    int LoanAmount = ReadPossitiveNumber("Please Enter Total Loan Amount");
    int MonthsToPay = ReadPossitiveNumber("Please Enter How Many Months");

    cout << "Monthly Installment = " << CalculateHowManyMonths(LoanAmount, MonthsToPay) << endl;

    return 0;
}