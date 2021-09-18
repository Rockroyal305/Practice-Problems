#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXN 100000

using namespace std;

struct cow
{
    int location;
    char species;
};

bool location_sort(cow num1, cow num2)
{
    return num1.location <= num2.location;
}

int main()

{
    ifstream fin("fairphoto.in");
    ofstream fout("fairphoto.out");
    int number, g = 0, h = 0, max_photo = 0;
    cow cows[MAXN];
    fin >> number;
    for(int i = 0; i < number; i++)
        fin >> cows[i].location >> cows[i].species;
    fin.close();
    sort(cows, cows+number, location_sort);
    for(int i = 0; i < number; i++)
    {
        if(cows[i].species == 'G')
            g++;
        else
            h++;
    }
    if(g == h)
    {
        fout << cows[number-1].location - cows[0].location << endl;
        return 0;
    }
    for(int i = 0; i < number; i++)
    {
        char species = cows[i].species;
        bool two_species = false;
        int guernsies = 0, holsteins = 0;
        for(int j = i; j < number; j++)
        {
            if(cows[j].species != species)
            {
                two_species = true;
            }
            if(cows[j].species == 'G')
                guernsies++;
            else
                holsteins++;
            //cout << i << " " << j << " Guernsies: " << guernsies << " Holsteins: " << holsteins << " " << cows[j].location - cows[i].location << " " << (two_species && guernsies == holsteins) << endl;
            if(two_species && guernsies == holsteins)
                max_photo = max(max_photo, cows[j].location - cows[i].location);
            else if(!two_species)
                max_photo = max(max_photo, cows[j].location - cows[i].location);
            else
                continue;
        }
    }
    fout << max_photo << endl;
}
