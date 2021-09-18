#include <iostream>

#define MAXN 501

using namespace std;

struct probe_location
{
    int x, y;
};

int calculate_time(char direction, char galaxy[MAXN][MAXN], probe_location probe, int rows, int columns)
{
    for(int time = 1; time <= 100000; time++)
    {
        int dirX = 0, dirY = 0;
        //cout << direction << endl;
        if(direction == 'U')
            dirY = -1;
        else if(direction == 'R')
            dirX = 1;
        else if(direction == 'D')
            dirY = 1;
        else
            dirX = -1;
        probe.x += dirX;
        probe.y += dirY;
        //end detection
        if(probe.x > columns || probe.x < 1)
            return time;
        else if(probe.y > rows || probe.y < 1)
            return time;
        char current_location = galaxy[probe.y][probe.x];
        if(current_location == 'C')
            return time;
        else if(current_location == '.')
            continue;
        else
        {
            if(current_location == '/')
            {
                if(direction == 'U')
                    direction = 'R';
                else if(direction == 'R')
                    direction = 'U';
                else if(direction == 'D')
                    direction = 'L';
                else
                    direction = 'D';
            }
            else
            {
                if(direction == 'U')
                    direction = 'L';
                else if(direction == 'R')
                    direction = 'D';
                else if(direction == 'D')
                    direction = 'R';
                else
                    direction = 'U';
            }
        }
    }
    return 100000;
}

int main()

{
    probe_location probe;
    int rows, columns, max_time = 0;
    char galaxy[MAXN][MAXN], directions[4] = {'U', 'R', 'D', 'L'}, best_direction;
    cin >> rows >> columns;
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++)
            cin >> galaxy[i][j];
    cin >> probe.y >> probe.x;
    //cout << galaxy[probe.y-1][probe.x] << endl;
    for(int d = 0; d < 4; d++)
    {
        //cout << endl;
        long calculated_time = calculate_time(directions[d], galaxy, probe, rows, columns);
        //cout << calculated_time << endl;
        if(calculated_time > max_time)
        {
            max_time = calculated_time;
            best_direction = directions[d];
        }
        else
            continue;
        }
    cout << best_direction << endl;
    if(max_time == 100000)
        cout << "Voyager" << endl;
    else
        cout << max_time << endl;
}
