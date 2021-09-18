#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXN 100

using namespace std;

struct production
{
    string cow;
    int output;
};

struct totals
{
    string cow;
    int total_output;
};

bool production_sort(production num1, production num2)
{
    if(num1.cow <= num2.cow)
        return true;
    return false;
}

int main()

{
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    int cows, totals[MAXN], sums = 0;
    string totals_found[MAXN];
    production outputs[MAXN];
    fin >> cows;
    for(int i = 0; i < cows; i++)
        fin >> outputs[i].cow >> outputs[i].output;
    fin.close();
    for(int i = 0; i < cows; i++)
        totals[i] = 0;
    sort(outputs, outputs+cows, production_sort);
    for(int i = 0; i < cows; i++)
    {
        bool cow_total = true;
        for(int j = 0; j < sums; j++)
        {
            if(outputs[i].cow == totals_found[j])
                cow_total = false;
        }
        if(cow_total)
        {
            totals_found[sums] = outputs[i].cow;
            for(int j = i; j < cows; j++)
            {
                if(outputs[j].cow == totals_found[sums])
                    totals[sums] += outputs[j].output;
            }
            sums++;
        }
    }
    //cout << sums << endl;
    for(int i = 0; i< sums; i++)
        cout << totals_found[i] << " " << totals[i] << endl;
}
