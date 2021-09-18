#include <iostream>

#define MAXN 101
//#define MAXK 100000000

using namespace std;

int main()

{
    int N, K, numbers[MAXN], left_bound1, right_bound1, left_bound2, right_bound2;
    cin >> N >> K;
    cin >> left_bound1 >> right_bound1 >> left_bound2 >> right_bound2;
    for(int i = 1; i <= N; i++)
        numbers[i] = i;
    /*for(int i = 1; i <= N; i++)
        cout << numbers[i] << endl;
    cout << endl;*/
    for(int i = 0; i < K; i++)
    {
        for(int j = 0; j <= (right_bound1-left_bound1)/2; j++)
        {
            int temp = numbers[right_bound1-j];
            numbers[right_bound1-j] = numbers[left_bound1+j];
            numbers[left_bound1+j] = temp;
        }
        for(int j = 0; j <= (right_bound2-left_bound2)/2; j++)
        {
            int temp = numbers[right_bound2-j];
            numbers[right_bound2-j] = numbers[left_bound2+j];
            numbers[left_bound2+j] = temp;
        }
    }
    for(int i = 1; i <= N; i++)
        cout << numbers[i] << endl;
}
