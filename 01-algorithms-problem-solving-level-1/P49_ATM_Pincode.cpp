#include <iostream>
using namespace std;

string ReadPinCode ()
{
    string code;
    cout << "Please Enter Your Pin Code" << endl;
    cin >> code;
    return code;
}

bool Login()
{
    string pincode;
    do{
        pincode = ReadPinCode();
        if (pincode == "1234")
        {
            return 1;
        }
        else
        {
            cout << "Wrong Pin" << endl;
            system("color 4F");
        }
    }while (pincode != "1234");

    return false;
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour Balance = 7500" << endl;
    }
    return 0;
}