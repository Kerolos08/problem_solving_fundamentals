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

int CalculateHowManyMonths (int LoanAmount, int MonthlyInstallment)
{
    return LoanAmount / MonthlyInstallment;
}

int main ()
{
    int LoanAmount = ReadPossitiveNumber("Please Enter Total Loan Amount");
    int MonthlyInstallment = ReadPossitiveNumber("Please Enter Monthly Install");

    cout << "Total Months To Pay = " << CalculateHowManyMonths(LoanAmount, MonthlyInstallment) << endl;

    return 0;
}