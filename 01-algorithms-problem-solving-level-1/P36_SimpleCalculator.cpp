#include <iostream>
using namespace std;

enum enOperationType {Add = '+', Subtract = '-', Multiply = '*', Divide = '/'};

enOperationType ReadTheOperation ()
{
    char operationtype;
    cout << "Choose The Operation You Want To Do ??" << endl;
    cout << "( + , - , * , / ) ?? " << endl;
    cin >> operationtype;
    return (enOperationType) operationtype;
}

float ReadNumber (string msg)
{
    float number;
    cout << msg << endl;
    cin >> number;
    return number;
}

float Calculate (float number1, float number2, enOperationType operationtype)
{
    switch (operationtype)
    {
        case enOperationType::Add:
        return number1 + number2;
        case enOperationType::Subtract:
        return number1 - number2;
        case enOperationType::Multiply:
        return number1 * number2;
        case enOperationType::Divide:
        return number1 / number2;
        default:
        return number1 + number2;
    }
}

int main ()
{
    float number1 = ReadNumber("Please Enter Number 1 ???");
    float number2 = ReadNumber("Please Enter Number 2 ???");

    enOperationType operator_ = ReadTheOperation();

    float result = Calculate(number1, number2, operator_);
    cout << "\n The Result Of This Mathimatical Operation Is = " << result << endl;
    return 0;
}