#include <iostream>

using namespace std;

string reverse(string word)
{
    string output = "";
    for(int i = word.size()-1; i >= 0; i--)
        output += word[i];
    return output;
}

string remove_spaces(string substr_)
{
    string output = "";
    for(int i = 0; i < substr_.size(); i++)
    {
        if(substr_[i] != ' ')
            output += substr_[i];
    }
    return output;
}

string min_string(string str1, string str2)
{
    for(int i = 0; i < min(str1.size(), str2.size()); i++)
    {
        if(str1[i] != str2[i])
        {
            int one = str1[i]-'0', two = str2[i]-'0';
            //cout << one << " " << two << endl;
            if(one < two)
                return str1;
            return str2;
        }
    }
}

int main()

{
    string word, min_word = "z";
    cin >> word;
    for(int i = 1; i < word.size()-1; i++)
    {
        for(int j = i+1; j < word.size(); j++)
        {
            string substr1,
                   substr2,
                   substr3;
            for(int k = 0; k < i; k++)
                substr1 += word[k];
            for(int l = i; l < j; l++)
                substr2 += word[l];
            for(int m = j; m < word.size(); m++)
                substr3 += word[m];
            //cout << substr1 << "|" << substr2 << "|" << substr3 << endl;
            substr3 = remove_spaces(substr3);
            substr1 = reverse(substr1);
            substr2 = reverse(substr2);
            substr3 = reverse(substr3);
            string combined_word = substr1 + substr2 + substr3;
            //cout << (combined_word < min_word) << endl;
            min_word = min_string(min_word, combined_word);
            //cout << combined_word << endl;
        }
    }
    cout << min_word << endl;
}
