/*
ID: rockroy1
TASK: friday
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()

{
    ofstream fout ("friday.out");
    ifstream fin ("friday.in");

    int day = 1;
    int years;
    //                     Su Mo Tu We Th Fr Sa
    int occurrences [7] = {0, 0, 0, 0, 0, 0, 0};
    fin >> years;
    //cout << years << endl;

    for(int i = 0; i < years; i++)
    {
            if(((i + 1900) % 4 == 0 && (i + 1900) % 100 != 0) || (i + 1900) % 400 == 0)
            {
                occurrences[(day + 12) % 7] = occurrences[(day + 12) % 7] + 1;
                occurrences[(day + 12 + 31) % 7] = occurrences[(day + 12 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 29) % 7] = occurrences[(day + 12 + 31 + 29) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31) % 7] = occurrences[(day + 12 + 31 + 29 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) % 7] + 1;
                day = (day + 2) % 7;
            }
            else
            {
                occurrences[(day + 12) % 7] = occurrences[(day + 12) % 7] + 1;
                occurrences[(day + 12 + 31) % 7] = occurrences[(day + 12 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 28) % 7] = occurrences[(day + 12 + 31 + 28) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31) % 7] = occurrences[(day + 12 + 31 + 28 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31) % 7] + 1;
                occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) % 7] = occurrences[(day + 12 + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30) % 7] + 1;
                day = (day + 1) % 7;
            }
    }
    /*cout << "Saturdays: " << occurrences[6]  << '\n';
    cout << "Sundays: " << occurrences[0]  << '\n';
    cout << "Mondays: " << occurrences[1]  << '\n';
    cout << "Tuesdays: " << occurrences[2]  << '\n';
    cout << "Wednesdays: " << occurrences[3]  << '\n';
    cout << "Thursdays: " << occurrences[4]  << '\n';
    cout << "Fridays: " << occurrences[5]  << '\n';*/
    fout << occurrences[6]  << ' ';
    fout << occurrences[0]  << ' ';
    fout << occurrences[1]  << ' ';
    fout << occurrences[2]  << ' ';
    fout << occurrences[3]  << ' ';
    fout << occurrences[4]  << ' ';
    fout << occurrences[5]  << '\n';
}
