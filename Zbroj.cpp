#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()

{
    int A, B;
    string num1, num2, temp1 = "", temp2 = "";
    cin >> A >> B;
    num1 = to_string(A);
    num2 = to_string(B);
    for(int i = 0; i < num1.size(); i++)
    {
        if(num1[i] == '6')
            temp1 = temp1 + '5';
        else
            temp1 = temp1 + num1[i];
    }
    for(int i = 0; i < num2.size(); i++)
    {
        if(num2[i] == '6')
            temp2 = temp2 + '5';
        else
            temp2 = temp2 + num2[i];
    }
    //cout << temp1 << " " << temp2 << endl;
    int x, y;
    //cout << x << endl;
    stringstream x_num(temp1);
    x_num >> x;
    stringstream y_num(temp2);
    y_num >> y;
    cout << x+y << " ";
    temp1 = "", temp2 = "";
    for(int i = 0; i < num1.size(); i++)
    {
        if(num1[i] == '5')
            temp1 = temp1 + '6';
        else
            temp1 = temp1 + num1[i];
    }
    for(int i = 0; i < num2.size(); i++)
    {
        if(num2[i] == '5')
            temp2 = temp2 + '6';
        else
            temp2 = temp2 + num2[i];
    }
    stringstream x_num2(temp1);
    x_num2 >> x;
    stringstream y_num2(temp2);
    y_num2 >> y;
    cout << x+y << endl;
}
