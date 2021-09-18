#include <iostream>
#include <fstream>

using namespace std;


bool in_between(int between, int bound1, int bound2)
{
    if(bound1 < between && between < bound2)
        return true;
    return false;
}

int main()

{
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out");
    char crossing_points[52], already_checked[52];
    int checked = 0, pair_locations[26][2], crossing_pairs = 0;
    for(int i = 0; i < 52; i++)
    {
        fin >> crossing_points[i];
    }
    fin.close();
    for(int i = 0; i < 52; i++)
    {
        bool check_pair = true;
        for(int j = 0; j < i; j++)
        {
            if(crossing_points[i] == already_checked[j])
                check_pair = false;
        }
        if(check_pair)
        {
            //cout << crossing_points[i] << endl;
            already_checked[checked] = crossing_points[i];
            for(int j = i; j < 52; j++)
            {
                if(j != i)
                {
                    if(crossing_points[i] == crossing_points[j])
                    {
                        pair_locations[checked][0] = i;
                        pair_locations[checked][1] = j;
                    }
                }
            }
            checked++;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            if(j != i)
            {
                if(in_between(pair_locations[j][0], pair_locations[i][0], pair_locations[i][1]) &&
                   in_between(pair_locations[i][1], pair_locations[j][0], pair_locations[j][1]))
                    crossing_pairs++;
            }
        }
    }
    fout << crossing_pairs << endl;
}
