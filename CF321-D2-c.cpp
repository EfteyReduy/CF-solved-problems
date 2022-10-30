#include<bits/stdc++.h>


using namespace std;
vector<int>g[100001];
bool vis[100001];
int arr[100001];
int n, m;
void dfs(int node, int w)
{
    if(vis[node])
        return;
    vis[node]=1;
    if(arr[node])
        w++;
    else
    {
        w=0;
    }
    if(w>m)
    {
        vis[node]=0;
        return ;
    }

    for(auto i:g[node])
    {
        dfs(i, w);
    }
}


main()
{

    cin>>n>>m;

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin>>a>>b;

        g[a].push_back(b);
        g[b].push_back(a);

    }
    int ans=0;
    int a=0;
    if(arr[1])
        a=0;
    dfs(1, a);
    for(int i=2; i<=n; i++)
    {
        if(vis[i])
        {
            //cout<<"here"<<endl;
            if(g[i].size()==1)
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;


}
