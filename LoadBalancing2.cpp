#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct location
{
    int x, y;
};

bool x_sort(location num1, location num2)
{
    return num1.x <= num2.x;
}

bool y_sort(location num1, location num2)
{
    return num1.y <= num2.y;
}

int max_number(int num1, int num2, int num3, int num4)
{
    int temp[] = {num1, num2, num3, num4};
    sort(temp, temp+4);
    return temp[3];
}

int main()

{
    int cows, temp;
    location locations[MAXN];
    cin >> cows >> temp;
    for(int i = 0; i < cows; i++)
        cin >> locations[i].x
            >> locations[i].y;
    sort(locations, locations+cows, x_sort);
    if(cows %2 == 0)
    {
        int x_line = locations[cows/2-1].x+1;
        sort(locations, locations+cows, y_sort);
        int y_line = locations[cows/2-1].y+1;
        int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
        for(int i = 0; i < cows; i++)
        {
            if(locations[i].x < x_line && locations[i].y < y_line)
                temp1++;
            else if(locations[i].x < x_line && locations[i].y > y_line)
                temp2++;
            else if(locations[i].x > x_line && locations[i].y < y_line)
                temp3++;
            else
                temp4++;
        }
        cout << max_number(temp, temp2, temp3, temp4) << endl;
    }
}
