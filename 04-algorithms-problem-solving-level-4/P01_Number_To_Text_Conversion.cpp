#include <iostream>
using namespace std;

int ReadNumber (string msg)
{
    int number;
    cout << msg;
    cin >> number;
    return number;
}

string NumberToString (int Number)
{
    if (Number >= 0 && Number <= 19)
    {
        string TextNumbers[20] = {" ", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
                                    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        return TextNumbers[Number] + " ";
    }

    if (Number >= 20 && Number <= 99)
    {
        string TextNumbers[] = {" ", " ", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
        return TextNumbers[Number / 10] + " " + NumberToString(Number % 10);
    }

    if (Number >= 100 && Number <= 199)
    {
        return "one hundred " + NumberToString(Number % 100);
    }

    if (Number >= 200 && Number <= 999)
    {
        return (NumberToString(Number / 100) + "hundred " + NumberToString(Number % 100));
    }

    if (Number >= 1000 && Number <= 1999)
    {
        return "one thousand " + NumberToString(Number % 1000);
    }

    if (Number >= 2000 && Number <= 999999)
    {
        return (NumberToString(Number / 1000) + "thousands " + NumberToString(Number % 1000));
    }

    if (Number >= 1000000 && Number <= 1999999)
    {
        return "one million " + NumberToString(Number % 1000000);
    }

    if (Number >= 2000000 && Number <= 999999999)
    {
        return (NumberToString(Number / 1000000) + "millions " + NumberToString(Number % 1000000));
    }

    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "one billion " + NumberToString(Number % 1000000000);
    }

    if (Number >= 2000000000 && Number <= 999999999999)
    {
        return (NumberToString(Number / 1000000000) + "billion " + NumberToString(Number % 1000000000));
    }


    return " ";
}


int main()
{
    int number = ReadNumber("Please Enter a Number? ");
    cout << NumberToString(number);
    return 0;
}