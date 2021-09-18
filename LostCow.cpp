#include <iostream>
#include <cstdlib>

using namespace std;
typedef long long ll;

int main()
{
    /*ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");*/
    ll x, y;
    cin >> x >> y;

    ll ans = 0;
    ll by = 1;
    ll dir = 1;
    while(true)
    {
        // dir == 1 means Farmer John is moving to the right, and
        // dir == -1 means he is moving to the left.
        if((dir==1 && x<=y && y<=x+by) || (dir==-1 && x-by<=y && y<=x))
        {
            // We found Bessie!
            ans += abs(y-x);
            cout << ans << endl;
            break;
        }
        else
        {
            // Didn't find Bessie! Add to our running total the cost of
            // moving 'by' units away from the start and back again.
            // Then multiply our next move's length by 2 and switch direction.
            ans += by*2;
            by *= 2;
            dir *= -1;
        }
    }
}
