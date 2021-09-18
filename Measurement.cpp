#include <iostream>
#include <fstream>
#include <algorithm>

#define MAXN 1000

using namespace std;

struct change
{
    int day;
    string name;
    char sign;
    int value_change;
};

bool change_sort(change change_1, change change_2)
{
    if(change_1.day <= change_2.day)
        return true;
    return false;
}

int name_to_index(string name)
{
    if(name == "Bessie")
        return 0;
    if(name == "Elsie")
        return 1;
    if(name == "Mildred")
        return 2;
}

int char_to_change(char sign, int value_change)
{
    if(sign == '+')
    {
        return value_change;
    }
    return 0-value_change;
}

int greatest(int outputs[])
{
    int temp = 0;
    int index;
    for(int i = 0; i < 3; i++)
    {
        if(outputs[i] > temp)
        {
            temp = outputs[i];
            index = i;
        }
    }
    return index;
}

int main()

{
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    //                        B  E  M
    int number, outputs[3] = {7, 7, 7}, greatest_output, display_changes = 0;
    change output_changes[MAXN];
    fin >> number;
    for(int i = 0; i < number; i++)
    {
        fin >> output_changes[i].day
            >> output_changes[i].name
            >> output_changes[i].sign
            >> output_changes[i].value_change;
    }
    sort(output_changes, output_changes+number, change_sort);
    /*for(int j = 0; j < 3; j++)
        cout << outputs[j] << " " << endl;
    cout << endl;*/
    for(int i = 0; i < number; i++)
    {
        //cout << output_changes[i].day << endl;

        outputs[name_to_index(output_changes[i].name)] +=
        char_to_change(output_changes[i].sign, output_changes[i].value_change);
        /*for(int j = 0; j < 3; j++)
            cout << outputs[j] << " " << endl;*/
        if(i != 0)
        {
            if(greatest_output != greatest(outputs))
            {
                greatest_output = greatest(outputs);
                display_changes++;
                //cout << "Display Change" << endl;
            }
        }
        else
        {
            greatest_output = greatest(outputs);
            display_changes++;
            //cout << "Display Change" << endl;
        }
        //cout << endl;
    }
    fout << display_changes << endl;
}
