#include <iostream>
#include <math.h>

#define MAXN 1001

using namespace std;

struct cow
{
    int x, y;
};

int square(int number)
{
    return number*number;
}

int cow_distance(cow cow1, cow cow2)
{
    //cout << "(" << cow1.x << ", " << cow1.y << ") (" << cow2.x << ", " << cow2.y << ")" << endl;
    return sqrt(square(cow2.x-cow1.x) + square(cow2.y-cow1.y));
}

int main()

{
    int number, current_cow = 1;
    bool still_standing[MAXN];
    cow cows[MAXN];
    cin >> number;
    int cows_standing = number;
    //cows[0].x = 25000;
    //cows[0].y = 25000;
    for(int i = 1; i <= number; i++)
    {
        cin >> cows[i].x >> cows[i].y;
        still_standing[i] = true;
    }
    //cout << cow_distance(cows[1], cows[2]) << endl;
    while(cows_standing > 1)
    {
        int closest = 0;
        if(still_standing[current_cow])
        {
            for(int i = 1; i <= number; i++)
            {
                if(still_standing[i] && i != current_cow)
                {
                    if(closest == 0 || cow_distance(cows[closest], cows[current_cow]) > cow_distance(cows[i], cows[current_cow]))
                        closest = i;
                }
            }
            still_standing[closest] = false;
            cows_standing--;
        }
        current_cow++;
    }
    for(int i = 1; i <= number; i++)
        if(still_standing[i])
        {
            cout << i << endl;
            //return 0;
        }
}
