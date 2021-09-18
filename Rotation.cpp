#include <iostream>

#define MAXN 1000

using namespace std;

struct pulley
{
    int driving, destination, type;
};

int main()

{
    int number, crossed = 0;
    pulley pulleys[MAXN];
    cin >> number;
    for(int i = 0; i < number-1; i++)
    {
        cin >> pulleys[i].driving >> pulleys[i].destination >> pulleys[i].type;
        crossed += pulleys[i].type;
    }
    cout << crossed%2 << endl;
}
