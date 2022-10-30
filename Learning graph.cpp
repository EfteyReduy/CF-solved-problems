#include<bits/stdc++.h>

#define pb push_back

using namespace std;

vector<int>g[100];
bool vis[100]={0};
int dis[100]={-1};


void dfs(int n, int d)
{
    vis[n]=1;
    dis[n]=d;
    cout<<"Distance from 1 to " <<n<<" is "<<d<<endl;
    for(int i=0; i<g[n].size(); i++ ){
        if(!vis[g[n][i]])
        {

            vis[g[n][i]]=1;
            dfs(g[n][i], d+1);
            //dis[g[n][i]]=d;
        }
    }
}

main()
{
    int n=9, m=8;
    g[1].push_back(2);
    g[1].push_back(3);
    g[2].pb(4);
    g[2].pb(5), g[2].pb(1);
    g[3].pb(7),g[3].pb(8),g[4].pb(2), g[3].pb(6), g[3].pb(1);
    g[5].pb(2), g[7].pb(3), g[8].pb(3), g[6].pb(3), g[8].pb(9), g[9].pb(8);

    dfs(1, 0);

    for(int i=0; i<11; i++)
    {
        cout<<"dis["<<i<<"] = "<<dis[i]<<endl;
    }


}
