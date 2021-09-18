#include <iostream>

using namespace std;

int day_index(int number)
{
    if(number >= 8)
    {
        return number%7;
    }
    if(number < 1)
    {
        return 8-number;
    }
}

int main()

{
    //                             Mo Tu We Th Fr Sa Su
    int years, occurences[8] = {0, 0, 0, 0, 0, 0, 0, 0}, day = 1;
    cin >> years;
    for(int i = 1900; i < 1900+years; i++)
    {
        int month_day = day;
        for(int month = 1; month <= 12; month++)
        {
            if(month%2 == 1)
            {

            }
            else if(month != 2)
            {

            }
            else
            {
                if(i % 400 == 0 || (i % 4 && i % 100 != 0))
                {
                    //leap year
                }
            }
        }
    }

}
