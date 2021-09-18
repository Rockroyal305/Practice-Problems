#include <iostream>
#include <algorithm>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int players[4], finalist1, finalist2;
        for(int i = 0; i < 4; i++)
            cin >> players[i];
        finalist1 = max(players[0], players[1]);
        finalist2 = max(players[2], players[3]);
        //cout << "1: " << finalist1 << endl;
        //cout << "2: " << finalist2 << endl;
        sort(players, players+4);
        /*for(int i = 0; i < 4; i++)
            cout << players[i] << " ";
        cout << endl;*/
        if(finalist1 == players[2] && finalist2 == players[3])
            cout << "YES" << endl;
        else if(finalist1 == players[3] && finalist2 == players[2])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
