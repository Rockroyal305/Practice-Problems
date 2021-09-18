#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXL 100

using namespace std;

struct shifts
{
    int start = 0;
    int end = 0;
};

bool compare_lifeguards(shifts guard_1, shifts guard_2)
{
    if(guard_1.start != guard_2.start)
        return guard_1.start < guard_2.start;
    return guard_1.end <= guard_2.end;
}

bool time_covered(int time, shifts lifeguards[], int number)
{
    for(int i = 0; i < number; i++)
    {
        if(time <= lifeguards[i].end && time > lifeguards[i].start)
            return true;
    }
    return false;
}

int main()

{
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int number, max_covered = 0;
    shifts lifeguards[MAXL];
    fin >> number;
    for(int i = 0; i < number; i++)
    {
        fin >> lifeguards[i].start >> lifeguards[i].end;
        //cout << lifeguards[i].start << " " << lifeguards[i].end << endl;
    }
    //cout << endl;
    sort(lifeguards, lifeguards+number, compare_lifeguards);
    /*for(int i = 0; i < number; i++)
    {
        cout << lifeguards[i].start << " " << lifeguards[i].end << endl;
    }
    cout << endl;*/
    int max_time = 1000;
    for(int i = 0; i < number; i++)
    {
        int removed_start = lifeguards[i].start;
        int removed_end = lifeguards[i].end;
        int temp = 0;
        lifeguards[i].start = 0;
        lifeguards[i].end = 0;
        for(int j = 1; j < max_time; j++)
        {
            if(time_covered(j, lifeguards, number))
                temp++;
        }
        max_covered = max(temp, max_covered);
        /*for(int i = 1; i < number; i++)
        {
            cout << lifeguards[i].start << " " << lifeguards[i].end << endl;
        }
        cout << endl;*/
        lifeguards[i].start = removed_start;
        lifeguards[i].end = removed_end;
    }
    fout << max_covered << endl;
}
