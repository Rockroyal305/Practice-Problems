#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct location
{
    int x, y;
};

bool location_sort(location num1, location num2)
{
    if(num1.x != num2.x)
        return num1.x < num2.y;
    return num1.y < num2.y;
}

int max_number(int num1, int num2, int num3, int num4)
{
    int temp[] = {num1, num2, num3, num4};
    sort(temp, temp+4);
    return temp[3];
}

int main()

{
    int cows, temp, max_x = 0, max_y = 0, minM = 75;
    location locations[MAXN];
    cin >> cows >> temp;
    for(int i = 0; i < cows; i++)
    {
        cin >> locations[i].x
            >> locations[i].y;
        max_x = max(max_x, locations[i].x);
        max_y = max(max_y, locations[i].y);
    }
    sort(locations, locations+cows, location_sort);
    //cout << endl;
    for(int x = 0; x <= max_x; x += 2)
    {
        for(int y = 0; y <= max_y; y += 2)
        {
            //x less and y less, x less and y greater
            //x greater and y less, x greater and y greater
            int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
            for(int i = 0; i < cows; i++)
            {
                if(locations[i].x < x && locations[i].y < y)
                    temp1++;
                else if(locations[i].x < x && locations[i].y > y)
                    temp2++;
                else if(locations[i].x > x && locations[i].y < y)
                    temp3++;
                else
                    temp4++;
            }
            //cout << temp1 << " " << temp2 << " " << temp3 << " " << temp4 << endl;
            int M = max_number(temp1, temp2, temp3, temp4);
            minM = min(M, minM);
        }
    }
    cout << minM << endl;
}
