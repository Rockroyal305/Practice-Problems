#include <iostream>
#include <vector>

#define MAXN 5000

using namespace std;

int main()

{
    int days, entertaining_days[MAXN], found = 0, ships = 0, visit_period;
    vector <int> already_found;
    cin >> days;
    for(int i = 0; i < days; i++)
    {
        cin >> entertaining_days[i];
        entertaining_days[i]--;
    }
    for(int i = 1; i < days; i++)
    {
        visit_period = entertaining_days[i];
        bool new_ship = true;
        for(int j = 0; j < found; j++)
        {
            if(already_found[j] == visit_period)
                new_ship = false;
        }
        if(new_ship)
        {
            ships++;
            for(int j = i; j < days; j++)
            {
                if(entertaining_days[j]%visit_period == 0)
                {
                    already_found.push_back(entertaining_days[j]);
                    found++;
                }
            }
        }
    }
    cout << ships << endl;
}
