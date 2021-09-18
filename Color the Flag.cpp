#include <iostream>
#include <vector>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int n, m;
        char grid[50][50];
        vector<pair<int,int>>red_pos;
        vector<pair<int,int>>white_pos;
        bool working = true;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
            for(int j  = 0; j < m; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == 'R')
                {
                    pair<int,int>temp = make_pair(i, j);
                    red_pos.push_back(temp);
                }
                else if(grid[i][j] == 'W')
                {
                    pair<int,int>temp = make_pair(i, j);
                    white_pos.push_back(temp);
                }
                else
                    continue;
            }
        for(int i = 0; i < white_pos.size(); i++)
        {
            for(int j = 0; j < red_pos.size(); j++)
            {
                if(white_pos[i].first+white_pos[i].second%2 ==
                    red_pos[j].first+red_pos[j].second%2)
                    working = false;
            }
        }
        if(working)
        {
            int odd_red = (red_pos[0].first+red_pos[0].second)%2;
            //cout << "odd_red: " << odd_red << endl;
            cout << "YES" << endl;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    if(grid[i][j] != '.')
                        cout << grid[i][j];
                    else
                    {
                        if(odd_red == (i+j)%2)
                            cout << 'R';
                        else
                            cout << 'W';
                    }
                }
                cout << endl;
            }
        }
        else
            cout << "NO" << endl;
    }
}
