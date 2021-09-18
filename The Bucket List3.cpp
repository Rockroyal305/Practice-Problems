#include <iostream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct cow
{
    int start, finish, buckets;
};

bool cow_sort(cow cow1, cow cow2)
{
    return cow1.start <= cow2.start;
}

int main()
{
    int number;
    cow cows[MAXN];
    cin >> number;
    for(int i = 0; i < number; i++)
    {
        cin >> cows[i].start >> cows[i].finish >> cows[i].buckets;
    }
    sort(cows, cows+number, cow_sort);
}

