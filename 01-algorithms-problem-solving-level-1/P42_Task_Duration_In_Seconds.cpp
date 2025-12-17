#include <iostream>
using namespace std;

struct stTaskDuration {int days, hours, minutes, seconds;};

int ReadPossitiveNumber (string msg)
{
    int number;
    do
    {
    cout << msg << endl;
    cin >> number;
    } while (number < 0);
    return number;
}

stTaskDuration ReadDuration ()
{
    stTaskDuration taskduration;
    taskduration.days = ReadPossitiveNumber("Enter Number Of Days");
    taskduration.hours = ReadPossitiveNumber("Enter Number Of Hours");
    taskduration.minutes = ReadPossitiveNumber("Enter Number Of Minutes");
    taskduration.seconds = ReadPossitiveNumber ("Enter Number Of Seconds");

    return taskduration;
}

int CalculateTaskDuration (stTaskDuration taskduration)
{
    int durationinseconds = taskduration.days * 24 * 60 * 60;
    durationinseconds += taskduration.hours * 60 * 60;
    durationinseconds += taskduration.minutes * 60;
    durationinseconds += taskduration.seconds;
    return durationinseconds;
}

int main ()
{
    int durationinseconds = CalculateTaskDuration(ReadDuration());
    cout << endl;
    cout << "Total Duration Of The Task In Seconds = " << durationinseconds << endl;
    return 0;
}