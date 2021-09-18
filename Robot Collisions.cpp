#include <iostream>

using namespace std;

struct robot
{
    int position;
    char direction;
};

char direction_change(char direction)
{
    if(direction == 'R')
        return 'L';
    return 'R';
}

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int number, right_wall, collisions[300000];
        robot robots[300000];
        cin >> number >> right_wall;
        for(int i = 0; i < number; i++)
            cin >> robots[i].position;
        for(int i = 0; i < number; i++)
        {
            cin >> robots[i].direction;
            collisions[i] = -1;
        }
        for(int time = 0; time <= 2*right_wall; time++)
        {
            for(int i = 0; i < number; i++)
            {

            }
        }
        //split robots into two groups, odd and even positions
    }
}
