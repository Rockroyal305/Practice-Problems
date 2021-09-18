#include <iostream>
#include <vector>

using namespace std;

int wrong_position;

bool XOR(vector<int>answer, string XOR_)
{
    for(int i = 0; i < vector.size()-1; i++)
    {
        for(int j = i+1; j < vector.size(); j++)
        {
            if(to_string(answer[i] | answer[j]) != XOR_)
            {
                wrong_position =
                return false;
            }
        }
    }
    return true;
}

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int a;
        string b;
        vector<int>answer;
        cin >> a >> b;
        for(int i = 0; i < a; i++)
        {
            answer.push_back(i);
            cout << i << " ";
        }
        cout << endl;
        while(!XOR(answer, b))
        {

        }
    }
}
