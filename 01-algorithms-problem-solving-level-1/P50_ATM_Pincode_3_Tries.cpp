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
    int counter = 3;
    do{
        counter --;
        pincode = ReadPinCode();
        if (pincode == "1234")
        {
            return 1;
        }
        else
        {
            cout << "Wrong Pin, You Have " << counter << " more tries" << endl;
            system("color 4F");
        }
    }while (counter >= 1 && pincode != "1234");
    return 0;
}

int main()
{
    if (Login())
    {
        system("color 2F");
        cout << "\nYour Balance = 7500" << endl;
    }
    else
    {
        cout << "\nYour Card Has Been Blocked, Please Contact The Bank For Support" << endl;
    }
    return 0;
}