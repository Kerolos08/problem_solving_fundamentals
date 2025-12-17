#include <iostream>
using namespace std;

int TotalSalesF ()
{
    int totalsales;
    cout << "How Much You Salled" << endl;
    cin >> totalsales;
    return totalsales;
}

float WhatIsThePercentage (int totalsales)
{
    if (totalsales >= 1000000)
    return 0.01;
    else if (totalsales >= 500000 && totalsales <= 1000000)
    return 0.02;
    else if (totalsales >= 100000 && totalsales <= 500000)
    return 0.03;
    else if (totalsales >= 50000 && totalsales <= 100000)
    return 0.05;
    else 
    return 0.00;
}

float CalculateCommission (int totalsales)
{
    return WhatIsThePercentage(totalsales) * totalsales;
}

int main ()
{
    int totalsales = TotalSalesF();
    cout << "Your Percentage On your Sales Is: " << WhatIsThePercentage(totalsales) << endl;
    cout << "Your Total Commission Duo To Your Sales Is: " << CalculateCommission(totalsales) << endl;
    return 0;
}