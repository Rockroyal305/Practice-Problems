#include <fstream>
#include <iostream>

using namespace std;

int x1 = 40000,
        x2 = 40000,
        x3 = 0,
        x4 = 0,
        y1 = 40000,
        y2 = 40000,
        y3 = 0,
        y4 = 0;
		int x [50000];
		int y [50000];

// This function takes in a point and updates the
// two smallest and two largest x and y coordinates.
void update(int x, int y) {
    if(x < x1) {
        x2 = x1;
        x1 = x;
    }
    else if(x < x2) {
        x2 = x;
    }
    if(x > x4) {
        x3 = x4;
        x4 = x;
    }
    else if(x > x3) {
        x3 = x;
    }
    if(y < y1) {
        y2 = y1;
        y1 = y;
    }
    else if(y < y2) {
        y2 = y;
    }
    if(y > y4) {
        y3 = y4;
        y4 = y;
    }
    else if(y > y3) {
        y3 = y;
    }
}

int main()
{
    /*ifstream fin("reduce.in");
    ofstream fout("reduce.out");*/
    int n;
    cin >> n;
    // read in all the locations
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
        update(x[i], y[i]);
    }
    // the original fence has this area
    int ans = (x4-x1) * (y4-y1);
    for(int i = 0; i < n; i++)
    {
        // check for each point if we use the smallest/largest coordinate
        // or the second-smallest/second-largest coordinate
        int xMin = x1;
        if(x[i] == xMin) {
            xMin = x2;
        }
        int xMax = x4;
        if(x[i] == xMax) {
            xMax = x3;
        }
        int yMin = y1;
        if(y[i] == yMin) {
            yMin = y2;
        }
        int yMax = y4;
        if(y[i] == yMax) {
            yMax = y3;
        }
        // check if the new area is smaller
        ans = min(ans, (xMax - xMin) * (yMax - yMin));
    }
    // print the answer
    cout << ans << endl;
}
