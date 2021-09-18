#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <vector>
#include <iostream>

//define MAXN 100000
#define MAXP 50001

using namespace std;

int main()
{
    ifstream fin("decorate.in");
    ofstream fout("decorate.out");
    int pastures, path_number, maxJ = 0;
    //cout << pastures << endl;
    vector<int>paths[MAXP];
    char pasture_letters[MAXP], letters[2] = {'F', 'J'};
    fin >> pastures >> path_number;
    //cout << pastures << endl;/*
    for(int i = 0; i < path_number; i++)
    {
        int temp1, temp2;
        fin >> temp1 >> temp2;
        paths[temp1].push_back(temp2);
        paths[temp2].push_back(temp1);
    }
    /*for(int i = 1; i <= pastures; i++)
    {
        cout << i << ": ";
        for(int j = 0; j < paths[i].size(); j++)
        {
            cout << (paths[i])[j] << " ";
        }
        cout << endl;
    }*/
    fin.close();
    // populate paths...
    for(int i = 0; i < 2; i++)
    {
        for(int j = 1; j <= pastures; j++)
            pasture_letters[j] = 'N';
        pasture_letters = letters[i];
        for(int j = 1; j <= pastures; j++)
        {
            for(int k = 0; k < paths[j].size(); k++)
            {
                if(pasture_letters[(paths[j])[k]] == 'N')
                {
                    if()
                }
            }
        }
    }
}
