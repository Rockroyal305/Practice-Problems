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

bool totals_sort(totals num1, totals num2)
{
    return num1.total_output <= num2.total_output;
}

int main()

{
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    int cows, sums = 0;
    totals cow_totals[MAXN];
    production outputs[MAXN];
    fin >> cows;
    for(int i = 0; i < cows; i++)
        fin >> outputs[i].cow >> outputs[i].output;
    fin.close();
    for(int i = 0; i < cows; i++)
        cow_totals[i].total_output = 0;
    sort(outputs, outputs+cows, production_sort);
    for(int i = 0; i < cows; i++)
    {
        bool cow_total = true;
        for(int j = 0; j < sums; j++)
        {
            if(outputs[i].cow == cow_totals[j].cow)
                cow_total = false;
        }
        if(cow_total)
        {
            cow_totals[sums].cow = outputs[i].cow;
            for(int j = i; j < cows; j++)
            {
                if(outputs[j].cow == cow_totals[sums].cow)
                    cow_totals[sums].total_output += outputs[j].output;
            }
            sums++;
        }
    }
    /*cout << sums << endl;
    for(int i = 0; i< sums; i++)
        cout << cow_totals[i].cow << " " << cow_totals[i].total_output << endl;*/
    sort(cow_totals, cow_totals+sums, totals_sort);
    /*cout << endl;
    for(int i = 0; i < sums; i++)
    {
        cout << cow_totals[i].cow << " " << cow_totals[i].total_output << endl;
    }*/
    if(sums == 7)
    {
        int min = cow_totals[0].total_output;
        int second_largest;
        for(int i = 0; i < sums; i++)
        {
            if(cow_totals[i].total_output != min)
            {
                second_largest = i;
                break;
            }
        }
        if(second_largest == sums-1)
        {
            fout << cow_totals[second_largest].cow << endl;
        }
        else if(cow_totals[second_largest].total_output == cow_totals[second_largest+1].total_output)
        {
            fout << "Tie" << endl;
        }
        else
        {
            fout << cow_totals[second_largest].cow << endl;
        }
        return 0;
    }
    else
    {
        if(sums == 1)
        {
            fout << cow_totals[0].cow;
        }
        else if(cow_totals[0].total_output == cow_totals[1].total_output)
        {
            fout << "Tie" << endl;
        }
        else
        {
            fout << cow_totals[0].cow << endl;
        }
        return 0;
    }
}
