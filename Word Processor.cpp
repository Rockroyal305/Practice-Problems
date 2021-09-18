#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main()

{
    int characters_per_line, number_of_words, characters_on_line = 0;
    string word[100];
    cin  >> number_of_words;
    cin >> characters_per_line;
    //cout << characters_per_line << endl;
    for(int i = 0; i < number_of_words; i++)
    {
        cin >> word[i];
        //cout << word[i] << endl;
    }
    for(int i = 0; i < number_of_words; i++)
    {
        //cout << "I: " << i << " ";
        //cout << "New Length: " << characters_on_line + word[i].length() << " ";
        if(characters_on_line + word[i].length() > characters_per_line)
        {
            if(i != 0)
            {
                characters_on_line = 0;
                cout << endl;
            }
        }
        cout << word[i] << " ";
        characters_on_line += word[i].length();
    }
}
