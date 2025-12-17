#include <iostream>
using namespace std;
struct stDriverInfo
{
    int Age;
    bool HasDrivingLicense;
    bool HasReccomendation;
};

stDriverInfo ReadInfo ()
{
    stDriverInfo info;

    cout << "Please Enter Your Age" << endl;
    cin >> info.Age;

    cout << "DO you Have A Driver License" << endl;
    cin >> info.HasDrivingLicense;

    cout << "DO you Have A Driver Reccomendation" << endl;
    cin >> info.HasReccomendation;

    return info;
}

bool IsAccepted (stDriverInfo info)
{
    if (info.HasReccomendation)
    {
        return true;
    }
    else
    {
        return (info.Age > 21 && info.HasDrivingLicense);
    }
}

void PrintResult (stDriverInfo info)
{
    if (IsAccepted(info))
    cout << "\n Hired" << endl;
    else
    cout << "\n Rejected" << endl;
}

int main()
{
    PrintResult(ReadInfo());
    return 0;
}
