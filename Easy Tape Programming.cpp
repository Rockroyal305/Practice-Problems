#include <iostream>
#include <vector>

using namespace std;

int main()

{
    int length, queries, CP, DP = 1; //DP = 1 for right, -1 for left
    vector<char> sequence, copy;
    cin >> length >> queries;
    for(int i = 1; i <= length; i++)
    {
        char temp;
        cin >> temp;
        sequence.push_back(temp);
    }

    for(int i = 0; i < queries; i++)
    {
        int l, r, numbers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0, i < length; i++)
        {
            copy.push_back(sequence[i]);
        }
        cin >> l >> r;
        l--;
        r--;
        CP = l;
        while(CP >= l && CP <= r)
        {
            if(sequence[CP] != '<' || sequence[CP] != '>')
            {
                numbers[sequence[CP] - '0']++;
                if(sequence[CP] != '0')
                    sequence[CP] = (sequence[CP] - '0' - 1) + '0';
                else
                    sequence.erase(sequence.begin()+CP);
            }
            else
            {
                if(sequence[CP] == '<')
                    DP = -1;
                else
                    DP = 1;
            }
            CP += DP;
        }
        for(int i = 0; i <= 9; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << endl;
    }
}
