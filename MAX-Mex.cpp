#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int answer = 0, MEX[100000], length;
        string binary_string_1, binary_string_2;
        cin >> length >> binary_string_1 >> binary_string_2;
        for(int i = 0; i < length; i++)
        {
            if(binary_string_1[i] == '1' && binary_string_2[i] == '0')
            {
                answer += 2;
                binary_string_1.erase(binary_string_1.begin()+i);
                binary_string_2.erase(binary_string_2.begin()+i);
                continue;
            }
            else if(binary_string_1[i] == '0' && binary_string_2[i] == '1')
            {
                answer += 2;
                binary_string_1.erase(binary_string_1.begin()+i);
                binary_string_2.erase(binary_string_2.begin()+i);
                continue;
            }
            else continue;
            length = binary_string_1.size();
        }
        //cout << endl;
        //cout << binary_string_1 << endl;
        //cout << binary_string_2 << endl;
        for(int i = 0; i < length; i++)
        {
            if(binary_string_1[i] == binary_string_2[i])
            {
                if(binary_string_1 == '1')
            }
            else if()
            {

            }
        }
        cout << answer << endl;
    }
}
