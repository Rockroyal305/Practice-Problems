#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int main()

{
    int a[3], temp, A, B, C;
    char order[3];
    cin >> a[0];
    cin >> a[1];
    cin >> a[2];
    //cout << "1st: " << a[0] << ", 2nd: " << a[1] << ", 3rd: " << a[2] << endl;
    cin >> order[0];
    cin >> order[1];
    cin >> order[2];
    for(int b = 1; b < 3; b++)
	{
		for(int j = 0; j < (3 - b); j++)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
	}
	//cout << "1st: " << a[0] << ", 2nd: " << a[1] << ", 3rd: " << a[2] << endl;
	A = a[0];
	B = a[1];
	C = a[2];
	//cout << "A: " << A << ", B: " << B << ", C:" << C << endl;
	for(int i = 0; i < 3; i++)
	{
	    if(order[i] == 'A')
	    {
	        cout << A << " ";
	    }
	    else if(order[i] == 'B')
	    {
	        cout << B << " ";
	    }
	    else if(order[i] == 'C')
	    {
	        cout << C << " ";
	    }
	    else
        {

        }
	}
}
