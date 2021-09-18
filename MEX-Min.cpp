#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        string binary_string;
        cin >> binary_string;
        int zeros = 0, ones = 0;
        for(int i = 0; i < binary_string.size(); i++)
        {
            if(binary_string[i] == '0')
                zeros++;
            else
                ones++;
        }
        if(zeros == 0)
            cout << 0 << endl;
        else if(ones == 0)
            cout << 1 << endl;
        else
        {
            int zero_seq = 0;
            for(int i = 0; i < binary_string.size(); i++)
            {
                if(binary_string[i] == '0')
                {
                    int j = i;
                    while(binary_string[j] == '0')
                    {
                        binary_string[j] = '1';
                        j++;
                    }
                    zero_seq++;
                }
            }
            if(zero_seq < 2)
                cout << zero_seq << endl;
            else
                cout << 2 << endl;
        }
    }
}
