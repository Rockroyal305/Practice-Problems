#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXC 7

using namespace std;

int main()

{
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    string cows[8] = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    bool found = false;
    sort(cows, cows+8);
    string constraints[MAXC][2], possibilities[8], temp;
    int num_of_constraints, validity = 0;
    fin >> num_of_constraints;
    for(int i = 0; i < num_of_constraints; i++)
    {
        fin >> constraints[i][0];
        for(int j = 0; j < 4; j++)
        {
            fin >> temp;
        }
        fin >> constraints[i][1];
    }
    /*cout << endl;
    for(int i = 0; i < num_of_constraints; i++)
    {
        cout << constraints[i][0] << ": " << constraints[i][1] << endl;;
    }
    cout << endl;*/
    do
    {
        validity = 0;
        for(int i = 0; i < 8; i++)
        {
            possibilities[i] = cows[i];
        }
        for(int i = 0; i < num_of_constraints; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(constraints[i][0] == possibilities[j] && (constraints[i][1] == possibilities[j+1] || constraints[i][1] == possibilities[j-1]))
                {
                    validity++;
                    break;
                }
            }
        }
        if(validity == num_of_constraints) //&& !found)
        {
            for(int i = 0; i < 8; i++)
            {
                fout << possibilities[i] << endl;
            }
            found = true;
            //return 0;
            //cout << endl;
        }
    }while(next_permutation(cows, cows + 8) && !found);
    return 0;
}
