#include <iostream>
#include <fstream>
#include <vector>

#define MAXR 10

using namespace std;

int N, canvas[MAXR][MAXR], candidate_colors = 0;

bool color_appears(int color)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(canvas[i][j] == color)
                return true;
        }
    }
    return false;
}

bool on_top_of(int c1, int c2)
{
    // Find c2's bounding box
    int top = N, bottom = 0, left = N, right = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            if(canvas[i][j] == c2)
            {
                top = min(top, i);
                bottom = max(bottom, i);
                left = min(left, j);
                right = max(right, j);
            }
    // Does c1 fall within it?
    for(int i=top; i<=bottom; i++)
        for(int j=left; j<=right; j++)
            if(canvas[i][j] == c1) return true;
    return false;
}

int main()

{
    char temp;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> temp;
            canvas[i][j] = temp-'0';
        }
    }
    //cout << color_appears(1) << endl;
    for(int i = 1; i <= 9; i++)
    {
        if(color_appears(i))
        {
            bool candidate = true;
            for(int j = 1; j <= 9; j++)
            {
                if(j != i && color_appears(j) && on_top_of(i, j))
                    candidate = false;
            }
            if(candidate)
                candidate_colors++;
        }
    }
    cout << candidate_colors << endl;
}
