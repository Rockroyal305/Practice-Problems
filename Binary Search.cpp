#include <iostream>
#include <algorithm>

#define MAXN 100000

using namespace std;

int binary_search_function(int number, int list[], int start, int end)
{
    int index = (start+end)/2;
    /*cout << "Start: " << start << " End: " << end << endl;
    cout << list[index] << endl;*/
    if(list[index] == number)
        return index;
    if(list[index+1] == number)
        return index+1;
    if(list[index-1] == number)
        return index-1;
    if(list[index] < number)
        return binary_search_function(number, list, index, end);
    else
        return binary_search_function(number, list, start, index);
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
        if(binary_search(numbers, numbers+N, queries[i]))
        {
            cout << binary_search_function(queries[i], numbers, 0, N-1) << endl;
        }
        else
            cout << "-1" << endl;
    }
}
