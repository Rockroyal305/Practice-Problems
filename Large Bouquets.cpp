#include <iostream>

using namespace std;


int main()

{
    int bouquets, flowers, evens = 0, odds = 0, large_bouquets = 0;
    cin >> bouquets;
    for(int i = 0; i < bouquets; i++)
    {
        cin >> flowers;
        if(flowers%2 == 0)
            evens++;
        else
            odds++;
    }
    //cout << "evens: " << evens << endl;
    //cout << "odds: " << odds << endl;
    while(evens > 0 && odds > 0)
    {
        large_bouquets++;
        evens--;
        odds--;
    }
    if(odds == 0)
        cout << large_bouquets << endl;
    else if(evens == 0)
    {
        while(odds >= 3)
        {
            large_bouquets++;
            odds -= 3;
        }
        cout << large_bouquets << endl;
    }
}
