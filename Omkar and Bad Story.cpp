#include <iostream>
#include <vector>

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int n, k = 0, temp;
        vector<int> a;
        bool working = false;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
            //cout << a[i] << endl;
        }
        while(n+k <= 300 && !working)
        {

            working = true;
            for(int i = 0; i < n+k-1; i++)
            {
                for(int j = i+1; j < n+k; j++)
                {
                    bool found = false;
                    for(int l = 0; l < n+k, !found; l++)
                    {
                        if(a[l] == a[j]-a[i] || a[l] == 0-(a[j]-a[i]))
                        {
                            found = true;
                        }
                    }
                    if(!found)
                    {
                        if(a[j]-a[i] > 0)
                            a.push_back(a[j]-a[i]);
                        else
                            a.push_back(0-a[j]-a[i]);
                        k++;
                        working = false;
                    }
                }
            }
        }
        if(working)
        {
            cout << "yes" << endl;
            for(int i = 0; i < n+k; i++)
                cout << a[i] << " ";
            cout << endl;
        }
        else
            cout << "no" << endl;
    }
}
