/*
ID: rockroy1
TASK: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()

{
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");
    int people_number;
    fin >> people_number;
    string people[10];
    int person_money_to_give[10] = {0,0,0,0,0,0,0,0,0,0};
    int person_money[10] = {0,0,0,0,0,0,0,0,0,0};
    int recipients;
    string giver;
    string people_receiving[10];
    for(int j = 0; j < people_number; j++)
    {
        fin >> people[j];
    }
    for(int i = 0; i < people_number; i++)
    {
        fin >> giver;
        fin >> person_money_to_give[i];
        fin >> recipients;
        if(recipients != 0)
        {
            for(int k = 0; k < people_number; k++)
            {
                if(giver == people[k])
                {
                    person_money[k] = person_money[k] + person_money_to_give[i] % recipients;
                    person_money[k] = person_money[k] - person_money_to_give[i];
                    k = people_number;
                }
            }
            for(int h = 0; h < recipients; h++)
            {
                fin >> people_receiving[h];
            }
        }
        for(int g = 0; g < people_number; g++)
        {
            for(int f = 0; f < people_number; f++)
            {
                if(people_receiving[g] == people[f])
                {
                    person_money[f] = person_money[f] + (person_money_to_give[i] - (person_money_to_give[i] % recipients)) / recipients;
                    //f = recipients;
                }
            }
        }
        for(int l = 0; l < recipients; l++)
            {
                people_receiving[l] = "";
            }
        recipients = 0;
    }
    for(int e = 0; e < people_number; e++)
    {
        fout << people[e] << " " << person_money[e] << '\n';
    }
    return 0;
}
