#include<bits/stdc++.h>

using namespace std;


vector<int>g[2501];
bool vis[2501], ans=false;

void dfs(int n, int parent)
{
    vis[n]=1;

    for(auto i:g[n])
    {
        if(!vis[i])
            dfs(i, n);
        else{
            if(i!=parent)
                ans=true;
        }
    }
}

main()
{
    int n, m;
    cin>>m>>n;
    int a=n*m;

    string s[m];

    for(int i=0; i<m; i++)
    {
        cin>>s[i];
    }
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(s[i][j]==s[i][j+1] and j+1<n)
            {
                g[((i*n)+j)].push_back((i*n+(j+1)));
                //g[(i*n+(j+1))].push_back(i*n+j);
            }

            if(s[i][j]==s[i][j-1] and j-1>=0)
            {
                g[((i*n)+j)].push_back((i*n+(j-1)));
                //g[(i*n+(j-1))].push_back(i*n+j);
            }

            if(i+1<m and s[i][j]==s[i+1][j])
            {
                g[((i*n)+j)].push_back(((i+1)*n)+j);
                //g[(((i+1)*n)+j)].push_back((i*n)+j);
            }

            if( i-1>=0 and s[i][j]==s[i-1][j] )
            {
                g[(i*n+j)].push_back((i-1)*n+j);
               // g[((i-1)*n+j)].push_back((i)*n+j);
            }
        }
    }

    for(int i=0; i<n*m; i++)
        vis[i]=0;
    for(int i=0; i<n*m; i++)
    {
        if(!vis[i])
        {
            dfs(i, i);
        }
    }
    if(ans)
        cout<<"Yes"<<endl;
    else{
        cout<<"No"<<endl;
    }



}
