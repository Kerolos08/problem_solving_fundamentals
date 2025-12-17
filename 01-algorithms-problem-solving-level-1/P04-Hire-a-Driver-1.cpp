#include <iostream>
using namespace std;
struct stDriverInfo
{
    int Age;
    bool HasDrivingLicense;
};

stDriverInfo ReadInfo ()
{
    stDriverInfo info;

    cout << "Please Enter Your Age" << endl;
    cin >> info.Age;

    cout << "DO you Have A Driver License" << endl;
    cin >> info.HasDrivingLicense;

    return info;
}

bool IsAccepted (stDriverInfo info)
{
    return (info.Age > 21 && info.HasDrivingLicense);
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
