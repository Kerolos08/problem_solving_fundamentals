#include <iostream>
using namespace std;

int ReadNumberInRange (int from ,int to)
{
    int Grade;
    do{
        cout << "Please Enter Your Mark" << endl;
        cin >> Grade;
    }while (!(Grade > 0 && Grade <= 100));
    return Grade;
}

char GradChar (int Grade)
{   
    cout << "Your Grade Is: " ;
    if (Grade >= 90)
    return 'A';
    else if (Grade >= 80)
    return 'B';
    else if (Grade >= 70)
    return 'C';
    else if (Grade >= 60)
    return 'D';
    else if (Grade >= 50)
    return 'E';
    else 
    return 'F';
}

int main ()
{
    cout << GradChar(ReadNumberInRange(0, 100));
    return 0;
}