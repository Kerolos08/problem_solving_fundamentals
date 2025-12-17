#include <iostream>
using namespace std;

struct stDuration {
    int days;
    int hours;
    int minutes;
    int seconds;
};

int ReadPossitiveNumber (string msg)
{
    int number;
    do{
        cout << msg << endl;
        cin >> number;
    }while (number < 0);
    return number;
}

stDuration calculate (int numberofseconds)
{
    stDuration duration;

    const int secondsinday = 24 * 60 * 60;
    const int secondsinhour = 60 * 60;
    const int secondsinminute = 60;


    duration.days = numberofseconds / secondsinday;
    int remainder = numberofseconds % secondsinday;

    duration.hours = remainder / secondsinhour;
    remainder = remainder % secondsinhour;

    duration.minutes = remainder / secondsinminute;
    remainder = remainder % secondsinminute;

    duration.seconds = remainder;

    return duration;
}


void PrintResult (stDuration duration)
{
    cout << "\n" << duration.days << ":" << duration.hours << ":" << duration.minutes << ":" << duration.seconds << endl;
}

int main ()
{
    int secondsinput = ReadPossitiveNumber ("Please Enter Number Of Seconds");

    PrintResult(calculate(secondsinput));

    return 0;
}