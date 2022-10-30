#include<bits/stdc++.h>

using namespace std;


vector<int>g[100002];
vector<int>ans;
bool vis[100002];

bool gvn[100002], des[100002];
void dfs(int node, bool p, bool q)
{
    if(vis[node])
    {
        return;
    }
    vis[node]=1;
    gvn[node]^=p;
    if(gvn[node]!=des[node])
    {
        p^=1;
        ans.push_back(node);
    }
    for(auto it:g[node])
    {
        dfs(it, q, p);
    }
}

int main()
{
    int n, k, x;

    cin>>n;

    for(int i=1; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        cin>>des[i];
    }
    for(int i=1; i<=n; i++)
    {
        cin>>gvn[i];
    }
    dfs(1, 0, 0);
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<endl;
    }
}
