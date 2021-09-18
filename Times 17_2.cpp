#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int getBit(string s, int index)
{
    if(index >= 0)
        return (s[index] - '0');
    else
        return 0;
}

string addBinary(string a, string b)
{
    if(a.size() > b.size())
        while(a.size() > b.size()) b = "0" + b;
    else if(b.size() > a.size())
        while(b.size() > a.size()) a = "0" + a;
    int l = max(a.size()-1, b.size() - 1);
    string result = "";
    int s=0;
    while(l>=0 || s==1)
    {
        s += getBit(a, l) + getBit(b, l) ;
        result = char(s % 2 + '0') + result;
        s /= 2;
        l--;
    }
    return result;
}

int decBinary(string num)
{
    int output = 0, base = 1;
    for(int i = 0; i < num.size(); i++)
    {
        if(num[i] != "0")
            output += base;
        base *= 2;
    }
    return output;
}

int main()

{
    long long int num1, num2;
    cin >> num1;
    num2 = num1*10000;
    string number1 = to_string(num1);
    string number2 = to_string(num2);
    //cout << number1 << " " << number2 << endl;
    cout << addBinary(number1, number2) << endl;
    //cout << decBinary(addBinary(number1, number2)) << endl;
}
