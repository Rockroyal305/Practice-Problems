#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <time.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()

{
    int numbers, gears[100], temp;
    cin >> numbers;
    //cout << "Number of Gears: " << numbers << endl;
    for(int i = 0; i < numbers; i++)
    {
        cin >> gears[i];
        //cout << "Gear " << i << ": " << gears[i] << endl;
    }
    for(int i = 1; i < numbers; i++)
    {
        temp = gears[i];
        //cout << temp << endl;
        for(int j = temp + 1; j > 0; j--)
        {
            if(gears[i] % j == 0 && gears[0]/(temp/gears[i]) % j == 0)
            {
                //cout << gears[0] % j << endl;
                gears[i] = gears[i]/j;
                //cout << "Factor: " << j << endl;
                //cout << "New Number: " << gears[i] << endl;
                //cout << "Comparison Gear:" << gears[0]/(temp/gears[i]) << endl;
            }
        }
        //cout << temp/(temp/gears[i]) << endl;
        cout << gears[0]/(temp/gears[i]) << "/" << temp/(temp/gears[i]) << endl;
    }
}
