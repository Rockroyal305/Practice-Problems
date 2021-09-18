#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXH 100

using namespace std;

int number, locations[MAXH], max_bales = 0;

int explode_bale(int index)
{
    int left = index, right = index, explosions = 1, time = 1;
    bool stop_left = false, stop_right = false;
    while(!(left == 0 && right == number-1))
    {
        bool explode = false;
        if(left > 0 && locations[left] - locations[left-1] <= time && !stop_left)
        {
            //explosions++;
            explode = true;
        }
        else
            stop_left = true;
        if(right < number-1 && locations[right+1] - locations[right] <= time && !stop_right)
        {
            //explosions++;
            explode = true;
        }
        else
            stop_right = true;
        if(stop_left && stop_right)
            return explosions;
        if(explode)
        {
            /*left--;
            right++;*/
            int left_start = left, right_start = right;
            for(int i = left_start; i >= 0; i--)
            {
                if(locations[left_start] - locations[i] <= time && !stop_left)
                {
                    left = i;
                    if(i != left_start)
                        explosions++;
                }
            }
            for(int i = right_start; i < number; i++)
            {
                if(locations[i] - locations[right_start] <= time && !stop_right)
                {
                    right = i;
                    if(i != right_start)
                        explosions++;
                }
            }
        }
        else
            return explosions;
        time++;
    }
    return explosions;
}

int main()

{
    int max_bale;
    cin >> number;
    for(int i = 0; i < number; i++)
        cin >> locations[i];
    sort(locations, locations+number);
    //cout << endl;
    for(int i = 0; i < number; i++)
    {
        //cout << locations[i] << endl;
        if(max_bales < explode_bale(i)) max_bale = locations[i];
        max_bales = max(max_bales, explode_bale(i));
    }
    //cout << endl;
    //cout << max_bale << endl;
    cout << max_bales << endl;
}

