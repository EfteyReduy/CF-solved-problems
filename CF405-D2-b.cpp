#include<bits/stdc++.h>

using namespace std;
long long ans=0, cnt=0;
bool vis[150002];
vector<int>g[150001];

void dfs(int node){
    vis[node]=1;
    cnt++;
    ans+=g[node].size();
    for(int i=0; i<g[node].size(); i++)
    {
        if(!vis[g[node][i]])
        {

            dfs(g[node][i]);
        }
    }
}


main()
{

    long long arr[150001];
    arr[0]=0;
    arr[1]=0;
    arr[2]=1;
    for(int i=3; i<=150000; i++)
    {
        arr[i]=arr[i-1]+i-1;
       // cout<<i<<" = "<<arr[i]<<endl;
    }
    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i=0; i<n; i++)vis[i]=0;

    for(int i=1; i<=n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            ans=ans/2;
            if(ans<arr[cnt])
            {
                cout<<"NO"<<endl;
                return 0;
            }
            ans=0, cnt=0;
        }
    }
    cout<<"YES"<<endl;


}
