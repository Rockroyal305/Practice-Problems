#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <bits/stdc++.h>

#define MAXN 10

using namespace std;

struct kayak
{
    int kayak_number, location;
};

bool kayak_sort(kayak num1, kayak num2)
{
    return num1.location >= num2.location;
}


int main()

{
    kayak kayaks[MAXN];
    int rows, columns, kayak_indices[MAXN];
    cin >> rows >> columns;
    //cout << rows << " " << columns << endl;
    for(int i = 1; i < 10; i++)
        kayaks[i].kayak_number = i;
    //cout << endl;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            char temp;
            int character;
            cin >> temp;
            if(j > 0 && j < columns-1 && temp != '.')
            {
                character = temp-'0';
                //cout << character << endl;
                kayaks[character].location = j;
                cout << j;
            }
        }
        cout << endl;
    }
    sort(kayaks+1, kayaks+rows, kayak_sort);
    /*for(int i = 1; i < 10; i++)
    {
        cout << kayaks[i].kayak_number << ": " <<  kayaks[i].location << endl;
        //
    }
    cout << endl;
    for(int i = 1; i < 10; i++)
    {
        cout << kayaks[i].kayak_number << ": " <<  kayaks[i].location << endl;
    }*/
    for(int i = 1; i < 10; i++)
    {
        kayak_indices[kayaks[i].kayak_number] = i;
    }
    /*for(int i = 1; i < 10; i++)
        cout << kayak_indices[i] << endl;*/
    int ties = 0, previous = 0;
    for(int i = 1; i < 10; i++)
    {
        if(ties == 0 && kayaks[kayak_indices[i]].location != previous)
        {
            previous = kayaks[kayak_indices[i]].location;
            cout << kayak_indices[i] << endl;
        }
        else if(ties == 0 && kayaks[kayak_indices[i]].location == previous)
        {
            ties++;
            cout << kayak_indices[i] - ties << endl;
        }
        else
        {
            if(kayaks[kayak_indices[i]].location == previous)
            {
                ties++;
                cout << kayak_indices[i] - ties << endl;
            }
            else
            {
                previous = kayaks[kayak_indices[i]].location;
                cout << kayak_indices[i] << endl;
            }
        }
        cout << previous << endl;
        cout << endl;
    }
    //cout << ties << endl;
}


