/*
ID: rockroy1
TASK: castle
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <algorithm>

#define MAX_N 50

using namespace std;

int borders[MAX_N][MAX_N][4];

void num_to_border(int num, int iter1, int iter2)
{
    //                       W  N  E  S
    int temp[7], codes[4] = {1, 2, 4, 8};
    for(int i = 0; i < 3; i++)
    {
        temp[i] = 0;
    }
    for(int i = 3; i < 7; i++)
    {
        temp[i] = 1;
    }
    do
    {
        int temp_sum = 0;
        for(int i = 0; i < 4; i++)
        {
            if(temp[i] == 1)
            {
                temp_sum += codes[i];
            }
        }
        if(temp_sum ==  num)
        {
            for(int i = 0; i < 4; i++)
            {
                if(temp[i] == 1)
                {
                    //cout << codes[i] << " ";
                    borders[iter1][iter2][i] = 1;
                }
                else
                {
                    borders[iter1][iter2][i] = 0;
                }
            }
            //cout << endl;
            return;
        }
    }while(next_permutation(temp, temp+7));
}

int main()

{
    int M, N, boundaries[MAX_N][MAX_N];
    ifstream fin("castle.in");
    ofstream fout("castle.out");
    fin >> M >> N;
    //cout << M << " " << N << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            fin >> boundaries[i][j];
            //cout << boundaries[i][j] << " ";
            num_to_border(boundaries[i][j], i, j);
            for(int k = 0; k < 4; k++)
            {
                cout << borders[i][j][k];
            }
            cout << endl;
            cout << endl;
        }
        //cout << endl;
    }
}
