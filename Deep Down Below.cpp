#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {

        int temp;
        cin >> temp;
        const int caves = temp;
        //cout << "caves: " << caves << endl;
        int monsters[caves], armor[caves][100000], armor_left[caves], armor_needed[caves], answer = 0;
        for(int i = 0; i < caves; i++)
        {
            cin >> monsters[i];
            //cout << "monsters: " << monsters[i] << endl;
            for(int j = 0; j < monsters[i]; j++)
            {
                cin >> armor[i][j];
                //cout << "armor " << j+1 << ": " << armor[i][j] << " ";
            }
            //cout << endl;
        }
        for(int i = 0; i < caves; i++)
        {
            int needed = 0;
            for(int j = 0; j < monsters[i]; j++)
            {
                needed = max(armor[i][j]-j, needed);
            }
            armor_needed[i] = needed;
            armor_left[i] = needed+monsters[i];
        }
        sort()
    }
}
