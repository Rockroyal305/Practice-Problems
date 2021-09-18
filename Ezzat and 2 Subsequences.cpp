#include <iostream>

#define MAXN 100000

using namespace std;

float average(float numbers[], int bound1, int bound2)
{
    float sum = 0;
    for(int i = bound1; i <= bound2; i++)
        sum += numbers[i];
    return sum/(bound2 - bound1 + 1);
}

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int number;
        float numbers[MAXN], max = -1000000000, total = 0;;
        cin >> number;
        for(int i = 0; i < number; i++)
        {
            cin >> numbers[i];
            total += numbers[i];
        }

    }
}
