#include <iostream>

#define MAXN 50001
#define MAXQ 50000
#define MAXT 100001

using namespace std;

int main()

{
    int N, Q, notes[MAXN], note_starts[MAXN], queries[MAXQ], time = 0;
    cin >> N >> Q;
    for(int i = 1; i <= N; i++)
        cin >> notes[i];
    for(int i = 0; i < Q; i++)
        cin >> queries[i];
    //cout << endl;
    for(int i = 1; i <= N; i++)
    {
        note_starts[i] = time;
        time += notes[i];
        //cout << note_starts[i] << endl;
    }
    note_starts[N+1] = note_starts[N]+notes[N];
    /*for(int i = 1; i <= N+1; i++)
        cout << note_starts[i] << endl;
    cout << endl;*/
    for(int i = 0; i < Q; i++)
    {
        //cout << i << endl;
        for(int j = 1; j <= N; j++)
        {
            if(queries[i] >= note_starts[j] && queries[i] < note_starts[j+1])
            {
                cout << j << endl;
                break;
            }
        }
    }
}
