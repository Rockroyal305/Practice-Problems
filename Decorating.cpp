#include <iostream>
#include <fstream>

#define MAXP 100000

using namespace std;

struct path
{
    int start;
    int end;
};

int main()

{
    ifstream fin("decorate.in");
    ofstream fout("decorate.out");
    int pastures, number, maxJ = 0;
    char letters[2] = {'F', 'J'};
    path paths[MAXP];
    fin >> pastures >> number;
    for(int i = 0; i < number; i++)
        fin >> paths[i].start >> paths[i].end;
    fin.close();
    for(int i = 0; i < 2; i++)
    {
        char pasture1 = letters[i];

    }
}
