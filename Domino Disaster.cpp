#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int columns;
        string first_row;
        cin >> columns >> first_row;
        for(int i = 0; i < columns; i++)
        {
            if(first_row[i] == 'L') first_row[i] = 'L';
            else if (first_row[i] == 'R') first_row[i] = 'R';
            else if(first_row[i] == 'D') first_row[i] = 'U';
            else first_row[i] = 'D';
        }
        cout << first_row << endl;
    }
}
