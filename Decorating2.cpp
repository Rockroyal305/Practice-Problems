#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <fstream>

using namespace std;

#define MAXN 50010

int color[MAXN];
int colorcount[2];
vector<int> E[MAXN];

bool dfs(int u, int c)
{
    //std::cout << "dfs(u, c)" << u << ":" << c << std::endl;
    if(color[u] != -1) {
      bool b = (color[u] == c);
      //std::cout <<"Returning:" << b << std::endl;
      return b;
    }
    //std::cout << "Coloring:" << u << "with:" << c << std::endl;
    color[u] = c;
    colorcount[c]++;
    for(int i = 0; i < E[u].size(); i++)
    {
        if(!dfs(E[u][i], 1 - c))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream fin("decorate.in");
    ofstream fout("decorate.out");
    int N, M;
    fin >> N >> M;
    //assert(1 <= N && N <= 50000);
    //assert(1 <= M && M <= 100000);
    for(int i = 0; i < M; i++)
    {
        int u, v;
        fin >> u >> v;
        //assert(u != v);
        //assert(1 <= u && u <= N);
        //assert(1 <= v && v <= N);
        u--; v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }

    int ccnt = 0;
    int result = 0;
    memset(color, -1, sizeof(color));
    for(int i = 0; i < N; i++)
    {
        if(color[i] != -1) continue;
        ccnt++;
        colorcount[0] = colorcount[1] = 0;
        if (!dfs(i, 0))
        {
            result = -1;
            break;
        }
        //std::cout << "Result before:" << result << ":" << colorcount[0] << ":" << colorcount[1]
        //          << "Result after:" << (result + max(colorcount[0], colorcount[1])) << std::endl;
        result += max(colorcount[0], colorcount[1]);
    }
    fout << result << endl;
    return 0;
}
