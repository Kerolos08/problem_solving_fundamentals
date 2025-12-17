#include <iostream>
using namespace std;

struct stPiggyBank {
    int Penny;
    int nickel;
    int dime;
    int quarter;
    int dollar;
};

stPiggyBank ReadPiggyBankContent ()
{
    stPiggyBank content;
    cout << "Please Enter How Many Pennies" << endl;
    cin >> content.Penny;
    cout << "Please Enter How Many Nickels" << endl;
    cin >> content.nickel;
    cout << "Plese Enter How Many Dimes" << endl;
    cin >> content.dime;
    cout << "Please Enter How Many Quarters" << endl;
    cin >> content.quarter;
    cout << "Please Enter How Many Dollars" << endl;
    cin >> content.dollar;

    return content;
}

int CalculateTotalPennies (stPiggyBank content)
{
    int totalpennies;
    totalpennies = 1 * content.Penny + 5 * content.nickel + 10 * content.dime + 25 * content.quarter + 100 * content.dollar;
    return totalpennies;
}

int main ()
{
    int totalpennies = CalculateTotalPennies(ReadPiggyBankContent());
    cout << "The Total Pennies Is: " << totalpennies << endl;
    cout << "The Total Dollars Is :" << (float)totalpennies / 100 << endl;
}