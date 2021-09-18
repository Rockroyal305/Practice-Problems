#include <iostream>
#include <string>

using namespace std;

int get_hexadecimal(char number)
{
    int num = number-'0';
    if(number <= 9)
        return number;
    if(number == 'A')
        return 10;
    if(number == 'B')
        return 11;
    if(number == 'C')
        return 12;
    if(number == 'D')
        return 13;
    if(number == 'E')
        return 14;
    if(number == 'F')
        return 15;
}

string hex_to_binary(int number)
{
    //          8421
    if(number == 0)
        return "0000";
    if(number == 1)
        return "0001";
    if(number == 2)
        return "0010";
    if(number == 3)
        return "0011";
    if(number == 4)
        return "0100";
    if(number == 5)
        return "0101";
    if(number == 6)
        return "0110";
    if(number == 7)
        return "0111";
    if(number == 8)
        return "1000";
    if(number == 9)
        return "1001";
    if(number == 10)
        return "1010";
    if(number == 11)
        return "1011";
    if(number == 12)
        return "1100";
    if(number == 13)
        return "1101";
    if(number == 14)
        return "1110";
    if(number == 15)
        return "1111";
}

int main()

{
    string num, binary = "";
    cin >> num;
    if(num == "0")
    {
        cout << 0 << endl;
        return 0;
    }
    //cout << hex_to_binary(get_hexadecimal('1')) << endl;
    for(int i = num.size()-1; i >= 0; i--)
    {
        //cout << num[i] << endl;
        binary = hex_to_binary(get_hexadecimal(num[i])) + binary;
    }
    //cout << hex_num << endl;
    int number = 0, base = 1;
    for(int i = binary.size()-1; i >= 0; i++)
    {
        int num = binary[i]-'0';
        if(num == 1)
        {
            number += base;
        }
        base *= 2;
    }
    cout << number << endl;
}
