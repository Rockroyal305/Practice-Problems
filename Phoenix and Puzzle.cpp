#include <iostream>
#include <math.h>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++)
    {
        int number, root2, root4;
        cin >> number;
        if(number %2 != 0 || number == 0)
            cout << "NO" << endl;
        else
        {
            root2 = int(sqrt(number/2));
            root4 = int(sqrt(number/4));
            //cout << root2 << " " << root4 << endl;
            if(root2*root2 == number/2 ||
               (root4*root4 == number/4 && number%4 == 0)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}
