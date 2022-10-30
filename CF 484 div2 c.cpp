#include<bits/stdc++.h>

using namespace std;

int t=0, in[100001], out[100001];
bool vis[100001];
vector<int>g[100001];

void dfs(int a)
{
    if(vis[a])
    {
        return;
    }
    vis[a]=1;
    t++;
    in[a]=t;
    for(auto it:g[a]){
        dfs(it);
    }
    t++;
    out[a]=t;

}

main()
{
    int n;
    cin>>n;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    int cou=0;
    for(int i=1; i<=n; i++)
    {
        if((abs(in[i]-out[i])+1)%4==0)
        {
            cou++;
        }
    }
    if(n%2)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<cou-1<<endl;
    }
}
