#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct times
{
    int arrival;
    int required_time;
};

bool times_sort(times num1, times num2)
{
    if(num1.arrival < num2.arrival)
        return true;
    if(num2.arrival < num1.arrival)
        return false;
    return num1.required_time < num2.required_time;
}

int main()

{
    ifstream fin("cowqueue.in");
    ofstream fout("cowqueue.out");
    int cows, time = 0;
    times details[MAXN];
    fin >> cows;
    for(int i = 0; i < cows; i++)
        fin >> details[i].arrival >> details[i].required_time;
    sort(details, details+cows, times_sort);
    time = details[0].arrival;
    for(int i = 0; i < cows; i++)
    {
        if(i == 0)
        {
            time += details[i].required_time;
        }
        else
        {
            if(time <= details[i].arrival)
            {
                time = details[i].arrival;
                time += details[i].required_time;
            }
            else
            {
                time += details[i].required_time;
            }
        }
    }
    fout << time << endl;
}
