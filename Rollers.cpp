#include <iostream>
#include <math.h>

#define MAXR 1080

using namespace std;

struct roller
{
    int x, y, radius;
};

int square(int num)
{
    return num*num;
}

bool are_touching(roller roller1, roller roller2)
{
    if(square(roller1.x-roller2.x)+square(roller1.y-roller2.y) == square(roller1.radius+roller2.radius))
        return true;
    return false;
}

int main()

{
    roller rollers[MAXR];
    int number;
    cin >> number;
    for(int i = 0; i < number; i++)
        cin >> rollers[i].x >> rollers[i].y >> rollers[i].radius;
    for(int i = 0; i < number; i++)
    {
        if(rollers[i].x != 0 || rollers[i].y != 0)
        {
            int touching = 0;
            for(int j = 0; j < number; j++)
            {
                if(j != i)
                {
                    if(are_touching(rollers[i], rollers[j]))
                        touching++;
                }
            }
            if(touching == 1)
            {
                cout << rollers[i].x << " " << rollers[i].y << endl;
                return 0;
            }
        }
    }
}
