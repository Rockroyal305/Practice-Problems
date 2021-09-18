#include <iostream>

#define MAXN 100

using namespace std;

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int number, x, pieces[MAXN], max_index = 0, sum = 0, biggest_piece = 0;
        cin >> number >> x;
        for(int i = 0; i < number; i++)
        {
            cin >> pieces[i];
            if(pieces[i] > pieces[max_index])
                max_index = i;
            biggest_piece = max(biggest_piece, pieces[i]);
            sum += pieces[i];
        }
        //sort(pieces, pieces+number);
        if(number == 1)
        {
            if(pieces[0] == x)
                cout << "NO" << endl;
            else
            {
                cout << "YES" << endl;
                cout << pieces[0] << endl;
            }
        }
        else if(sum < x)
        {
            cout << "YES" << endl;
            for(int i = 0; i < number; i++)
            {
                cout << pieces[i] << " ";
            }
            cout << endl;
        }
        else if(sum == x)
        {
            cout << "NO" << endl;
        }
        else if(biggest_piece > x)
        {
            cout << "YES" << endl;
            swap(pieces[0], pieces[max_index]);
            for(int i = 0; i < number; i++)
            {
                cout << pieces[i] << " ";
            }
            cout << endl;
        }
        else
        {
            int temp_sum = 0;
            for(int i = 0; i < number-1; i++)
            {
                if(temp_sum + pieces[i] == x)
                {
                    swap(pieces[i], pieces[i+1]);
                    break;
                }
                temp_sum += pieces[i];
            }
            cout << "YES" << endl;
            for(int i = 0; i < number; i++)
            {
                cout << pieces[i] << " ";
            }
            cout << endl;
        }
    }
}
