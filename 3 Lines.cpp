#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

#define MAXN 50000

using namespace std;

struct location
{
    int x, y;
};

/*bool x_sort(location loc1, location loc2)
{
    return loc1.x <= loc2.x;
}

bool y_sort(location loc1, location loc2)
{
    return loc1.y <= loc2.y;
}*/

int main()

{
    ifstream fin("6.in");
    ofstream fout("3lines.out");
    int number, x_values = 0, y_values = 0, previous = 0,
        cow_x_values[MAXN], cow_y_values[MAXN];
    set<int>cow_x_values_set, cow_y_values_set;
    location cows[MAXN];
    fin >> number;
    for(int i = 0; i < number; i++)
        fin >> cows[i].x >> cows[i].y;
    for(int i = 0; i < number; i++)
    {
        cow_x_values_set.insert(cows[i].x);
        cow_y_values_set.insert(cows[i].y);
    }
    x_values = cow_x_values_set.size();
    y_values = cow_y_values_set.size();
    //cout << "x: " << x_values << " y: " << y_values << endl;
    if(x_values <= 3 || y_values <= 3)
    {
        cout << 1 << endl;
        return 0;
    }
    int counter_x = 0, counter_y = 0;
    for(set<int>::iterator x = cow_x_values_set.begin(); x != cow_x_values_set.end(); x++)
    {
        cow_x_values[counter_x] = *x;
        counter_x++;
    }
    for(set<int>::iterator y = cow_y_values_set.begin(); y != cow_y_values_set.end(); y++)
    {
        cow_y_values[counter_y] = *y;
        counter_y++;
    }
    //2 x lines, 1 y line
    for(int i = 0; i < x_values - 1; i++)
    {
        for(int j = i+1; j < x_values; j++)
        {
            for(int k = 0; k < y_values; k++)
            {
                bool cows_covered = true;
                for(int l = 0; l < number; l++)
                {
                    if(cows[l].x != cow_x_values[i] &&
                       cows[l].x != cow_x_values[j] &&
                       cows[l].y != cow_y_values[k]) cows_covered = false;
                }
                if(cows_covered)
                {
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }
    //2 y lines, 1 x line
    for(int i = 0; i < y_values - 1; i++)
    {
        for(int j = i+1; j < y_values; j++)
        {
            for(int k = 0; k < x_values; k++)
            {
                bool cows_covered = true;
                for(int l = 0; l < number; l++)
                {
                    if(cows[l].y != cow_y_values[i] &&
                       cows[l].y != cow_y_values[j] &&
                       cows[l].x != cow_x_values[k]) cows_covered = false;
                }
                if(cows_covered)
                {
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << 0 << endl;
    return 0;
}
