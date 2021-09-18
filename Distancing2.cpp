#include <iostream>

using namespace std;

int locations[100,001], cows, radius = 100,000, previous_location;

int main()

{
    cin >> cows;
    for(int i = 0; i < cows; i++)
    {
        int location, infected;
        cin >> location >> infected;
        if(infected == 0) infected = 1;
        else infected = -1;
        locations[location] = infected;
    }
    for(int i = 1; i <= 100,000; i++)
    {
        if(locations[i] != 0)
        {

        }
    }
}
