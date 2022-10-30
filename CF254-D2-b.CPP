#include<bits/stdc++.h>

using namespace std;


bool vis[100];

vector<int>g[100];
long long ans=1;

void dfs(int n){
    if(vis[n])
        return;

    vis[n]=true;

    for(int i=0; i<g[n].size(); i++)
    {
        if(!vis[g[n][i]])
        {
            ans=ans*2;
            dfs(g[n][i]);
        }
    }
}


int main(){

    int n, m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    long long total=0;

    for(int i=0; i<=n; i++)
    {
        vis[i]=0;
    }

    for(int i=1; i<n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            //total+=ans;
            //ans=1;
        }

    }
    //total=max(ans,total);

    //cout<<total<<endl;
    cout<<ans<<endl;

}

