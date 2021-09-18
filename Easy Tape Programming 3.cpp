#include <iostream>
#include <vector>

using namespace std;

int main()

{
    int length, queries; //DP = 1 for right, -1 for left
    char sequence[101];
    vector<char> copy;
    pair <int, int> query;
    cin >> length >> queries;
    for(int i = 1; i <= length; i++)
        cin >> sequence[i];
    for(int i = 0; i < queries; i++)
    {
        int l, r, CP = 1, DP = 1, times_printed[10] = {0,0,0,0,0,0,0,0,0,0};
        cin >> l >> r;
        cout << "l: " << l << " r: " << r << endl;
        copy.clear();
        copy.push_back('-');
        for(int j = l; j <= r; j++)
            copy.push_back(sequence[j]);
        copy.push_back('-');
        char previous = 'p';
        while(copy[CP] != '-')
        {
            for(int i = 0; i < copy.size(); i++)
            {
                cout << copy[i] << " ";
            }
            cout << "CP: " << CP << endl;
            if(copy[CP] != '<' && copy[CP] != '>')
            {
                times_printed[copy[CP]-'0']++;
                if(copy[CP] == '0')
                {
                    copy.erase(copy.begin()+CP);
                }
                else
                {
                    copy[CP] = (copy[CP]-'0'-1)+'0';
                }
            }
            else if(copy[CP] == '<')
            {
                if(previous == '<' || previous == '>')
                {
                    copy.erase(copy.begin()+CP - DP);
                }
                DP = -1;
            }
            else
            {
                if(previous == '<' || previous == '>')
                {
                    copy.erase(copy.begin()+ CP - DP);
                }
                DP = 1;
            }
            CP += DP;
            previous = copy[CP-1];
            for(int j = 0; j < 10; j++)
            {
                cout << times_printed[j] << " ";
            }
            cout << endl;
        }
        /*for(int j = 0; j < 10; j++)
        {
            cout << times_printed[j] << " ";
        }
        cout << endl;*/
    }
}
