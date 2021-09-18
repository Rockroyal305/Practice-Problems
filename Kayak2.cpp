#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int rows, columns, distances[50], boats[50];
int temporary_distance, temporary_boats;
char race[50][50];
bool rowcheck;

bool search(int lane, int lines, bool debug)
{
    rowcheck = false;
    if(debug == true)
    {
        cout << "Row: ";
        for(int i = 0; i < lines; i++)
        {
            cout << race[lane][i];
        }
        cout << " ";
    }
    for(int i = 0; i < lines; i++)
    {
        if(race[lane][i] != 'S' && race[lane][i] != 'F' &&  race[lane][i] != '.')
        {
            rowcheck = true;
            return rowcheck;
        }
    }
}

int main()

{
    cin >> rows;
    cin >> columns;
    for(int i = 0; i < 50; i++)
    {
        distances[i] = 0;
        boats[i] = 0;
    }
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cin >> race[i][j];;
            if(race[i][j] != 'S' && race[i][j] != 'F' &&  race[i][j] != '.' && search(j, columns, false) == true)
            {
                distances[race[i][j] - '1'] = columns - j;
                boats[race[i][j] - '1']
                cout << "J: " << j << endl;
            }
        }
    }
}
