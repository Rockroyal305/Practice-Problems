#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXC 100

using namespace std;

int main()

{
    int number, cows[MAXC], sorted[MAXC], differences = 0;
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    fin >> number;
    for(int i = 0; i < number; i++)
    {
        fin >> cows[i];
        //cout << cows[i] << endl;
        sorted[i] = cows[i];
    }
    sort(sorted, sorted+number);
    int swaps = -1;
    for(int a = 0; a < number; a++)
    {
        if(sorted[a] != cows[a])
        {
            swaps++;
        }
    }
    swaps = max(swaps, 0);
    fout << swaps << endl;
}
