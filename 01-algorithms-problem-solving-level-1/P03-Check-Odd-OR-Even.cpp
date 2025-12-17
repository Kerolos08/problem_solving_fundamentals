#include <iostream>
using namespace std;
enum enNumberType {Odd, Even};

int ReadNumber()
{
int num;
cout << "Please Enter A Number\n";
cin >> num;
return num;
}

enNumberType CheckNumberType(int num)
{
    int result = num % 2;
    if (result == 0)
    return enNumberType:: Even;
    else
    return enNumberType :: Odd;
}

void PrintNumberType (enNumberType NumberType)
{
if (NumberType == enNumberType :: Even)
    cout << "\n Number is Even. \n";    
else
    cout << "\n Number is Odd. \n";
}


int main()
{

PrintNumberType(CheckNumberType(ReadNumber()));
    return 0;
}


