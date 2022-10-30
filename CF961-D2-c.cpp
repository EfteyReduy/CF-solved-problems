#include<bits/stdc++.h>
using namespace std;

main()
{

    int n;
    cin>>n;
    string s[4][n];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>s[i][j];
        }
    }

    string sta[n], stb[n];
    bool t=false;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(t)
            {
                sta[i][j]+='0';
                stb[i][j]+='1';
            }
            else
            {
                sta[i][j]+='1';
                stb[i][j]+='0';
            }
            t=!t;
        }
    }

}
