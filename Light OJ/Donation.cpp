#include<bits/stdc++.h>

using namespace std;
int par[55];
vector<int>g[55];
int vis[55];

void init()
{
    for(int i=0; i<55; i++)
    {
        par[i]=i;
        g[i].clear();
        vis[i]=0;
    }
}

int find_par(int x)
{
    if(par[x]==x)
    {
        return x;
    }
    return par[x]=find_par(par[x]);
}

void marge_par(int x, int y)
{
    par[find_par(x)]=find_par(y);
}

void dfs(int node)
{
    vis[node]=1;
    for(int i=0; i<g[node].size(); i++)
    {
        if(!vis[g[node][i]])
        {
            dfs(g[node][i]);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        init();
        int n;
        cin>>n;
        int arr[n][n], ans=0;
        vector<pair<int, pair<int, int> > >p;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>arr[i][j];
                ans+=arr[i][j];
                if(arr[i][j]!=0)
                {
                    p.push_back({arr[i][j],{i,j}});
                }
            }
        }
        sort(p.begin(), p.end());

        for(int i=0; i<p.size(); i++)
        {
            pair<int, pair<int, int> >pp=p[i];
            int x=pp.second.first, y=pp.second.second;
            if(find_par(x)==find_par(y))
            {
                //ans+=pp.first;
            }
            else{
                ans-=pp.first;
                marge_par(find_par(x), find_par(y));
                g[x].push_back(y);
                g[y].push_back(x);
            }
        }
        int cou=0;
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
            {
                cou++;
                dfs(i);
            }
            if(cou>1)
                break;
        }
        cout<<"Case "<<cas<<": ";
        if(cou>1)
        {
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}
