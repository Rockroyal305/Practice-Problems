#include <iostream>
#include <fstream>
#include <utility>
#include <set>

#define MAXN 1000

using namespace std;

int main()

{
    ifstream fin("cowrow.in");
    ofstream fout("cowrow.out");
    int number, cows[MAXN], max_streak = 0;
    fin >> number;
    for(int i = 0; i < number; i++)
    {
        fin >> cows[i];
    }
    for(int i = 0; i < number; i++)
    {
        //remove cow i
        for(int j = 0; j < number; j++)
        {
            if(cows[j] != cows[i])
            {
                int streak_start = cows[j], streak_length = 0;
                for(int k = j; k < number; k++)
                {
                    if(cows[k] == streak_start)
                        streak_length++;
                    else if(cows[k] == cows[i])
                        continue;
                    else
                        break;
                }
                max_streak = max(max_streak, streak_length);
            }
        }
    }
    cout << max_streak << endl;
}
