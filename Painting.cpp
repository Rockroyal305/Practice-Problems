#include <iostream>
#include <fstream>

using namespace std;

int main()

{
    ifstream fin("paint.in");
    ofstream fout("paint.out");
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    //cin >> a >> b >> c >> d;
    fin.close();
    int amountPainted = 0;
    for(int i = 0; i < 100; i++)
    {
        if(i >= a && i+1 <= b)
        {
            amountPainted++;
        }
        else if(i >= c && i+1 <= d)
        {
            amountPainted++;
        }
    }
    fout << amountPainted << endl;
}
