#include <stdio.h>
#include <iostream>

using namespace std;

int solve(int dist)
{
    int minSpeed;
    cin >> minSpeed;
    int leftDist = 0;
    int rightDist = 0;
    int time = 0;
    for(int curSpeed = 1;;curSpeed++)
    {
        leftDist += curSpeed;
        time++;
        if(leftDist + rightDist >= dist)
        {
            return time;
        }

        if(curSpeed >= minSpeed)
        {
            rightDist += curSpeed;
            time++;
            if(leftDist + rightDist >= dist)
            {
                return time;
            }
        }
    }
}

int main()
{
    int k, n;
    cin >> k >> n;
    for(int i = 0; i < n; i++)
    {
        cout << solve(k) << endl;
    }
}
