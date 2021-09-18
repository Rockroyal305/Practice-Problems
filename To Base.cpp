#include <iostream>
#include <string>

using namespace std;

int num_base10(int num, int base)
{
    string number = to_string(num);
    int result = 0, base_num = 1;
    for(int i = number.size()-1; i >= 0; i--)
    {
        //cout << number[i] << endl;
        if(number[i] != '0')
            result += base_num*(number[i]-'0');
        //cout << result << endl;
        base_num*=base;
    }
    //cout << endl;
    return result;
}

int main()

{
    int number, base;
    cin >> number >> base;
    //cout << endl;
    cout << num_base10(number, base) << endl;
}
