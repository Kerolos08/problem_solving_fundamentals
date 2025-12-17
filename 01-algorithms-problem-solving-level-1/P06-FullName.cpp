#include <iostream>
using namespace std;

struct stInfo
{
    string FirstName;
    string LastName;
};

stInfo ReadName ()
{
    stInfo info;

    cout << "Enter Your Frist Name" << endl;
    cin >> info.FirstName;

    cout << "Enter your Last Name" << endl;
    cin >> info.LastName;

    return info;
}

string GetFullName (stInfo info, bool reversed)
{
    string FullName;

        if (reversed)
        FullName = info.LastName + " " + info.FirstName;
        else
        FullName = info.FirstName + " " + info.LastName;

    return FullName;
}

void PrintFullName (string FullName)
{
    cout << "\nYour Full Name Is: " << FullName << endl;
}

int main ()
{
    PrintFullName(GetFullName(ReadName(),true));
    return 0;
}
