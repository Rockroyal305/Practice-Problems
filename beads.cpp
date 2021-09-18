/*
ID: rockroy1
TASK: beads
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()

{
    ifstream fin ("beads.in");
    ofstream fout ("beads.out");
    int beads_of_same_color = 0;
    int bead_number = 0;
    int temp = 0;
    int beads_collected[350];
    char beads[700];
    char bead_1;
    int beadschecked = 1;
    char beadcolor;
    fin >> bead_number;
    int m = 0;
    int n = bead_number;
    bool forwardloop;
    bool backwardloop;
    bool whitecheck;
    for(int i = 0; i < 350; i++)
    {
        beads_collected[i] = 1;
    }
    for(int i = 0; i < bead_number; i++)
    {
        fin >> beads[i];
        //cout << beads[i];
    }
    //cout << endl;
    for(int i = 0; i < bead_number; i++)
    {
        beads[i + bead_number] = beads[i];
    }
    for(int i = 0; i < 350; i++)
    {
        beads_collected[i] = 0;
    }
    /*for(int i = 0; i < bead_number; i++)
    {
        fout << beads[i] << endl;
    }*/
    //Checking if they are all the same color
    bead_1 = beads[0];
    for(int i = 0; i < bead_number; i++)
    {
        if(beads[i] == bead_1)
        {
            beads_of_same_color++;
        }
    }
    if(beads_of_same_color == bead_number)
    {
        fout << bead_number << '\n';
        return 0;
    }
    cout << "Got to loop" << endl;
    //The big brain part
    for(int j = 0; j < bead_number; j++)
    {
        cout << "Got to 2nd loop" << endl;
        beadschecked = 1;
        forwardloop = false;
        backwardloop = false;

        while(forwardloop != true)
        {
            if(beads[j] != 'w' || whitecheck != false)
            {
                if(whitecheck == false)
                {
                    beadcolor = beads[j];
                }
                while((beads[j + beads_collected[j]]  == beadcolor || beads[j + beads_collected[j]] == 'w') && beads_collected[j] < bead_number)
                {
                    beads_collected[j]++;
                }
                forwardloop = true;
            }
            else
            {

                while(beads[j + beadschecked] == 'w')
                {
                    beadschecked ++;
                }
                beadcolor = beads[j + beadschecked];
                //cout << "Whitecheck" << endl;
                whitecheck == true;
            }
        }
        cout << "Got to 3rd loop" << endl;
        beadschecked = 1;
        whitecheck = false;
        while(backwardloop != true)
        {
            if(beads[j - 1] != 'w' || whitecheck != false)
            {
                if(whitecheck == false)
                {
                    beadcolor = beads[j + bead_number - 1];
                }
                while((beads[j + bead_number - 1 - beads_collected[j]]  == beadcolor || beads[j + bead_number - 1 - beads_collected[j]] == 'w') && beads_collected[j] < bead_number)
                {
                    beads_collected[j]++;
                }
                backwardloop = true;
            }
            else
            {
                while(beads[j + bead_number - 1 - beadschecked] == 'w')
                {
                    beadschecked ++;
                }
                beadcolor = beads[j + bead_number - 1 - beadschecked];
                whitecheck == true;
            }
        }
    }
    cout << "Done with big loop" << endl;
    for(int b = 0; b < bead_number - 1; b++)
	{
        if(beads_collected[b] > beads_collected[b + 1])
        {
            temp = beads_collected[b];
            beads_collected[b] = beads_collected[b + 1];
            beads_collected[b + 1] = temp;
        }
	}
	for(int i = 0; i < bead_number; i++)
    {
        cout << beads_collected[i] << endl;
    }
	fout << beads_collected[bead_number - 1] << '\n';
}
