#include <iostream>
#include <algorithm>
#include <fstream>

#define MAXN 4000

using namespace std;

struct bale
{
    int size;
    int location;
};

bool location_sort(bale num1, bale num2)
{
    return num1.location <= num2.location;
}

int main()

{
    //ifstream fin("trapped.in");
    //ofstream fout("trapped.out");
    int number;
    bale haybales[MAXN];
    cin >> number;
    for(int i = 0; i < number; i++)
        cin >> haybales[i].size >> haybales[i].location;
    //fin.close();
    sort(haybales, haybales+number, location_sort);
    int ans = 0;
    for(int i = 0; i < number-1; i++)
    {
        //cout << haybales[i].size << " " << haybales[i].location << endl;
        int areaOfInterval = haybales[i+1].location-haybales[i].location;
        int leftmostBale = i;
        int rightmostBale = i+1;
        while(leftmostBale >= 0 && rightmostBale <= number-1)
        {
            bool broke = false;
            int currDist = haybales[rightmostBale].location - haybales[leftmostBale].location;
            if(currDist > haybales[leftmostBale].size)
            {
                leftmostBale--;
                broke = true;
            }
            if(currDist > haybales[rightmostBale].size)
            {
                rightmostBale++;
                broke = true;
            }
            // Bessie couldn't break through either the left or the right bale, so stop
            if(!broke)
            {
                break;
            }
       }
       // Bessie couldn't break out
       if(leftmostBale >= 0 && rightmostBale <= number-1)
       {
           ans += areaOfInterval;
       }
    }
    cout << ans << endl;
}
