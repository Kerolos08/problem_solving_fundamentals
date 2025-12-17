#include <iostream>
using namespace std;

int ReadNumber (string msg)
{
    int number;
    cout << msg << endl;
    cin >> number;
    return number;
}

int SumNumbers ()
{
    int sum = 0, counter = 1, number;

    do{
    number = ReadNumber ("Please Enter Number " + to_string(counter));

        if (number == -99)
    {
        break;
    }

        sum += number;
        counter ++;
    
    }while (number != -99);

    return sum;
}

int main () 
{
    int result = SumNumbers();
    cout << "Sum Of All Your Numbers = " << result << endl;
    return 0;
}