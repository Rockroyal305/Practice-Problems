#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()

{
    int capacities[3];
    int amounts[3];
    int cycle = 0;
    //1st row is for
    for(int i = 0; i < 3; i++)
    {
        cin >> capacities[i];
        cin >> amounts[i];
    }
    for(int i = 0; i < 100; i++)
    {
        if(cycle != 2)
        {
            if(amounts[cycle] + amounts[cycle + 1] <= capacities[cycle + 1])
            {
                amounts[cycle + 1] += amounts[cycle];
                amounts[cycle] = 0;
                cycle++;
            }
            else
            {
                amounts[cycle] -= capacities[cycle + 1] - amounts[cycle + 1];
                amounts[cycle + 1] = capacities[cycle + 1];
                cycle++;
            }
        }
        else
        {
            if(amounts[cycle] + amounts[0] <= capacities[0])
            {
                amounts[0] += amounts[cycle];
                amounts[cycle] = 0;
                cycle = 0;
            }
            else
            {
                amounts[cycle] -= capacities[0] - amounts[0];
                amounts[0] = capacities[0];
                cycle = 0;
            }
        }
    }
    for(int i = 0; i < 3; i++)
    {
        cout << amounts[i] << endl;
    }
}
