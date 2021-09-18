#include <iostream>
using namespace std;

int N, A[100000];

int main()
{
	cin >> N;
	if(N == 1)
    {
        cout << 0 << endl;
        return 0;
    }
	for(int i = 0; i < N; i++)
		cin >> A[i];
	int ans = N-1;
	for(int i = N - 2; i >= 0; i--)
	{
		if(A[i] < A[i+1])
			ans = i;
		else
			break;
	}
	cout << ans << endl;
	return 0;
}
