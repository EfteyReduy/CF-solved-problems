#include<bits/stdc++.h>

using namespace std;

main()
{
    int n, m, i, j;
    cin>>n>>m;
    char c, str[n][m];
    cin>>c;
    set<char>ch;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin>>str[i][j];

        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(str[i][j]==c)
            {
                if(i>0&&str[i-1][j]!='.'&&str[i-1][j]!=c)
                    ch.insert(str[i-1][j]);
                if(j>0&&str[i][j-1]!='.'&&str[i][j-1]!=c)
                    ch.insert(str[i][j-1]);
                if(j<m-1&&str[i][j+1]!='.'&&str[i][j+1]!=c)
                    ch.insert(str[i][j+1]);
                if(i<n-1&&str[i+1][j]!='.'&&str[i+1][j]!=c)
                    ch.insert(str[i+1][j]);
            }
        }
    }
    cout<<ch.size()<<endl;




}
