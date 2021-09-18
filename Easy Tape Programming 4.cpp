#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <memory.h>
#include <algorithm>
using namespace std;
int a[11];
int main()
{
    int n,m,p,q,dp,cp;
    string s;
    string ss;
    while (cin>>n>>m)
    {

        cin>>s;
        for (int i=1; i<=m; i++)
        {
            cin>>p>>q;
             memset(a,0,sizeof a);
            string ss=s.substr(p-1,q-p+1);
            int cp=0;
            int l=ss.length();
            dp=1;
            bool fs;
            while (cp>=0 && cp<ss.length())
            {
                fs=false;
                if (ss[cp]>='0' && ss[cp]<='9')
                {
                    a[ss[cp]-'0']++;
                    ss[cp]--;
                    if (ss[cp]<'0')
                    {
                        ss.erase(cp,1);
                        if (dp==-1) cp--;
                        fs=true;
                    }
                }
                else if (ss[cp]=='>')
                        {
                            dp=1;
                            if (cp+1<ss.length())
                             if (ss[cp+1]=='>' || ss[cp+1]=='<')
                             {
                              ss.erase(cp,1);
                              if (dp==-1) cp--;
                              fs=true;
                             }
                        }
                else if (ss[cp]=='<')
                {
                    dp=-1;
                    if (cp-1>=0)
                     if (ss[cp-1]=='>' || ss[cp-1]=='<')
                     {
                         ss.erase(cp,1);
                         if (dp==-1) cp--;
                         fs=true;
                     }
                }
                if (!fs) cp=cp+dp;
            }
            for (int i=0; i<=8; i++)
             cout<<a[i]<<" ";
             cout<<a[9]<<endl;
        }

    }
    return 0;
}
