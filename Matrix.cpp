#include <iostream>

#define MAXN 400

using namespace std;

int main()

{
    int size, matrix[MAXN][MAXN], max_beauty = 0;
    cin >> size;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            cin >> matrix[i][j];
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            //upper-left corner is point i, j
            int max_length = min(size-i-1, size-j-1);
            /*cout << endl;
            cout << i+1 << ", " << j+1 << endl;
            cout << "max_length: " << max_length << endl;
            cout << endl;*/
            for(int k = 0; k <= max_length; k++)
            {
                int main_diagonal = 0, other_diagonal = 0;
                for(int d = 0; d <= k; d++)
                {
                    main_diagonal += matrix[i+d][j+d];
                }
                //upper-right corner is point i, j+k
                for(int d = 0; d <= k; d++)
                {
                    other_diagonal += matrix[i+d][j+k-d];
                    //cout << matrix[i+d][j+k-d] << " ";
                }
                //cout << endl;
                //cout << main_diagonal << " " << other_diagonal << endl;
                max_beauty = max(main_diagonal-other_diagonal, max_beauty);
            }
            //cout << i << ", " << j << ": " << matrix[i][j] << endl;
        }
    }
    //cout << endl;
    cout << max_beauty << endl;
}

