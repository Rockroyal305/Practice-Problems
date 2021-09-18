#include <iostream>

using namespace std;

int length, queries, CP, DP = 1; //DP = 1 for right, -1 for left
int times_printed[11] = {0,0,0,0,0,0,0,0,0,0,0};
char sequence[101], copy[101];
pair <int, int> query;

void delete(int position)
{
    for(int i = position; i < length; i++)
        sequence[i] = sequence[i+1];
    length--;
    CP--;
    return;
}

int main()

{

    cin >> length >> queries;
    for(int i = 1; i <= length; i++)
        cin >> sequence[i];
    for(int i = 0; i < queries; i++)
    {
        cin >> query.first >> query.second;
        char previous;
        previous = sequence[CP];
        for(int i = 1; i <= length; i++)
            copy[i] = sequence[i];
        //cout << query.first << " " << query.second << endl;
        while(CP >= query.first && CP <= query.second)
        {
            if(sequence[CP] != '<' && sequence[CP] != '>')
            {
                if(sequence[CP] == '0')
                {
                    delete(CP);
                }
                else
                {
                    times_printed[sequence[CP-'0']]++;
                    sequence[CP-'0'] = (sequence[CP-'0']-1)-'0';
                }
            }
        }
    }
}
