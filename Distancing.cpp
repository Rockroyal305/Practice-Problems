#include <iostream>
#include <algorithm>

#define MAXC 1000

using namespace std;

struct cow
{
    int location, infected;
};

bool cow_sort(cow cow1, cow cow2)
{
    return cow1.location < cow2.location;
}

int main()

{
    int number, radius = 1,000,000, islands = 0, gap_sizes[MAXC];
    cow cows[MAXC];
    cin >> number;
    for(int i = 0; i < number; i++)
        cin >> cows[i].location >> cows[i].infected;
    if(number == 1)
    {
        cout << cows[0].infected << endl;
        return 0;
    }
    if(number == 2)
    {
        if(cows[0].infected == 1 || cows[1].infected == 1)
        {
            cout << 1 << endl;
            return 0;
        }
        else
        {
            cout << 0 << endl;
            return 0;
        }
    }
    sort(cows, cows+number, cow_sort);
    for(int i = 0; i < number-1; i++)
    {
        //cout << cows[i].infected << " " << cows[i+1].infected << endl;
        if((cows[i].infected == 1 || cows[i+1].infected == 1)&&
           (cows[i].infected == 0 || cows[i+1].infected == 0))
        {
            //cout << cows[i+1].location - cows[i].location << endl;
            radius = min(radius, cows[i+1].location-cows[i].location-1);
            //cout << "r: " << radius<< endl;
        }
    }
    //cout << radius<< endl;
    for(int i = 0; i < number-1; i++)
    {
        gap_sizes[i] = cows[i+1].location - cows[i].location;
    }
    for(int i = 0; i < number; i++)
    {
        if(i == 0)
        {
            if(cows[i].infected == 1)
            {

            }
        }
    }
}
