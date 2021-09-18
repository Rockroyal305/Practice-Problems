#include <iostream>

#define MAXN 20
#define MAXK 10

using namespace std;

int main()

{
    int sessions, cows, practice_sessions[MAXK][MAXN], consistent_pairs = 0;
    cin >> sessions >> cows;
    for(int i = 0; i < sessions; i++)
    {
        for(int j = 0; j < cows; j++)
            cin >> practice_sessions[i][j];
    }
    for(int i = 0; i < cows-1; i++)
    {
        for(int j = i+1; j < cows; j++)
        {
            int consistency = 0;
            for(int k = 0; k < sessions; k++)
            {
                int loc_i, loc_j;
                for(int l = 0; l < cows; l++)
                {
                    if(practice_sessions[k][l] == practice_sessions[0][i])
                        loc_i = l;
                }
                for(int l = 0; l < cows; l++)
                {
                    if(practice_sessions[k][l] == practice_sessions[0][j])
                        loc_j = l;
                }
                //cout << "i: " << loc_i << " j: " << loc_j << endl;
                if(loc_i < loc_j)
                    consistency++;
            }
            if(consistency == sessions)
            {
                consistent_pairs++;
                //cout << practice_sessions[0][i] << ": " << practice_sessions[0][j] << endl;
            }
        }
    }
    cout << consistent_pairs << endl;
}
