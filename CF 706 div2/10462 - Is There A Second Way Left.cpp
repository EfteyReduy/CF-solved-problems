#include<bits/stdc++.h>

using namespace std;

vector<int>g[100+5];
bool vis[105];
void dfs(int n)
{
    if(vis[n]==1)
    {
        return;
    }
    else{
        vis[n]=1;
    }
    for(auto i:g[n])
    {
        dfs(i);
    }
}


int parent[105];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {

        int n, m;
        cin>>n>>m;
        for(int i=0 ;i<=n; i++)
        {
            parent[i]=i;
            g[i].clear();
            vis[i]=0;
        }
        pair<int, pair<int, int> >p[m];
        map<pair<int, int>, int>mp;
        for(int i=0; i<m; i++)
        {
            int a,b,cost;
            cin>>a>>b>>cost;
            p[i]={cost, {a,b}};
            mp[{a,b}]=1;
            mp[{b,a}]=1;
        }

        for(auto it:mp)
        {
            g[it.first.first].push_back(it.first.second);
        }
        int cou=0;

        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                cou++;
                dfs(i);
            }
            if(cou>1)
            {
                break;
            }
        }
        if(cou>1)
            cout<<"No way"<<endl;
        else if(cou==1)
        {
            if(m+1==n)
            {
                cout<<"No second way"<<endl;
            }
            else{
                sort(p, p+m);

            }
        }
    }
}
