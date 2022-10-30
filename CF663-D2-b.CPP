#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x, y, a, b;
        cin>>x>>y;

        char str[x][y];

        for(int i=0; i<x; i++)
        {
            for(int j=0; j<y; j++)
            {
                cin>>str[i][j];
                if(str[i][j]=='C')
                {
                    a=i;
                    b=j;
                }
            }
        }
        int ans=0;
        for(int i=0; i<a; i++)
        {
            if(str[i][b]=='R')
            {
                ans++;
            }
            //cout<<str[i][b]<<endl;
        }
        ////return 0;
        for(int i=0; i<b; i++)
        {
            if(str[a][i]=='D')
            {
                ans++;
            }
        }

        cout<<ans<<endl;
    }
}
