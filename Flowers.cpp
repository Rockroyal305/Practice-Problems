#include <iostream>

#define MAXF 10001
#define MAXK 100

using namespace std;

struct descriptor
{
    int start, interval;
};

int main()

{
    int F, K, empty = 0;
    descriptor descriptors[MAXK];
    bool flowers[MAXF];
    cin >> F >> K;
    for(int i = 0; i < K; i++)
        cin >> descriptors[i].start >> descriptors[i].interval;
    for(int i = 0; i < 10001; i++)
        flowers[i] = false;
    for(int i = 0; i < K; i++)
    {
        for(int j = descriptors[i].start; j <= F; j += descriptors[i].interval)
            flowers[j] = true;
    }
    for(int i = 1; i <= F; i++)
    {
        if(!flowers[i])
            empty++;
    }
    cout << empty << endl;
}
