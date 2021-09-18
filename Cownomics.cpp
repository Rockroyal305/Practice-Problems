#include <iostream>
#include <fstream>

#define MAXS 500

using namespace std;

int main()

{
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int N, M, identifiers = 0;
    string spotty_cows[MAXS], plain_cows[MAXS];
    fin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        fin >> spotty_cows[i];
    }
    for(int i = 0; i < N; i++)
    {
        fin >> plain_cows[i];
    }
    for(int i = 0; i < M; i++)
    {
        string sequence1 = "", sequence2 = "";
        bool working = true;
        for(int j = 0; j < N; j++)
        {
            sequence1 += spotty_cows[j][i];
            sequence2 += plain_cows[j][i];
        }
        //cout << sequence1 << " " << sequence2 << endl;
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
            {
                if(sequence1[j] == sequence2[k])
                    working = false;
            }
        }
        if(working)
        {
            identifiers++;
            //cout << "New Position" << endl;
        }
    }
    fout << identifiers << endl;
}
