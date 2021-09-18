#include <iostream>

#define MAXN 100

using namespace std;

int main()

{
    int log[MAXN], number, required = 0, possible = 0, time = -1;
    cin >> number;
    for(int i = 0; i < number; i++)
        cin >> log[i];
    if(log[0] > 0)
    {
        cout << -1 << endl;
        return 0;
    }
    log[0] = 0;
    for(int i = number-1; i >= 0; i--)
    {
        if(time != -1 && log[i] != -1 && log[i] != time)
        {
            cout << -1 << endl;
            return 0;
        }
        if(time == -1)
            time = log[i];
        if(log[i] == -1)
            log[i] = time;
        if(log[i] == 0)
            required++;
        if(log[i] == -1)
            possible++;
        if(time > -1)
            time--;
    }
    cout << required << " " << required+possible << endl;
}
