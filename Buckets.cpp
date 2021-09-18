#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()

{
    int barn_x, barn_y, rock_x, rock_y, lake_x, lake_y;
    char map[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == 'B')
            {
                barn_x = j;
                barn_y = i;
            }
            else if(map[i][j] == 'R')
            {
                rock_x = j;
                rock_y = i;
            }
            else if(map[i][j] == 'L')
            {
                lake_x = j;
                lake_y = i;
            }
            else
            {

            }
        }
    }
    cout << "Barn Position:" << barn_x << ", " << barn_y << endl;
    cout << "Rock Position:" << rock_x << ", " << rock_y << endl;
    cout << "Lake Position:" << lake_x << ", " << lake_y << endl;
    if((barn_x < rock_x && rock_x < lake_x && barn_y == rock_y && rock_y == lake_y) or (barn_x > rock_x && rock_x > lake_x && barn_y == rock_y && rock_y == lake_y) or (barn_y < rock_y && rock_y < lake_y && barn_x == rock_x && rock_x == lake_x) or (barn_y > rock_y && rock_y > lake_y && barn_x == rock_x && rock_x == lake_x) )
    {
        cout << abs(barn_x-lake_x) + abs(barn_y-lake_y) + 1 << endl;
        cout << "Barrier" << endl;
    }
    else
    {
        cout << abs(barn_x-lake_x) + abs(barn_y-lake_y) - 1 << endl;
    }
}

