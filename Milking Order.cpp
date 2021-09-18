#include <iostream>
#include <fstream>

#define MAXN 101

using namespace std;

int cows, hierarchy_cows, specific_cows, hierarchy[MAXN], milking_order[MAXN];

bool check(int i_position)
{

}

int main()

{
    ifstream fin("milkingorder.in");
    ofstream fout("milkingorder.out");
    fin >> cows >> hierarchy_cows >> specific_cows;
    for(int i = 0; i < hierarchy_cows; i++)
    {
        fin >> hierarchy[i];
    }
    for(int i = 0; i < specific_cows; i++)
    {
        int cow, position;
        fin >> cow >> position;
        milking_order[position] = cow;
        if(cow == 1)
        {
            cout << position << endl;
            return 0;
        }
    }
    for(int i = 1; i <= number; i++)
    {
        if(milking_order[i] == 0)
        {
            if(check(i))
            {
                cout << i << endl;
                return 0;
            }
        }
    }
}
