#include <iostream>

using namespace std;

int main()

{
    //                             Mo Tu We Th Fr Sa Su
    int years, occurences[8] = {0, 0, 0, 0, 0, 0, 0, 0}, day = 1;
    cin >> years;
    for(int i = 0; i < years; i++)
    {
        if(day >= 3)
            occurences[day-2]++;
        else
            occurences[day+5]++;
        if(day <= 6)
            occurences[day+1]++;
        else
            occurences[day-6]++;
        if(i % 400 == 0 || (i % 4 && i % 100 != 0))
        {
            //leap year
            if(day <= 5)
                occurences[day+2]++;
            else
                occurences[day-5]++;

        }
        else
        {

        }
    }

}
