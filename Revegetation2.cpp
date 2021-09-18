#include <iostream>
#include <utility>

#define MAXP 101
#define MAXN 151

using namespace std;

struct cow_pasture
{
    pair<int, int>pastures;
};

int main()

{
    int number, cows, pastures[MAXP];
    cow_pasture cow_pastures[MAXN];
    cin >> number >> cows;
    for(int i = 0; i < cows; i++)
    {
        cin >> cow_pastures[i].pastures.first >> cow_pastures[i].pastures.second;
        if(cow_pastures[i].pastures.first > cow_pastures[i].pastures.second)
            swap(cow_pastures[i].pastures.first, cow_pastures[i].pastures.second);
    }
    for(int i = 1; i <= number; i++)
    {
        int grass;
        for(grass = 1; grass <= 4; grass++)
        {
            bool ok = true;
            for(int j = 0; j < cows; j++)
            {
                if(cow_pastures[j].pastures.second  == i && pastures[cow_pastures[j].pastures.first] == grass) ok = false;
            }
            if(ok) break;
        }
        pastures[i] = grass;
        cout << grass;
    }
    cout << endl;
    return 0;
}
