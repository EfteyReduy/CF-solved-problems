#include<bits/stdc++.h>

using namespace std;
bool vis[100001];

    vector<int>g[100001];

void dfs(int node)
{
    vis[node]=1;

    for(auto i:g[node])
    {
        if(vis[i]==0)
            dfs(i);
    }
    return;
}


main()
{
    int n,m;
    cin>>n>>m;

    pair<int, int>e[m];
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        e[i]=make_pair(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans=0;

    for(int i=0; i<=n; i++)
    {
        vis[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
            dfs(i), ans++;
    }
    int x;
    cin>>x;
    for(int i=0; i<x; i++)
    {
        int y;
        cin>>y;
        int a, b;
        a=e[y-1].first, b=e[y-1].second;
        ///incomplete..................................................

    }

}
