#include <iostream>

using namespace std;

int main()

{
    int V, A, B, days = 0, height = 0;
    cin >> A >> B >> V;
    //cout << A << " " << B << " " << V << endl;
    while(height <= V)
    {
        days++;
        height += A;
        //cout << height << endl;
        if(height >= V)
        {
            cout << days << endl;
            return 0;
        }
        height -= B;
    }
    cout << days << endl;
    return 0;
}
