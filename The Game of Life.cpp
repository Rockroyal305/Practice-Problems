#include <iostream>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int number, iterations, dead = 0;
        char cells[1000], new_cells[1000], previous_cells[1000];
        cin >> number >> iterations;
        for(int i = 0; i < number; i++)
        {
            cin >> cells[i];
            if(cells[i] == '0')
                dead++;
            //cout << cells[i];
        }
        //cout << endl;
        //cout << iterations << endl;
        if(dead < number)
        {
            for(int i = 0; i < iterations; i++)
            {

                bool is_previous = true;
                for(int j = 0; j < number; j++)
                    previous_cells[i] = cells[i];
                for(int j = 0; j < number; j++)
                {
                     if(j == 0)
                     {
                         if(cells[j+1] == '1' ||
                            cells[j] == '1')
                            new_cells[j] = '1';
                         else
                            new_cells[j] = '0';
                     }
                     else if(j == number-1)
                     {
                         if(cells[j-1] == '1' ||
                            cells[j] == '1')
                            new_cells[j] = '1';
                        else
                            new_cells[j] = '0';
                     }
                     else
                     {
                        if(cells[j] == '1' ||
                         ((cells[j-1] == '1' && cells[j+1] == '0') ||
                          (cells[j+1] == '1' && cells[j-1] == '0')))
                            new_cells[j] = '1';
                        else
                            new_cells[j] = '0';
                     }
                }
                //bool is_previous  = true;
                /*for(int j = 0; j < number; j++)
                {
                    cells[j] = new_cells[j];
                    cout << cells[j];
                    if(previous_cells[j] != cells[j])
                        is_previous = false;
                }
                cout << endl;*/
                if(is_previous == true)
                    break;
            }
        }
        for(int i = 0; i < number; i++)
        {
            cout << cells[i];
        }
        cout << endl;
    }
}
