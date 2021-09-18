#include <iostream>
#include <fstream>

#define MAXN 100000

using namespace std;

int num_of_islands(bool above_water[], int number)
{
    int islands = 0;
    for(int i = 0; i < number; i++)
    {
        if(above_water[i])
        {
            islands++;
            for(int j = i; j < number; j++)
            {
                if(above_water[j])
                    above_water[j] = false;
                else
                    break;
            }
        }
    }
    return islands;
}

int main()

{
    ifstream fin("3.in");
    ofstream fout("islands.out");
    int number, islands[MAXN], max_islands = 0, max_height = 0, min_height = 1000000;
    bool above_water[MAXN];
    fin >> number;
    for(int i = 0; i < number; i++)
    {
        fin >> islands[i];
        max_height = max(max_height, islands[i]);
        min_height = min(min_height, islands[i]);
    }
    for(float water_level = min_height; water_level <= max_height; water_level += 0.5)
    {
        for(int i = 0; i < number; i++)
            above_water[i] = (islands[i] > water_level);
        int calculated = num_of_islands(above_water, number);
        //cout << calculated << endl;
        if(calculated > max_islands)
            max_islands = calculated;
    }
    //cout << endl;
    cout << max_islands << endl;
}
