#include <iostream>
#include <vector>

using namespace std;

int main()

{
    int length, queries, temp;
    vector<int>array;
    cin >> length >> queries;
    array.push_back(1000000);
    for(int i = 1; i <= length; i++)
    {
        cin >> temp;
        array.push_back(temp);
    }
    for(int q = 0; q < queries; q++)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x, y;
            array[x] = y;
        }
        else
        {
            int l, r, answer = 0;
            vector<int>copy;
            for(int i = l; i <= r; i++)
            {
                copy.push_back(array[i]);
            }
            for(int i = 0; i < r-l-1; i++)
            {
                for(int j = r-l; j > i; j--)
                {
                    bool working = true;
                    for(int k = i; k < j-1; k++)
                    {
                        if(copy[k] > copy[k+1])
                            working = false;
                    }
                    if(working)
                    {
                        answer += j-i;
                        break;
                    }
                }
            }
            cout << answer << endl;
        }
    }
}
