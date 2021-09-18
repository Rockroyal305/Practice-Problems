/*
ID: rockroy1
TASK: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <io.h>
#include <string.h>

using namespace std;


int main()

{
    ifstream fin1("namenum.in");
    ifstream fin2("dict.txt");
    ofstream fout("namenum.out");
    string dictionary[4617];
    int64_t possiblenames[4617][2];
    int k = 0;
    bool anynamescorrect = false;
    for(int i = 0; i < 4617; i++)
    {
        possiblenames[i][0] = 0;
    }
    int64_t input_number;
    fin1 >> input_number;
    int input_length = ceil(log10(input_number));
    int dictionary_length;
    //cout << input_number << endl;
    for(int i = 0; i < 4617; i++)
    {
        fin2 >> dictionary[i];
        // << dictionary[i] << endl;
    }
    for(int i = 0; i < 4617; i++)
    {
        dictionary_length = (dictionary[i]).length();
        if(input_length == dictionary_length)
        {
            //cout << dictionary[i] << endl;
            //cout << input_number << endl;
            possiblenames[i][1] = i;
            for(int j = 0; j < dictionary_length; j++)
            {
                //cout << (dictionary[i])[j] << endl;
                if((dictionary[i])[j] == 'A' ||(dictionary[i])[j] == 'B' ||(dictionary[i])[j] == 'C')
                {
                    //cout << "+2:" << dictionary[i] << " " << possiblenames[i][0] << " " << (2*10^(dictionary_length - j - 1 )) <<endl;
                    possiblenames[i][0] += 2 * ::pow(10, (dictionary_length - j - 1 ));
                    //cout << possiblenames[i][0] << endl;
                }
                else if((dictionary[i])[j] == 'D' ||(dictionary[i])[j] == 'E' ||(dictionary[i])[j] == 'F')
                {
                    //cout << "+3" << endl;
                    possiblenames[i][0] += 3 * ::pow(10, (dictionary_length - j - 1 ));
                }
                else if((dictionary[i])[j] == 'G' ||(dictionary[i])[j] == 'H' ||(dictionary[i])[j] == 'I')
                {
                    //cout << "+4" << endl;
                    possiblenames[i][0] += 4 * ::pow(10, (dictionary_length - j - 1 ));
                }
                else if((dictionary[i])[j] == 'J' ||(dictionary[i])[j] == 'K' ||(dictionary[i])[j] == 'L')
                {
                    //cout << "Before K: " << possiblenames[i][0] << endl;
                    //cout << "+5" << endl;
                    possiblenames[i][0] += 5 * ::pow(10, (dictionary_length - j - 1 ));
                    //cout << "After K: " << possiblenames[i][0] << endl;
                }
                else if((dictionary[i])[j] == 'M' ||(dictionary[i])[j] == 'N' ||(dictionary[i])[j] == 'O')
                {
                    //cout << "+6" << endl;
                    possiblenames[i][0] += 6 * ::pow(10, (dictionary_length - j - 1 ));
                }
                else if((dictionary[i])[j] == 'P' ||(dictionary[i])[j] == 'R' ||(dictionary[i])[j] == 'S')
                {
                    //cout << "Before R: " << possiblenames[i][0] << endl;
                    //cout << "+7" << endl;
                    possiblenames[i][0] += 7 * ::pow(10, (dictionary_length - j - 1 ));
                    //cout << "After R: " << possiblenames[i][0] << endl;
                }
                else if((dictionary[i])[j] == 'T' ||(dictionary[i])[j] == 'U' ||(dictionary[i])[j] == 'V')
                {
                    //cout << "+8" << endl;
                    possiblenames[i][0] += 8 * ::pow(10, (dictionary_length - j - 1 ));
                }
                else if((dictionary[i])[j] == 'W' ||(dictionary[i])[j] == 'X' ||(dictionary[i])[j] == 'Y')
                {
                    //cout << "+9" << endl;
                    possiblenames[i][0] += 9 * ::pow(10, (dictionary_length - j - 1 ));
                }
                else
                {
                    //cout << "Not Working" << endl;
                }
            }
        }
    }
    /*for(int i = 0; i < 4617; i++)
    {
        if(possiblenames[i][0] != 0)
        {
            k++;
            cout << k << endl;
            cout << possiblenames[i][0];
            cout << " Dictionary Index: " <<  possiblenames[i][1] << endl;
        }
    }*/
    //cout << "Searching" << endl;
    for(int i = 0; i < 4617; i++)
    {
        if(input_number == possiblenames[i][0])
        {
            fout << dictionary[possiblenames[i][1]] << endl;
            anynamescorrect = true;
        }
    }
    //cout << anynamescorrect << endl;
    if(anynamescorrect == false)
    {
        fout << "NONE" << endl;
    }
}
