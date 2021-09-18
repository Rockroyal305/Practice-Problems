#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

// A recursive binary search function. It returns
// location of x in given array arr[l..r] is present,
// otherwise -1
int binarySearch(int numbers[], int l, int r, int x)
{
	if(r >= l)
    {
        int mid = l + (r - l) / 2;
		// If the element is present at the middle
		// itself
		if (numbers[mid] == x)
			return mid;
		// If element is smaller than mid, then
		// it can only be present in left subarray
		if(numbers[mid] > x)
            return binarySearch(numbers, l, mid - 1, x);
		// Else the element can only be present
		// in right subarray
		return binarySearch(numbers, mid + 1, r, x);
	}
	// We reach here when element is not
	// present in array
	return -1;
}

int main()
{
	int N, Q, numbers[MAXN], queries[MAXN];
    cin >> N >> Q;
    for(int i = 0; i < N; i++)
        cin >> numbers[i];
    for(int i = 0; i < Q; i++)
        cin >> queries[i];
    for(int i = 0; i < Q; i++)
    {
        if(numbers[0] = queries[i])
            cout << 0 << endl;
        else
        {
            int result = binarySearch(numbers, 0, N-1, queries[i]);
            if(result == -1)
                cout << result << endl;
            else
            {
                for(int j = result; j >= 0; j--)
                {
                    if(numbers[j] == queries[i])
                        result--;
                    else
                        break;
                }
                cout << result+1 << endl;
            }
        }
        //cout << result << endl;
    }
}
